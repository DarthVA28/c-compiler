#include "ASTNode.hpp"

ASTNode::ASTNode(std::string label) {
    repr = label;
    /* Can have some logic to assign the type of the node if there is time */
}

ASTNode::ASTNode(ntype nodetype, std::string label) {
    node_type = nodetype;
    repr = label;
    if (node_type == ASTNode::SCONST) {
        int n = repr.length();
        repr = repr.substr(1,n-2);
    }
    // repr = std::string(label?label:"");
}

ASTNode::ASTNode(ntype nodetype, int intval) {
    node_type = nodetype;
    ival = intval;
    repr = std::to_string(ival);
}

ASTNode::ASTNode(ntype nodetype, float flval) {
    node_type = nodetype;
    fval = flval;
    repr = std::to_string(fval);
}

/* Constructor for Assignment Expressions */
ASTNode::ASTNode(ntype nodetype, std::string label, ASTNode* e1, ASTNode* op, ASTNode* e2) {
    node_type = nodetype;
    // repr = std::string(label?label:"");
    repr = label;
    children.push_back(e1);
    children.push_back(op);
    children.push_back(e2);
    nchildren += 3;
}

/* Constructor for Binary Expressions */
ASTNode::ASTNode(ntype nodetype, std::string label, ASTNode* e1, ASTNode* e2) {
    node_type = nodetype;
    repr = label;
    children.push_back(e1);
    children.push_back(e2);
    nchildren += 2;
}

/* Constructor for Unary Expressions */
ASTNode::ASTNode(ntype nodetype, std::string label, ASTNode* e1) {
    node_type = nodetype;
    repr = label;
    children.push_back(e1);
    nchildren += 1;
}

void ASTNode::addChild(ASTNode* node) {
    children.push_back(node);
    nchildren += 1;
}

ASTNode::ntype ASTNode::getType() {
    return node_type;
}


void ASTNode::printAST(const std::string& prefix, bool isLeft) {
    std::string s = repr;

    std::cout << prefix;

    std::cout << (isLeft ? "├────" : "└────" );

    // print the value of the node
    std::cout << s << std::endl;

    // enter the next tree level - left and right branch
    for(int i = 0; i < nchildren; i++ ) {
        if (i == nchildren-1) {

            children[i]->printAST(prefix + (isLeft ? "│   " : "    "), false);
        } else {
            children[i]->printAST( prefix + (isLeft ? "│   " : "    "), true);
        }
    }
    
}

void ASTNode::printAST() {
    printAST("", false);    
}
