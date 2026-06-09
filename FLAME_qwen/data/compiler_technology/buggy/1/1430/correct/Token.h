// Token.h
#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <map>
#include <vector>

// 词法单元结构
struct Token {
    std::string type;
    std::string value;
    int line;
};

// 关键字与其对应的类型映射
extern std::map<std::string, std::string> keywords;

// 运算符与其对应的类型映射
extern std::map<std::string, std::string> operators;

extern std::vector<Token> tokens;

#endif // TOKEN_H
