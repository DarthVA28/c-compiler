/* Type Checker Implementation */

#pragma once
#include "ASTNode.hpp"
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <iostream>

class TypeChecker {
    public:
        std::stack<std::map<std::string,int>> symbols;
        std::map<std::string, std::vector<int>> fargs;

        std::map<int,std::string> getType;

        std::map<std::string,int> getTypeId;

    TypeChecker();

    void enter_scope();

    void exit_scope();

    void add_symbol(std::string id, std::string idtype);

    int lookup_sym(std::string id);

    int check_node(ASTNode* node);

    void print_syms();

};
