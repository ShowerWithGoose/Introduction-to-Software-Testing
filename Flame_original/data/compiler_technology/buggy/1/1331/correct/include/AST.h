#ifndef COMPILER_AST_H
#define COMPILER_AST_H

#include <utility>
#include <vector>
#include <string>

using namespace std;

class AST {// 抽象语法树
public:
    string type;// 类型
    int line{};//行号
    string token;// token
    vector<AST> children;// 子节点

    AST() = default;

    AST(string type, int line, string token) {
        this->type = std::move(type);
        this->line = line;
        this->token = std::move(token);
    }
};


#endif //COMPILER_AST_H
