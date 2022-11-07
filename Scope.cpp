#include "Scope.hpp"

Scope::Scope() {}

Scope::Scope(std::vector<std::string> syms, std::vector<std::string> locs) {
    for(int i = 0; i < syms.size(); i++) {
        symbols.push_back(syms[i]);
    }
    for(int j = 0; j < locs.size(); j++) {
        symbols.push_back(locs[j]);
    }
}

void Scope::print_syms() {
    for (int i = 0; i < symbols.size(); i++) {
        std::cout << symbols[i] << std::endl;
    }
    std::cout << "------------" << std::endl;
    for (int i = 0; i < locals.size(); i++) {
        std::cout << locals[i] << std::endl;
    }
}

void Scope::add_symbol(std::string id) {
    locals.push_back(id);
}

bool Scope::check_decl(std::string id, bool top = false) {
    int n = locals.size();
    for (int i = 0; i < n; i++) {
        if (locals[i] == id) {
            return true;
        }
    }
    return false;
}

bool Scope::check_scope(std::string id, bool top = false) {
    int n = symbols.size();
    for (int i = 0; i < n; i++) {
        if (symbols[i] == id) {
            return true;
        }
    }
    int m = locals.size();
    for (int i = 0; i < m; i++) {
        if (locals[i] == id) {
            return true;
        }
    }
    return false;
}

ScopeStack::ScopeStack() {
    Scope startscope = Scope();
    scopes.push(startscope);
    bool debug = false;
}

void ScopeStack::enter_scope() {
    Scope topscope = scopes.top();
    std::vector<std::string> syms = topscope.symbols;
    std::vector<std::string> locs = topscope.locals;
    Scope newscope = Scope(syms,locs);
    scopes.push(newscope);
}

void ScopeStack::exit_scope() {
    scopes.pop();
}

bool ScopeStack::check_node(ASTNode* node, bool decl) {
    /* Main Function for checking 
    Scoping rules of the language */

    // Logic for checking node based on type of node here
    ASTNode::ntype node_type = node->node_type;
    bool d = false;

    switch(node_type) {

        case (ASTNode::FUNC):
            {
            std::string funcname = (node->children[1]->children[0])->repr;
            // std::cout << "Encountered " << funcname << std::endl;
            // Check the function declaration 
            if (scopes.top().check_scope(funcname)) {
                std::cout << "Double declaration of function " << node->repr << "in the program." << std::endl;
                return false;
            }
            scopes.top().add_symbol(funcname);

            // Add variables in the function arg list 
        
            enter_scope();

            for(int i = 1; i < node->children[1]->nchildren; i++) {
                ASTNode* temp = node->children[1]->children[i];
                if (temp->children[1]->node_type == ASTNode::ARRAY) {
                    scopes.top().add_symbol(temp->children[1]->children[0]->repr);
                } else {
                    scopes.top().add_symbol(temp->children[1]->repr);
                }
            }
            // Check the function body
            // std::cout << "Entering scope for function " << funcname << std::endl;
            bool b = check_node(node->children[2],decl);
            // if (b == true) {
            //     std::cout << "Check complete and passed for: " << funcname << std::endl;
            // }
            exit_scope();

            return b;
            }

        case (ASTNode::FOR):
            {
                bool b = check_node(node->children[0],decl);
                b = b & check_node(node->children[1],decl);
                b = b & check_node(node->children[2],decl);
                if (b == false) {
                    return false;
                } 
                
                enter_scope();
                b = check_node(node->children[3],decl);
                exit_scope();

                return b;
            }

        case (ASTNode::WHILE):
            {
                bool b = check_node(node->children[0],decl);
                if (b == false) {
                    return false;
                } 
                
                enter_scope();
                b = check_node(node->children[1],decl);
                exit_scope();

                return b;
            }

        case (ASTNode::ITE):
            {
                bool b = check_node(node->children[0],decl);
                if (b == false) {
                    return false;
                } 
                
                enter_scope();
                b = check_node(node->children[1],decl);
                exit_scope();

                if (node->nchildren > 2) {
                    enter_scope();
                    b = check_node(node->children[2],decl);
                    exit_scope();
                }

                return b;
            }     

        case (ASTNode::VARDEC):
            {
                decl = true;          
                break;
            }
        
        case (ASTNode::FUNCDEF):
        {
            if (decl) {
                std::string funcname = (node->children[0]->repr);
                // std::cout << "Encountered " << funcname << std::endl;
                // Check the function declaration 
                if (scopes.top().check_scope(funcname)) {
                    std::cout << "Double declaration of function " << node->children[0]->repr << "in the program." << std::endl;
                    return false;
                }
                scopes.top().add_symbol(funcname);

                return true;
            }
            return true;
        }

        case (ASTNode::FUNCALL):
            {
                if(!scopes.top().check_scope(node->children[0]->repr)) {
                    std::cout << "Function " << node->children[0]->repr << " not declared before use." << std::endl;
                    return false;
                } 

                for(int i = 1; i<node->nchildren; i++) {
                    if (!check_node(node->children[i], decl)){
                        return false;
                    }
                }

                return true;
            }

        case (ASTNode::LABEL):
            {
                if (scopes.top().check_scope(node->repr)) {
                    std::cout << "Double declaration of label " << node->repr << " in the program." << std::endl;
                    return false;
                } 
                scopes.top().add_symbol(node->repr);
                break;
            }

        case (ASTNode::ID):
            if (decl && scopes.top().check_decl(node->repr)) {
                std::cout << "Double declaration of variable " << node->repr << " in the program." << std::endl;
                scopes.top().print_syms();
                return false;
            } else if (!decl && !scopes.top().check_scope(node->repr)) {
                std::cout << "Variable " << node->repr << " not declared before use." << std::endl;
                // scopes.top().print_syms();
                return false;
            }
            if (decl) {
                scopes.top().add_symbol(node->repr);
                decl = false;
            }
            break;

        case (ASTNode::ARRAY):
        {
            if (scopes.top().check_decl(node->children[0]->repr)) {
                std::cout << "Array " << node->children[0]->repr  << " already declared in the program." << std::endl;
                scopes.top().print_syms();
                return false;
            }  else {
                scopes.top().add_symbol(node->children[0]->repr);
                return true;
            }
            break;
        }

        case (ASTNode::ARRELEM):
            if (!scopes.top().check_scope(node->repr)) {
                std::cout << "Array " << node->repr << " not declared before access." << std::endl;
                // scopes.top().print_syms();
                return false;
            }
            return check_node(node->children[0]->children[0],decl);

        case (ASTNode::POINTER):
            {
            ASTNode* temp = node;
            while (temp->node_type == ASTNode::POINTER) {
                temp = temp->children[0];
            }
            if (scopes.top().check_scope(temp->repr)) {
                std::cout << "Double declaration of pointer variable " << temp->repr << "in the program." << std::endl;
                return false;
            }
            scopes.top().add_symbol(node->repr);
            break;
            }

        default:
            // std::cout << "Taken default branch " << std::endl;
            break;

    }
    
    if (node->nchildren == 0) {
        return true;
    } else {
        if (decl && node->node_type == ASTNode::ASSIGNEXP) {
            for(int i = 0; i < node->nchildren; i++) {
                if (!check_node(node->children[i],decl)) {
                    return false;
                }
                decl = false;
                return true;
            }
        } else {
            for(int i = 0; i < node->nchildren; i++) {
                if (!check_node(node->children[i],decl)) {
                    return false;
                }
            }
            return true; 
        }
    }

    return true;
}
