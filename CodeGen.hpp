#pragma once
#include "ASTNode.hpp"
#include "llvm_headers.hpp"
#include <stack>
#include <vector>
#include <map>    
#include <iostream>

#define table std::map<std::string,LLVMValueRef>

extern LLVMTypeRef getLLVMType(std::string type_qualifier);

class CodeGen {
    public:
        LLVMModuleRef cmodule;

        /* Symbol Tables for Variables & Function Names */
        std::stack<table> symbols;
        std::stack<table> functions;
        std::stack<table> func_args;
        std::stack<table> arrays;

        /* llvm context + builder stacks */
        std::stack<LLVMContextRef> contextStack;
        std::stack<LLVMBuilderRef> builderStack;

        std::vector<LLVMBasicBlockRef> labels;

        CodeGen();

        void push_sym();

        void pop_sym();

        bool checkReturn(ASTNode* node);

        LLVMValueRef codegen(ASTNode* node, bool local, LLVMTypeRef rettype);

        LLVMValueRef varDecl(ASTNode* node, LLVMTypeRef type, bool local);

        LLVMValueRef arrDecl(ASTNode* node, LLVMTypeRef type, bool local);

        LLVMValueRef codegenBlock(ASTNode* block, LLVMBuilderRef curr_builder, LLVMTypeRef rettype);

        LLVMValueRef getVar(std::string vname);

        LLVMValueRef getFunc(std::string fname);

        LLVMValueRef getFArg(std::string vname);

        LLVMValueRef getArr(std::string arr);

        LLVMValueRef getNodeValue(ASTNode* node, LLVMValueRef mem);

        void TreeCodeGen(ASTNode* tree, const char* file);

        // LLVMValueRef 
};