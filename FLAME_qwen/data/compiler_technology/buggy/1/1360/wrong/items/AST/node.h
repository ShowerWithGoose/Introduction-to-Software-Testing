//
// Created by  on 2024/10/11.
//
#include <memory>
#include <vector>
#include <string>
#include <ostream>
#include "token.h"
#include "Grammar.h"
#ifndef MYLEXER_ANALYSIS_NODE_H
#define MYLEXER_ANALYSIS_NODE_H

enum NodeType{
    VN,VT
};
class Node {
private:
    NodeType type;
    std::shared_ptr<Node> parent;
    std::vector<std::shared_ptr<Node>> children;
    int depth{};
    Grammar grammar;
    Token token;
public:
    Node(std::shared_ptr<Node> p,int depth,Token token);
    Node(std::shared_ptr<Node> p,int depth,Grammar grammar);
    bool isLeaf();
    std::shared_ptr<Node> getParent();
    void addChildren(const std::shared_ptr<Node>& node);
    void deleteChildren();
    void addParent(const std::shared_ptr<Node>& node);
    void postOrderTraversal(std::ostream &os);

    void postOrderTraversal();
};


#endif //MYLEXER_ANALYSIS_NODE_H
