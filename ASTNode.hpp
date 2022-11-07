#pragma once 
#include<string>
#include<vector>
#include<iostream>

class ASTNode { 
    public:
        enum ntype { ID, POINTER, TYPE, PARAMETER, ICONST, FCONST, SCONST, 
        STATEMENTS, ASSIGNOP, UNOP, BINOP, EXPRESSION, ITE, WHILE, FOR, PAREXP, 
        ASSIGNEXP, BINEXP, UNEXP, FUNC, FUNCDEF, BLOCK, TRANSLATION_UNIT, VARDEC, 
        FUNCALL, RETURN, GOTO, LABEL, ARRAY, ARRELEM, LIST};
        
        std::vector<ASTNode*> children;
        int nchildren = 0;

        ntype node_type;
        std::string repr;
        int ival = 0; 
        float fval;

    ASTNode(std::string label);

    ASTNode(ntype nodetype, std::string label);
    
    ASTNode(ntype nodetype, int intval);

    ASTNode(ntype nodetype, float flval);

    ASTNode(ntype nodetype, std::string label, ASTNode* e1, ASTNode* op, ASTNode* e2);

    ASTNode(ntype nodetype, std::string label, ASTNode* e1, ASTNode* e2);

    ASTNode(ntype nodetype, std::string label, ASTNode* e1);

    void addChild(ASTNode* node);

    ntype getType();

    void printAST(const std::string& prefix, bool isLeft);

    void printAST();
        
};

class ASTNodeList {
    public: 
        std::vector<ASTNode*> nodelist;
        int length = 0;

    ASTNodeList(ASTNode* node) {
        nodelist.push_back(node);
        length++;
    }

    void add(ASTNode* node) {
        nodelist.push_back(node);
        length++;
    }

    int getLength() {
        return length;
    }

    ASTNode* get(int i) {
        return nodelist[i];
    }

};