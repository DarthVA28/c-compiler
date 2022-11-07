#pragma once
#include "ASTNode.hpp"
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <iostream>

class Optimizer {
    public:
        int npasses;

    Optimizer();

    void removeDeadCode(ASTNode* node);

    bool constFolding(ASTNode* node);

    void optimizeAST(ASTNode* tree);

};