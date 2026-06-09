//
// Created by  on 2024/10/11.
//

#include "node.h"

#include <utility>

bool Node::isLeaf() {
    if(this->type==VN)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Node::addChildren(const std::shared_ptr<Node>& node) {
    this->children.push_back(node);

}

void Node::deleteChildren() {
    this->children.pop_back();
}
void Node::addParent(const std::shared_ptr<Node>& node) {
    this->parent=node;
}
std::shared_ptr<Node> Node::getParent() {
    return this->parent;
}
Node::Node(std::shared_ptr<Node> p, int depth, Token token)
        : parent(std::move(p)), depth(depth), type(VT), token(std::move(token)) {}

Node::Node(std::shared_ptr<Node> p, int depth, Grammar grammar)
        : parent(std::move(p)), depth(depth), type(VN), grammar(std::move(grammar)) {}


void Node::postOrderTraversal(std::ostream &os) {
    for(auto &child:this->children) {
        child->postOrderTraversal(os);
    }
    if(!this->token.value.empty())
    {
        os<< this->token.TokenType2String()<<" "<<this->token.value<<std::endl;
    } else
    {
        if(this->grammar.type!=BlockItem&& this->grammar.type!=Decl&& this->grammar.type!=BType) {
            os << "<" << this->grammar.value << ">" << std::endl;
        }
    }

}