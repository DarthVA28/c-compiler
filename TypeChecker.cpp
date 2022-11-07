#include "TypeChecker.hpp"


TypeChecker::TypeChecker() {
    getType[0] = "INT";
    getType[1] = "FLOAT";
    getType[2] = "CHAR*";
    getType[3] = "INTARR";
    getType[4] = "FLOATARR";

    getTypeId["INT"]    = 0;
    getTypeId["FLOAT"]  = 1;
    getTypeId["CHAR*"]  = 2;
    getTypeId["INTARR"]   = 3;
    getTypeId["FLOATARR"]   = 4;

    std::map<std::string,int> initmap;
    symbols.push(initmap);
}

void TypeChecker::enter_scope() {
    std::map<std::string,int> topmap = symbols.top();
    symbols.push(topmap); 
}

void TypeChecker::exit_scope() {
    symbols.pop();
}

void TypeChecker::add_symbol(std::string id, std::string idtype) {
    symbols.top()[id] = getTypeId[idtype];
}

int TypeChecker::lookup_sym(std::string id){
    std::map<std::string,int> topmap = symbols.top();
    if (topmap.find(id) != topmap.end()) {
        return topmap[id];
    }
    return -1;
}

int TypeChecker::check_node(ASTNode* node) {
    ASTNode::ntype node_type = node->node_type;

    switch(node_type) {
        case (ASTNode::FUNC):
            {
            std::string funcname = (node->children[1]->children[0])->repr;
            std::string ftype = node->children[0]->repr;

            add_symbol(funcname,ftype);
            std::vector<int> funcargs;
            fargs[funcname] = funcargs;


            // Add variables in the function arg list 
        
            enter_scope();

            for(int i = 1; i < node->children[1]->nchildren; i++) {
                ASTNode* temp = node->children[1]->children[i];
                std::string argtype = temp->children[0]->repr;
                std::string arg;
                if (temp->children[1]->node_type != ASTNode::ARRAY) {
                    arg = temp->children[1]->repr;
                } else {
                    arg = temp->children[1]->children[0]->repr;
                    argtype += "ARR";
                }
            
                add_symbol(arg,argtype);
                fargs[funcname].push_back(getTypeId[argtype]);
            }
            int chk = check_node(node->children[2]);

            exit_scope();

            if (chk >= 0) {
                return getTypeId[ftype];
            } else {
                return -1;
            }

            }

        case (ASTNode::FOR):
            {
                int chk1 = check_node(node->children[0]);
                int chk2 = check_node(node->children[1]);
                int chk3 = check_node(node->children[2]);
                if (chk1 < 0 || chk2 < 0 || chk3 < 0) {
                    return -1;
                }
                
                int chk4;
                enter_scope();
                chk4 = check_node(node->children[3]);
                exit_scope();

                return chk4;
            }

        case (ASTNode::WHILE):
            {
                int chk = check_node(node->children[0]);
                if (chk < 0) {
                    return -1;
                } 
                
                enter_scope();
                chk = check_node(node->children[1]);
                exit_scope();

                return chk;
            }

        case (ASTNode::ITE):
            {
                int chk = check_node(node->children[0]);
                if (chk < 0) {
                    return chk;
                } 
                
                enter_scope();
                chk = check_node(node->children[1]);
                exit_scope();

                if (chk < 0) {
                    return chk;
                } 

                if (node->nchildren > 2) {
                    enter_scope();
                    chk = check_node(node->children[2]);
                    exit_scope();
                }

                return chk;
            }     

        case (ASTNode::VARDEC):
            {
                int chk = 100;
                std::string vtype = node->children[0]->repr;

                if (node->children[1]->node_type != ASTNode::FUNCDEF) {

                    for(int i = 1; i<node->nchildren; i++) {
                        std::string vname;
                        if (node->children[i]->node_type == ASTNode::ASSIGNEXP) {
                            if (node->children[i]->children[0]->node_type == ASTNode::ARRAY) {
                                vname = node->children[i]->children[0]->children[0]->repr;
                                vtype += "ARR";
                            } else {
                                vname = node->children[i]->children[0]->repr;
                            }
                        } else if (node->children[i]->node_type == ASTNode::ARRAY) {
                            vname = node->children[i]->children[0]->repr;
                            vtype += "ARR";
                        } else {
                            vname = node->children[i]->repr;
                        }
                        symbols.top()[vname] = getTypeId[vtype];
                        if (check_node(node->children[i]) < 0) {
                                chk = -1;
                        }
                    }
                if (chk < 0) {
                    return chk;
                } 
                return getTypeId[vtype];

                } else {
                    std::string funcname = (node->children[1]->children[0])->repr;
                    std::string ftype = vtype;

                    add_symbol(funcname,ftype);
                    std::vector<int> funcargs;
                    fargs[funcname] = funcargs;

                    // Add variables in the function arg list 
                
                    enter_scope();

                    for(int i = 1; i < node->children[1]->nchildren; i++) {
                        if (node->children[1]->children[i]->repr == "...") {
                            fargs[funcname].push_back(50);
                            break;
                        }
                        ASTNode* temp = node->children[1]->children[i];
                        std::string argtype = temp->children[0]->repr;
                        
                        std::string arg = temp->children[1]->repr;
                        // std::cout << argtype << " " << arg << std::endl; 
                        add_symbol(arg,argtype);
                        fargs[funcname].push_back(getTypeId[argtype]);
                    }
                    // int chk = check_node(node->children[2]);

                    exit_scope();
                    return getTypeId[ftype];
                    // if (chk >= 0) {
                    //     return getTypeId[ftype];
                    // } else {
                    //     return -1;
                    // }
                }
                
            }

        case (ASTNode::FUNCALL):
            {
                std::string fname = node->children[0]->repr;
                // std::cout << "Checking func " << fname << std::endl;
                for(int i = 1; i<node->nchildren; i++) {
                    // std::cout << "Checking arg " << i << std::endl;
                    if (fargs[fname][i-1] == 50) {
                        return symbols.top()[fname];
                    }
                    if (fargs[fname][i-1] != check_node(node->children[i])){
                        // std::cout << "failed1" << std::endl;
                        return -1;
                    }
                }
                return symbols.top()[fname];
            }

        case (ASTNode::ARRELEM):
        {
            std::string arrname = node->repr;
            if (check_node(node->children[0]->children[0]) != 0) {
                std::cout << check_node(node->children[0]->children[0]) << std::endl;
                std::cout << "Typecheck failure. Array " << arrname << " accessed with non-int index." << std::endl;
                return -1;
            }
            int arrtype = symbols.top()[arrname];
            if (arrtype < 3) {
                std::cout << "Typecheck failure. Indexed a non-array item." << std::endl;
                return -1;
            }
            // std::cout << (arrtype-3) << std::endl;
            return arrtype-3;
        }

        case (ASTNode::ASSIGNEXP):
            {
                // std::string vname = node->children[0]->repr;
                int ltype = check_node(node->children[0]);
                int rtype = check_node(node->children[2]);
                if (ltype >= 0 && rtype >= 0 && ltype == rtype) {
                    return ltype;
                } else {
                    if (rtype >= 0 && ltype >= 0){
                        std::string vname = node->children[0]->repr;
                        std::cout << "Typecheck Failure. Variable " << vname << " of type " 
                        << getType[ltype] << " assigned to expression of type " << getType[rtype] << std::endl;
                    return -1;
                    } else {
                        // std::cout << "failed2" << std::endl;
                        return -1;
                    }
                }
            }
        case (ASTNode::ID):
        {
            std::string vname = node->repr;
            return symbols.top()[vname];
        }

        case (ASTNode::BINEXP):
        {
            std::string op = node->repr;
            int ltype = check_node(node->children[0]);
            int rtype = check_node(node->children[1]);
            if (ltype == rtype && ltype != 2 && ltype >= 0) {
                return ltype;
            } else {
                if (ltype >= 0 and rtype >= 0) {
                    std::cout << "Argument types " << getType[ltype] << " " << getType[rtype] << " mismatch for operator " << op << std::endl;
                }
                // std::cout << "failed3" << std::endl;
                return -1;
            }
        }

        case (ASTNode::ICONST):
        {
            return 0;
        }

        case (ASTNode::FCONST):
        {
            return 1;
        }

        case (ASTNode::SCONST):
        {
            return 2;
        }

        // case (ASTNode::POINTER):
        //     {
        //     ASTNode* temp = node;
        //     while (temp->node_type == ASTNode::POINTER) {
        //         temp = temp->children[0];
        //     }
        //     if (scopes.top().check_scope(temp->repr)) {
        //         std::cout << "Double declaration of pointer variable " << temp->repr << "in the program." << std::endl;
        //         return false;
        //     }
        //     scopes.top().add_symbol(node->repr);
        //     break;
        //     }

        default:
            // std::cout << "Taken default branch " << std::endl;
            break;

    }
    
    if (node->nchildren == 0) {
        return 100;
    } else {
        for(int i = 0; i < node->nchildren; i++) {
            // std::cout << node->repr << " iteration" << i << std::endl;
            if (check_node(node->children[i]) < 0) {
                // std::cout << "failed4" << std::endl;
                return -1;
            }
        }
        return 100;
    }

    return 100;

}

