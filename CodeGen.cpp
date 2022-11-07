#include "CodeGen.hpp"
#include <fstream>

LLVMTypeRef getLLVMType(std::string type_qualifier, LLVMContextRef context) {
    if (type_qualifier == "INT") {
        return LLVMInt32TypeInContext(context);
    } else if (type_qualifier == "FLOAT") {
        return LLVMFloatTypeInContext(context);
    } else if (type_qualifier == "VOID") {
        return LLVMVoidTypeInContext(context);
    } else if (type_qualifier == "CHAR") {
        return LLVMInt8TypeInContext(context);
    } else {
        std::string cmp; 
        cmp += type_qualifier.back();
        if (cmp == "*") { 
            type_qualifier.pop_back();
            LLVMTypeRef base_type = getLLVMType(type_qualifier, context);
            return LLVMPointerType(base_type,0);
        } else {
            return LLVMInt32TypeInContext(context);
        }
        // return NULL;
    }
}

CodeGen::CodeGen() {
    LLVMContextRef globalContext = LLVMGetGlobalContext();
    LLVMBuilderRef globalBuilder = LLVMCreateBuilderInContext(globalContext);

    std::map<std::string, LLVMValueRef> symMap;
	std::map<std::string, LLVMValueRef> argMap;
	std::map<std::string, LLVMValueRef> fMap;

    symbols.push(symMap);
    func_args.push(argMap);
    functions.push(fMap);

    contextStack.push(globalContext);
    builderStack.push(globalBuilder);

    cmodule = LLVMModuleCreateWithNameInContext("cmodule", globalContext);
}

void CodeGen::push_sym() {
    table newsymbols;
    table newarrs;
    symbols.push(newsymbols);
    arrays.push(newarrs);
}

void CodeGen::pop_sym() {
    symbols.pop();
    arrays.pop();
}

LLVMValueRef CodeGen::getVar(std::string vname) {
    if (symbols.empty()) {
        return NULL;
    } 

    table top = symbols.top();
    if (top.find(vname) != top.end()) {
        return top[vname];
    } else {
        symbols.pop();
        LLVMValueRef var = getVar(vname);
        symbols.push(top);
        return var;
    }
}

LLVMValueRef CodeGen::getFunc(std::string fname) {
    if (functions.empty()) {
        return NULL;
    } 

    table top = functions.top();
    if (top.find(fname) != top.end()) {
        return top[fname];
    } else {
        functions.pop();
        LLVMValueRef func = getFunc(fname);
        functions.push(top);
        return func;
    }
}

LLVMValueRef CodeGen::getFArg(std::string vname) {
    table fargs = func_args.top();

    if (fargs.find(vname) != fargs.end()) {
        return fargs[vname];
    } 

    return NULL;
}

LLVMValueRef CodeGen::getArr(std::string arr) {
    if (arrays.empty()) {
        return NULL;
    } 

    table top = arrays.top();
    if (top.find(arr) != top.end()) {
        return top[arr];
    } else {
        arrays.pop();
        LLVMValueRef array = getArr(arr);
        arrays.push(top);
        return array;
    }

    // table arrs = arrays.top();

    // if (arrs.find(arr) != arrs.end()) {
    //     return arrs[arr];
    // }
     
    // return NULL;
}

LLVMValueRef CodeGen::getNodeValue(ASTNode* node, LLVMValueRef mem) {
    // mem: If the node is of type ID
    // Memory represents the memory location to load from
    // Else it represents the actual value of the node
    // We will return accordingly 

    ASTNode::ntype node_type = node->node_type;

    if (node_type != ASTNode::ID && node_type != ASTNode::ARRELEM) {
        return mem;
    } 

    std::string id = node->repr;

    if (node_type != ASTNode::ARRELEM) {
        LLVMValueRef array = getArr(id);
        LLVMValueRef base_ptr = NULL;
        LLVMValueRef e_ptr = NULL;

        if (array != NULL) { 
            std::string tag = "arr_" + id;
            LLVMValueRef idx = {LLVMConstInt(LLVMInt32TypeInContext(contextStack.top()), 0, false)};
            base_ptr = LLVMBuildStructGEP(builderStack.top(), array, 0, "_arr_base_ptr");
            e_ptr = LLVMBuildGEP(builderStack.top(), base_ptr, &idx, 1, "_arr_first_ptr");
            return e_ptr;
        }
    }

    std::string load = "ld_" + id;
    LLVMValueRef ld = LLVMBuildLoad(builderStack.top(), mem, load.c_str());
    return ld;
            
}

/* Main Code Generator Function  for Function Decl, Var Decl and Expressions */

LLVMValueRef CodeGen::codegen(ASTNode* node, bool local, LLVMTypeRef rettype = NULL) {
    // Get Context and Builder for current node
    LLVMContextRef context = contextStack.top();
    LLVMBuilderRef builder = builderStack.top();

    // Get type of AST Node 
    ASTNode::ntype node_type = node->node_type;

    // Switch based on the type of the node 
    switch(node_type) {

        /******************/
        /* FUNCTION NODES */
        /******************/

        case(ASTNode::TRANSLATION_UNIT):
        {
            int nitems = node->nchildren;

            for(int i = 0; i < nitems; i++) {
                codegen(node->children[i], false);
            }

            return NULL;
        }

        case (ASTNode::FUNC):
            {
                bool isvoid = false;;
                if (node->children[0]->repr == "VOID") {
                    isvoid = true;
                }
                LLVMTypeRef fret = getLLVMType(node->children[0]->repr, context);
                const char* fname = (node->children[1]->children[0])->repr.c_str();
            
                table syms;
                table p_arrs;
                int nargs = 0;

                /* FUNCTION DECLARATION */

                LLVMValueRef fDecl;
                // Check if the function has already been declared 
                table ftable = functions.top();
                if (ftable.find(fname) != ftable.end()) {
                    return ftable[fname];
                }

                // Check if the function has no parameters
                if (node->children[1]->children.size() == 1) {
                    // LLVMTypeRef param_types[] = {};
                    LLVMTypeRef fType = LLVMFunctionType(fret, {}, 0, 0);
                    fDecl = LLVMAddFunction(cmodule, fname, fType);
                    unsigned int ct = LLVMCountParams(fDecl);
                    functions.top()[fname] = fDecl;
                }
                else {
                     // If the function does have parameters 
                    nargs = node->children[1]->nchildren;
                    std::vector<LLVMTypeRef> fparams;

                    // LLVMTypeRef param_types[nargs];
                    for(int i = 1; i < nargs; i++) {
                        ASTNode* temp = node->children[1]->children[i];
                        if (temp->children[1]->node_type == ASTNode::ARRAY){
                            fparams.push_back(getLLVMType(temp->children[0]->repr + "*", context));
                        } else {
                            fparams.push_back(getLLVMType(temp->children[0]->repr, context));
                        }
                    }
                    
                    LLVMTypeRef* param_types = fparams.data();
                    LLVMTypeRef fType = LLVMFunctionType(fret, param_types, nargs-1, 0);

                    fDecl = LLVMAddFunction(cmodule, fname, fType);

                    functions.top()[fname] = fDecl;    
                }
                LLVMBasicBlockRef fentry = LLVMAppendBasicBlock(fDecl, "entry");
                LLVMPositionBuilderAtEnd(builder, fentry);

                // Add variables to Symbol Table
                for(int i = 1; i < nargs; i++) {
                    ASTNode* temp = node->children[1]->children[i];
                    std::string id;
                    if (temp->children[1]->node_type == ASTNode::ARRAY){
                        id = temp->children[1]->children[0]->repr;
                        std::string arrtype = temp->children[0]->repr + "*";
                        // std::cout << arrtype << std::endl;
                        LLVMValueRef p = LLVMBuildAlloca(builder, getLLVMType(arrtype,context), id.c_str());
                        LLVMBuildStore(builder,LLVMGetParam(fDecl,i-1),p);
                        syms[id] = p;
                        // std::cout << p << std::endl;
                    } else {
                        id = temp->children[1]->repr;
                        LLVMValueRef p = LLVMBuildAlloca(builder, getLLVMType(temp->children[0]->repr,context), id.c_str());
                        LLVMBuildStore(builder,LLVMGetParam(fDecl,i-1),p);
                        syms[id] = p;
                    }
                    // LLVMValueRef p = LLVMGetParam(fDecl,i-1);
                }

                /* Generate Code for Function Block */
                
                push_sym();
                func_args.push(syms);

                ASTNode* fblock = node->children[2];

                // Function Block CodeGen
                codegenBlock(fblock, builder, fret);
                pop_sym();
                func_args.pop();

                if (isvoid) {
                    LLVMBuildRetVoid(builder);
                }
                return NULL;
                // break;
            }

        
        
        /***********************/
        /*     IDENTIFIER      */
        /**********************/

        case(ASTNode::ID):
        {
            // Get ID of the variable 
            std::string vname = node->repr;
            
            // Check in the Symbol Table
            LLVMValueRef id = getVar(vname);
            
            if (id != NULL) {
                return id;
            } 

            // Check if a function argument
            id = getFArg(vname);
            if (id != NULL) {
                return id;
            } 

            // Check if array element 
            id = getArr(vname);
            if (id != NULL) {
                return id;
            }

            std::cout << "ERROR, NOT FOUND!" << std::endl;
            break;
        
        }

        case(ASTNode::ARRELEM):
        {
            std::string arrname = node->repr;
            
            // generate code for index

            LLVMValueRef idx = codegen(node->children[0]->children[0],local);
            idx = getNodeValue(node->children[0]->children[0], idx);
            int ind = node->children[0]->children[0]->ival;

            // get the tag
            std::string tag = arrname + "_" + std::to_string(ind) + "_";

            // Check if access made from a pointer variable or an array variable
            LLVMValueRef array = getArr(arrname);
            LLVMValueRef base_ptr = NULL;
            LLVMValueRef elem_ptr = NULL;

            if (array != NULL) { 
                base_ptr = LLVMBuildStructGEP(builder, array, 0, "_load_ptr_val");
                elem_ptr = LLVMBuildInBoundsGEP(builder, base_ptr, &idx, 1, tag.c_str());
                return elem_ptr;
            } else {
                array = getFArg(arrname);
                array = getNodeValue(node, array);
                elem_ptr = LLVMBuildGEP(builder, array, &idx, 1, tag.c_str()); 
                return elem_ptr;
            }
            
        }

        case(ASTNode::FUNCALL):
        {
            // Check if a function call
            std::string fname = node->children[0]->repr;
            LLVMValueRef id = getFunc(fname);
            if (id != NULL) {
                // Is a function call 
                if (node->nchildren == 0) {
                    LLVMValueRef* args;
                    std::string fn = fname + "()";
                    return LLVMBuildCall(builder, id, args, 0, fn.c_str());
                } else {
                    std::vector<LLVMValueRef> fn_args;
                    std::string fn = fname + "()";
                    
                    for(int i = 1; i < node->nchildren; i++) {
                        LLVMValueRef arg = codegen(node->children[i],local);
                        // TODO: Get value
                        LLVMValueRef arg_val = getNodeValue(node->children[i],arg);
                        fn_args.push_back(arg_val);
                    }

                    LLVMValueRef* args = fn_args.data();
                    unsigned int nargs = fn_args.size();

                    return LLVMBuildCall(builder, id, args, nargs, fn.c_str());

                }
            }
        }

        /***********************/
        /* DECLARATION NODES  */
        /**********************/
        
        case (ASTNode::VARDEC): 
        {
            // Get Type of the Variable
            LLVMTypeRef vtype = getLLVMType(node->children[0]->repr,context);
            
            if (node->children[1]->node_type != ASTNode::FUNCDEF) {
                int ndecl = node->nchildren;
                for(int i = 1; i<ndecl; i++) {
                    if (node->children[i]->node_type == ASTNode::ASSIGNEXP) {
                        // Defined along with declaration
                        if (node->children[i]->children[0]->node_type == ASTNode::ARRAY) {
                            arrDecl(node->children[i]->children[0],vtype,local);
                        } else {
                            varDecl(node->children[i]->children[0],vtype,local);
                        }
                        // Logic for Assignment
                        codegen(node->children[i],local);
                    }
                    else {
                        if (node->children[i]->node_type == ASTNode::ARRAY) {
                            arrDecl(node->children[i],vtype,local);
                        } else {
                            varDecl(node->children[i],vtype,local);
                        }
                        
                    }
                }
                return NULL;
                break;
            } else {

                LLVMTypeRef fret = getLLVMType(node->children[0]->repr, context);
                const char* fname = (node->children[1]->children[0])->repr.c_str();
            
                table syms;
                int nargs = 0;

                /* FUNCTION DECLARATION */

                LLVMValueRef fDecl;
                // Check if the function has already been declared 
                table ftable = functions.top();
                if (ftable.find(fname) != ftable.end()) {
                    return ftable[fname];
                }


                // Check if the function has no parameters
                if (node->children[1]->children.size() == 1) {
                    // LLVMTypeRef param_types[] = {};
                    LLVMTypeRef fType = LLVMFunctionType(fret, {}, 0, 0);
                    fDecl = LLVMAddFunction(cmodule, fname, fType);
                    unsigned int ct = LLVMCountParams(fDecl);
                    functions.top()[fname] = fDecl;
                }
                else {
                     // If the function does have parameters 
                    nargs = node->children[1]->nchildren;
                    std::vector<LLVMTypeRef> fparams;

                    int isVariadic = 0;
                    // LLVMTypeRef param_types[nargs];
                    for(int i = 1; i < nargs; i++) {
                        ASTNode* temp = node->children[1]->children[i];
                        if (temp->repr == "...") {
                            nargs = i;
                            isVariadic = 1;
                            break;
                        }
                        fparams.push_back(getLLVMType(temp->children[0]->repr, context));
                    }
                    
                    LLVMTypeRef* param_types = fparams.data();
                    LLVMTypeRef fType = LLVMFunctionType(fret, param_types, nargs-1, isVariadic);

                    fDecl = LLVMAddFunction(cmodule, fname, fType);
                    functions.top()[fname] = fDecl;    
                }
                return NULL;

            }
        }

        case (ASTNode::ASSIGNEXP):
        {
            if (node->children[0]->node_type != ASTNode::ARRAY) {
                std::string vname = node->children[0]->repr;
                // Search in table: decl before use 
                // Once found assign new value using BuildStore

                LLVMValueRef mem = codegen(node->children[0], local);
                LLVMValueRef assignexp = codegen(node->children[2], local);
                LLVMValueRef assignval = getNodeValue(node->children[2], assignexp);
                return LLVMBuildStore(builder, assignval, mem); 
            } else {
                ASTNode* arrnode = node->children[0];
                for(int i = 0; i < arrnode->children[1]->ival; i++) {
                    ASTNode* assign = new ASTNode(ASTNode::ASSIGNEXP, "ASSIGN");
                    ASTNode* left = new ASTNode(ASTNode::ARRELEM, arrnode->children[0]->repr);
                    ASTNode* tmp = new ASTNode(ASTNode::EXPRESSION, "INDEX");
                    tmp->addChild(new ASTNode(ASTNode::ICONST, i));
                    left->addChild(tmp);
                    assign->addChild(left);
                    assign->addChild(new ASTNode(ASTNode::ASSIGNEXP, "="));
                    ASTNode* right;
                    if (node->children[2]->children[i]->node_type == ASTNode::ICONST) {
                        right = new ASTNode(ASTNode::ICONST, node->children[2]->children[i]->ival);
                    } else {
                        right = new ASTNode(ASTNode::FCONST, node->children[2]->children[i]->fval);
                    }
                    assign->addChild(right);
                    // assign->printAST();
                    codegen(assign, local);
                }

                return NULL;
                
            }
            
        }

        case(ASTNode::ICONST):
        {
            return LLVMConstInt(LLVMInt32TypeInContext(context), node->ival, false);
        }

        case(ASTNode::FCONST):
        {
            LLVMConstReal(LLVMFloatTypeInContext(contextStack.top()), node->fval);
        }

        case(ASTNode::SCONST):
        {
            return LLVMBuildGlobalStringPtr(builder, node->repr.c_str(), "const_string");
        }

        case(ASTNode::LABEL):
        {
            LLVMBasicBlockRef currBlock = LLVMGetInsertBlock(builder);
            LLVMValueRef func = LLVMGetBasicBlockParent(currBlock);
            LLVMBasicBlockRef labBlock = LLVMAppendBasicBlock(func, node->repr.c_str());
            LLVMBuildBr(builder, labBlock);
            LLVMPositionBuilderAtEnd(builder, labBlock); 
            labels.push_back(labBlock);
            codegen(node->children[0], local);
            return NULL;
        }

        /***********************/
        /*    EXPRESSIONS     */
        /**********************/

        case(ASTNode::BINEXP):
        {
            std::string op = node->repr;
            LLVMValueRef lvalue = codegen(node->children[0],local);
            lvalue = getNodeValue(node->children[0], lvalue);
            LLVMValueRef rvalue = codegen(node->children[1],local);
            rvalue = getNodeValue(node->children[1], rvalue);
            LLVMOpcode opcode;
            bool logic_exp = false;

            if (op == "PLUS") {
                opcode = LLVMAdd;
            } else if (op == "MINUS") {
                opcode = LLVMSub;
            } else if (op == "TIMES") {
                opcode = LLVMMul;
            } else if (op == "DIV") {
                opcode = LLVMSDiv;
            } else if (op == "MOD") {
                opcode = LLVMSRem;
            } else if (op == "AND") {
                opcode = LLVMAnd;
                logic_exp = true;
            } else if (op == "OR") {
                opcode = LLVMOr;
                logic_exp = true;
            } else if (op == "XOR") {
                opcode = LLVMXor;  
                logic_exp = true;
            } else {
                // Comparison Expression 
                LLVMIntPredicate ipred;
                LLVMRealPredicate fpred;

                if (op == "LT") {
                    ipred = LLVMIntSLT;
                    fpred = LLVMRealOLT;
                } else if (op == "GT") {
                    ipred = LLVMIntSGT;
                    fpred = LLVMRealOGT;
                } else if (op == "LE") {
                    ipred = LLVMIntSLE;
                    fpred = LLVMRealOLE;
                } else if (op == "GE") {
                    ipred = LLVMIntSGE;
                    fpred = LLVMRealOGE;
                } else if (op == "EQ") {
                    ipred = LLVMIntEQ;
                    fpred = LLVMRealOEQ;
                } else if (op == "NEQ") {
                    ipred = LLVMIntNE;
                    fpred = LLVMRealONE;
                }

                if (LLVMGetTypeKind(LLVMTypeOf(lvalue)) == LLVMFloatTypeKind &&
	                LLVMGetTypeKind(LLVMTypeOf(rvalue)) == LLVMFloatTypeKind) {
                        return LLVMBuildFCmp(builder,fpred, lvalue, rvalue, "flt_cmp");
                } else {
                        return LLVMBuildICmp(builder, ipred, lvalue, rvalue, "int_cmp");
                }
            }

            if (LLVMGetTypeKind(LLVMTypeOf(lvalue)) == LLVMFloatTypeKind &&
                LLVMGetTypeKind(LLVMTypeOf(rvalue)) == LLVMFloatTypeKind && 
                !logic_exp) {
		            return LLVMBuildBinOp(builder, ((LLVMOpcode)(opcode + 1)), lvalue, rvalue, "_flt_op");
	            }
            else {
                    return LLVMBuildBinOp(builder, opcode, lvalue, rvalue, "_int_op");
            }

        }

        case (ASTNode::RETURN):
            {
                if (rettype == NULL) {
                    std::cout << "An unknown error occured..." << std::endl;
                    break;
                }
                // Node is of return type 
                if(rettype == LLVMVoidType()) {
                    return LLVMBuildRetVoid(builder);
                } else {
                    LLVMValueRef retval = codegen(node->children[0], true);
                    retval = getNodeValue(node->children[0], retval);
                    return LLVMBuildRet(builder, retval);
                }
            } 

        case (ASTNode::BLOCK):
            {
                return codegenBlock(node,builder,rettype);
            }

        default:
            // Generate code for all the children 
            // In the case of a EXPBLOCK 
            for(int i = 0; i< node->nchildren; i++) {
                codegen(node->children[i], local);
            }
            break;
    }
    return NULL;
}

/* Function to generate code for initializing variable */

LLVMValueRef CodeGen::varDecl(ASTNode* node, LLVMTypeRef type, bool local) {
    std::string vname = node->repr;
    LLVMValueRef mem;
    LLVMBuilderRef builder = builderStack.top();
    if (local) {
        mem = LLVMBuildAlloca(builder, type, vname.c_str());
    } else {
        mem = LLVMAddGlobal(cmodule, type, vname.c_str());
        LLVMSetLinkage(mem, LLVMCommonLinkage);
        // The symbol is not a global constant
        LLVMSetGlobalConstant(mem,0);
        // Initialize globals to 0 
        LLVMTypeKind tkind = LLVMGetTypeKind(type);
        LLVMValueRef z;
        if (tkind == LLVMIntegerTypeKind) {
            z = LLVMConstInt(LLVMInt32TypeInContext(contextStack.top()), 0, false);
        } else {
            z = LLVMConstReal(LLVMFloatTypeInContext(contextStack.top()), 0.0);
        }
        LLVMSetInitializer(mem, z);
    }
    symbols.top()[vname] = mem;
    return mem;
} 

LLVMValueRef CodeGen::arrDecl(ASTNode* node, LLVMTypeRef type, bool local) {
    LLVMBuilderRef builder = builderStack.top();
    std::string arr = node->children[0]->repr;
    int arrlen = node->children[1]->ival;
    LLVMTypeRef arrtype = LLVMArrayType(type, arrlen);

    LLVMValueRef arr_alloc = LLVMBuildArrayAlloca(builder, arrtype, NULL, arr.c_str());

    arrays.top()[arr] = arr_alloc;

    return arr_alloc;	
}

/* Function to generate code for a code block */
/* These are the nodes which can transfer control in the program */
LLVMValueRef CodeGen::codegenBlock(ASTNode* block, LLVMBuilderRef curr_builder, LLVMTypeRef rettype) {
    if (block->node_type == ASTNode::BLOCK) {
        for(int i = 0; i< block->nchildren; i++) {
            ASTNode* node = block->children[i];
            ASTNode::ntype node_type = node->node_type;

            // Cases on the base of node_type 
            if (node_type == ASTNode::RETURN) {
                // Node is of return type 
                if(rettype == LLVMVoidType()) {
                    return LLVMBuildRetVoid(curr_builder);
                } else {
                    LLVMValueRef retval = codegen(node->children[0], true);
                    retval = getNodeValue(node->children[0], retval);
                    return LLVMBuildRet(curr_builder, retval);
                }
            } 

            else if (node_type == ASTNode::ITE) { 
                LLVMBasicBlockRef currBlock = LLVMGetInsertBlock(curr_builder);
                LLVMValueRef func = LLVMGetBasicBlockParent(currBlock);
                bool allret = checkReturn(node);

                LLVMBasicBlockRef thenBlock = LLVMAppendBasicBlock(func, "then");
                LLVMBasicBlockRef elseBlock;
                LLVMBasicBlockRef mergeBlock;

                if (node->nchildren > 2) {
                    elseBlock = LLVMAppendBasicBlock(func, "else");
                }

                if (node->nchildren <= 2 || !allret) {
                    mergeBlock = LLVMAppendBasicBlock(func, "merge");
                }
                

                // Generate code for the Then Block
                LLVMPositionBuilderAtEnd(curr_builder, thenBlock);

                push_sym();
                
                codegenBlock(node->children[1], curr_builder, rettype);
                if (node->nchildren <= 2 || !allret) {
                    LLVMBuildBr(curr_builder, mergeBlock);
                }
                pop_sym();

                // Generate code for the Else Block, if it exists
                if (node->nchildren > 2) {
                    LLVMPositionBuilderAtEnd(curr_builder, elseBlock);

                    push_sym();
                    codegenBlock(node->children[2], curr_builder, rettype);
                    if (!allret) {
                        LLVMBuildBr(curr_builder, mergeBlock);
                    }
                    pop_sym();
                }

                // Generate code for the merged block 
                // Generate the condition in the current block
                LLVMPositionBuilderAtEnd(curr_builder, currBlock);
                LLVMValueRef ifCond = codegen(node->children[0],true);
                if (node->nchildren > 2 || allret) {
                    LLVMBuildCondBr(curr_builder, ifCond, thenBlock, elseBlock);
                } else if (!allret) {
                    LLVMBuildCondBr(curr_builder, ifCond, thenBlock, mergeBlock);
                } 
                // Continue from the end of the merged Block
                if (node->nchildren <= 2 || !allret){
                    LLVMPositionBuilderAtEnd(curr_builder,mergeBlock);
                } else {
                    LLVMPositionBuilderAtEnd(curr_builder,thenBlock);
                }
            }

            else if (node_type == ASTNode::GOTO) {
                std::string lab = node->children[0]->repr;
                bool found = false;
                int i;
                for(i = 0; i < labels.size(); i ++) {
                    std::string ls_label = LLVMGetBasicBlockName(labels[i]);
                    if (ls_label == lab) {
                        found = true;
                        break;
                    } 
                }
                if (found == true) {
                    return LLVMBuildBr(curr_builder, labels[i]);
                } else {
                    std::cout << "LABEL NOT FOUND!" << std::endl;
                    return NULL;
                }
            }

            else if (node_type == ASTNode::WHILE) {
                LLVMBasicBlockRef currBlock = LLVMGetInsertBlock(curr_builder);
                // The function which the basic block belongs to 
                LLVMValueRef func = LLVMGetBasicBlockParent(currBlock);

                LLVMBasicBlockRef whileBlock = LLVMAppendBasicBlock(func, "while");
                LLVMBasicBlockRef chkBlock = LLVMAppendBasicBlock(func, "chk");
                LLVMBasicBlockRef mergeBlock = LLVMAppendBasicBlock(func, "merge");

                LLVMBuildBr(curr_builder, chkBlock);
                // Generate code for the While Block
                LLVMPositionBuilderAtEnd(curr_builder, whileBlock);

                push_sym();
                codegenBlock(node->children[1], curr_builder, rettype);
                LLVMBuildBr(curr_builder, chkBlock);
                pop_sym();

                // Generate code for the Check block 
                LLVMPositionBuilderAtEnd(curr_builder, chkBlock);
                LLVMValueRef whCond = codegen(node->children[0],true);
                LLVMBuildCondBr(curr_builder, whCond, whileBlock, mergeBlock);
                
                // Continue from the end of the merged Block
                LLVMPositionBuilderAtEnd(curr_builder,mergeBlock);
            }

            else if (node_type == ASTNode::FOR) {
                // Initialize the expression 
                codegen(node->children[0], true);

                LLVMBasicBlockRef currBlock = LLVMGetInsertBlock(curr_builder);
                // The function which the basic block belongs to 
                LLVMValueRef func = LLVMGetBasicBlockParent(currBlock);

                LLVMBasicBlockRef forBlock = LLVMAppendBasicBlock(func, "for");
                LLVMBasicBlockRef chkBlock = LLVMAppendBasicBlock(func, "chk");
                LLVMBasicBlockRef incrBlock = LLVMAppendBasicBlock(func, "incr");
                LLVMBasicBlockRef mergeBlock = LLVMAppendBasicBlock(func, "merge");

                LLVMBuildBr(curr_builder, chkBlock);

                // Generate code for the For Block 
                LLVMPositionBuilderAtEnd(curr_builder, forBlock);

                push_sym();
                codegenBlock(node->children[3], curr_builder, rettype);
                LLVMBuildBr(curr_builder, incrBlock);
                pop_sym();

                LLVMPositionBuilderAtEnd(curr_builder, incrBlock);
                codegen(node->children[2],true);
                LLVMBuildBr(curr_builder, chkBlock);
    
                LLVMPositionBuilderAtEnd(curr_builder, chkBlock);
                LLVMValueRef forCond = codegen(node->children[1]->children[0],true);
                LLVMBuildCondBr(curr_builder, forCond, forBlock, mergeBlock);

                LLVMPositionBuilderAtEnd(curr_builder,mergeBlock);
            }

            else {
                codegen(node, true, rettype);
            }
        }
    
        return NULL;
    } else {
        codegen(block,true,rettype);
        return NULL;
    }
}

void CodeGen::TreeCodeGen(ASTNode* tree, const char* file) {
    codegen(tree, true);

    std::ofstream outfile;

    std::string filename = file;
    // filename += ".ll";
    outfile.open(filename);

    std::cout << "Writing generated code ..." << std::endl;

    outfile << LLVMPrintModuleToString(cmodule) << std::endl;

    outfile.close();
}

bool CodeGen::checkReturn(ASTNode* node) {
    ASTNode::ntype node_type = node->node_type;

    if (node_type == ASTNode::RETURN) {
        return true;
    }

    if (node_type == ASTNode::BLOCK) {
        bool chk = false;
        for(int i =0; i < node->nchildren; i++) {
            if (checkReturn(node->children[i])) {
                chk = true;
            }
        }
        return chk;
    }

    if (node_type == ASTNode::ITE) {
        if (node->nchildren >2) {
            return (checkReturn(node->children[1]) && checkReturn(node->children[2]));
        } else {
            return (checkReturn(node->children[1]));
        }
    }

    return false;

}
