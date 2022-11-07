/* 
Scoping Check Implementation 

enter_scope(): start a new nested scope
find_symbol(x): search stack starting from top, for the first scope that contains x. Return first x found or NULL if none found
add_symbol(x): add a symbol to the current scope (top scope)
check_scope(x): true if x defined in the current scope (top scope). allows to check for double definitions.
exit_scope(): exit current scope
*/

#pragma once
#include "ASTNode.hpp"
#include <stack>
#include <vector>
#include <iostream>


class Scope {
    public:
        std::vector<std::string> symbols;
        std::vector<std::string> locals;
    
    Scope();

    Scope(std::vector<std::string> syms, std::vector<std::string> locs);

    void print_syms();

    void add_symbol(std::string id);

    bool check_decl(std::string id, bool top);

    bool check_scope(std::string id, bool top);

};

class ScopeStack {
    public: 
        int size;
        std::stack<Scope> scopes;
        bool debug;

    ScopeStack();

    void enter_scope();

    void exit_scope();

    bool check_node(ASTNode* node, bool decl);

    
};