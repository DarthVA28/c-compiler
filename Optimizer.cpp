#include "Optimizer.hpp"

Optimizer::Optimizer() {
    npasses = 1;
}

bool containsReturn(ASTNode* block) {
    for(int i = 0; i< block->nchildren; i++) {
        if (block->children[i]->node_type == ASTNode::RETURN) {
            return true;
        }
    } 
    return false;
}

void Optimizer::removeDeadCode(ASTNode* block) { 
    
    if (block->node_type == ASTNode::BLOCK) {
        
        int ret_idx = -1;

        for(int i = 0; i< block->nchildren; i++) {
            ASTNode* node = block->children[i];
            removeDeadCode(node);
            ASTNode::ntype node_type = node->node_type;
            if (node_type == ASTNode::RETURN || (node_type == ASTNode::BLOCK && containsReturn(node))) {
                ret_idx = i+1;
                break;
            }
        }

        if (ret_idx != -1) {
            ASTNode newblock = ASTNode(ASTNode::BLOCK, "STBLOCK");
            for(int i = 0; i < ret_idx; i++) {
                newblock.addChild(block->children[i]);
            }
            *block = newblock;

        }

        // Indices to remove 
        std::vector<int> rm_indices;

        for(int i = 0; i< block->nchildren; i++) {
            ASTNode* node = block->children[i];
            ASTNode::ntype node_type = node->node_type;
            // Useless Branch Conditions
            if (node_type == ASTNode::ITE) {
                if (node->children[0]->repr == "1") {
                    *node = *(node->children[1]);
                } else if (node->children[0]->repr == "0") {
                    if (node->nchildren > 2) {
                        *node = *(node->children[2]);
                    } else {
                        // We can remove the ITE entirely 
                        rm_indices.push_back(i);
                    }
                }
            }
        }
        
        if (rm_indices.size() > 0) {
            ASTNode newblock = ASTNode(ASTNode::BLOCK, "STBLOCK");
            int j = 0;
            // Remove the ITEs
            
            for(int i = 0; i < ret_idx; i++) {
                if (i != rm_indices[j]) {
                    newblock.addChild(block->children[i]);
                } else { 
                    if (j < rm_indices.size()) {
                        j += 1;
                    }
                }
            }
            *block = newblock;
        }

    } else if (block->nchildren > 0) {
        for(int i = 0; i< block->nchildren; i++) {
            removeDeadCode(block->children[i]);
        }
    }
}

bool Optimizer::constFolding(ASTNode* node) {
    if (node->node_type == ASTNode::BINEXP) {
        bool b1 = constFolding(node->children[0]);
        bool b2 = constFolding(node->children[1]);
        if (b1 && b2) {
            if (node->children[0]->node_type == ASTNode::ICONST) {
                int nval = 0;
                if (node->repr == "PLUS") {
                    nval = node->children[0]->ival + node->children[1]->ival;
                } else if (node->repr == "MINUS") {
                    nval = node->children[0]->ival - node->children[1]->ival;
                } else if (node->repr == "TIMES") {
                    nval = node->children[0]->ival * node->children[1]->ival;
                } else if (node->repr == "DIV") {
                    nval = node->children[0]->ival / node->children[1]->ival;
                } else if (node->repr == "MOD") {
                    nval = node->children[0]->ival % node->children[1]->ival;
                } else if (node->repr == "OR") {
                    nval = node->children[0]->ival || node->children[1]->ival;
                } else if (node->repr == "AND") {
                    nval = node->children[0]->ival && node->children[1]->ival;
                } else if (node->repr == "LT") {
                    nval = (node->children[0]->ival < node->children[1]->ival);
                } else if (node->repr == "GT") {
                    nval = (node->children[0]->ival > node->children[1]->ival);
                } else if (node->repr == "LE") {
                    nval = (node->children[0]->ival <= node->children[1]->ival);
                } else if (node->repr == "GE") {
                    nval = (node->children[0]->ival >= node->children[1]->ival);
                } else if (node->repr == "EQ") {
                    nval = (node->children[0]->ival == node->children[1]->ival);
                } else if (node->repr == "NEQ") {
                    nval = (node->children[0]->ival != node->children[1]->ival);
                }
                ASTNode newnode = ASTNode(ASTNode::ICONST, nval);
                *node = newnode;
                return true;
            } else if (node->children[0]->node_type == ASTNode::FCONST) {
                float nval;
                if (node->repr == "PLUS") {
                    nval = node->children[0]->fval + node->children[1]->fval;
                } else if (node->repr == "MINUS") {
                    nval = node->children[0]->fval - node->children[1]->fval;
                } else if (node->repr == "TIMES") {
                    nval = node->children[0]->fval * node->children[1]->fval;
                } else if (node->repr == "DIV") {
                    nval = node->children[0]->fval / node->children[1]->fval;
                } else if (node->repr == "OR") {
                    nval = node->children[0]->fval || node->children[1]->fval;
                } else if (node->repr == "AND") {
                    nval = node->children[0]->fval && node->children[1]->fval;
                } else if (node->repr == "LT") {
                    nval = (node->children[0]->fval < node->children[1]->fval);
                } else if (node->repr == "GT") {
                    nval = (node->children[0]->fval > node->children[1]->fval);
                } else if (node->repr == "LE") {
                    nval = (node->children[0]->fval <= node->children[1]->fval);
                } else if (node->repr == "GE") {
                    nval = (node->children[0]->fval >= node->children[1]->fval);
                } else if (node->repr == "EQ") {
                    nval = (node->children[0]->fval == node->children[1]->fval);
                } else if (node->repr == "NEQ") {
                    nval = (node->children[0]->fval != node->children[1]->fval);
                }
                std::cout << "Going to optimize shit ahaha: " << nval << std::endl;
                ASTNode newnode = ASTNode(ASTNode::FCONST, nval);
                *node = newnode;
                return true;
            }
        } else {
            // Can do some logical optimizations
            if (node->children[0]->node_type == ASTNode::ICONST) {
                int nval = -1;
                if (node->repr == "OR") {
                    if (node->children[0]->ival == 1 || node->children[1]->ival == 1) {
                        nval = 1;
                    }
                } else if (node->repr == "AND") {
                    if (node->children[0]->ival == 0 || node->children[1]->ival == 0) {
                        nval = 0;
                    }
                }
                if (nval >= 0){
                    ASTNode newnode = ASTNode(ASTNode::ICONST, nval);
                    *node = newnode;
                    return true;
                } else {
                    return false;
                }
            } 
        }
    } else if (node->node_type == ASTNode::ICONST) {
        return true;
    } else if (node->node_type == ASTNode::FCONST) {
        return true;
    } else if ((node->node_type == ASTNode::ID)) {
        return false;
    } else {
        if (node->nchildren > 0) {
            for(int i = 0; i< node->nchildren; i++) {
                constFolding(node->children[i]);
            }
        }
        return false;
    }
    return false;
}


void Optimizer::optimizeAST(ASTNode* tree) {
    constFolding(tree);
    removeDeadCode(tree);
    removeDeadCode(tree);
}

