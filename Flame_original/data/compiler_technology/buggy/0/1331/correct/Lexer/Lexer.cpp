#include "Lexer.h"
#include <string>
#include <iostream>
#include "Error.h"

using namespace std;

// 构造函数：初始化成员变量并打开文件
Lexer::Lexer(const std::string &content) {
    this->content = content;
    ch = content[0];
}

// 清空 token
void Lexer::clearToken() {
    token.clear();
}

// 将当前字符追加到 token
void Lexer::catToken() {
    token += static_cast<char>(ch);
}

// 保留字匹配：如果当前 token 是保留字，返回对应的索引，否则返回 0
LexType Lexer::reserver() {
    auto it = lexMap.find(token);
    if (it != lexMap.end()) {
        return it->second;
    }
    return IDENFR;
}


char Lexer::get_ch() {
    return content[++index];
}

// 将 token 转换为整数
unsigned long long Lexer::transNum() {
    return stoull(token);
}

// 处理下一个单词，返回 true 表示成功，false 表示文件结束
bool Lexer::next() {
    clearToken();
    if (ch == EOF)
        return false;  // 文件结束
    // 跳过空白字符
    while (isspace(ch)) {
        if (ch == '\n')
            line++;
        ch = get_ch();
    }
    // 处理标识符或关键字
    if (isalpha(ch) || ch == '_') {
        do {
            catToken();
            ch = get_ch();
        } while (isalnum(ch) || ch == '_');
        int resultValue = reserver();
        if (!resultValue)
            symbol = LexTypeNames[IDENFR];
        else
            symbol = LexTypeNames[static_cast<LexType>(resultValue)];
    }
        // 处理数字
    else if (isdigit(ch)) {
        do {
            catToken();
            ch = get_ch();
        } while (isdigit(ch));
        num = transNum();
        symbol = LexTypeNames[INTCON];
    }
        // 处理其他符号
    else {
        switch (ch) {
            case '+':
                symbol = LexTypeNames[PLUS];
                catToken();
                ch = get_ch();
                break;
            case '-':
                symbol = LexTypeNames[MINU];
                catToken();
                ch = get_ch();
                break;
            case '*':
                symbol = LexTypeNames[MULT];
                catToken();
                ch = get_ch();
                break;
            case '/':
                catToken();
                ch = get_ch();
                if (ch == '/') {
                    // 处理单行注释
                    while (ch != '\n' && ch != EOF)
                        ch = get_ch();
                    if (ch == EOF)
                        return false;
                    if (ch == '\n') {
                        line++;
                        ch = get_ch();
                        return next();
                    }
                } else if (ch == '*') {
                    // 处理多行注释
                    while (true) {
                        do {
                            ch = get_ch();
                            if (ch == EOF) {
                                return false;
                            }
                            if (ch == '\n') {
                                line++;
                            }
                        } while (ch != '*');
                        do {
                            ch = get_ch();
                        } while (ch == '*');
                        if (ch == '/') {
                            ch = get_ch();
                            return next();
                        }
                    }
                } else {
                    symbol = LexTypeNames[DIV];
                }
                break;
            case '%':
                symbol = LexTypeNames[MOD];
                catToken();
                ch = get_ch();
                break;
            case '!':
                catToken();
                ch = get_ch();
                if (ch == '=') {
                    symbol = LexTypeNames[NEQ];
                    catToken();
                    ch = get_ch();
                } else {
                    symbol = LexTypeNames[NOT];
                }
                break;
            case '&':
                catToken();
                ch = get_ch();
                if (ch == '&') {
                    symbol = LexTypeNames[AND];
                    catToken();
                    ch = get_ch();
                } else {
                    Error::getInstance().error('a', line);
                }
                break;
            case '|':
                catToken();
                ch = get_ch();
                if (ch == '|') {
                    symbol = LexTypeNames[OR];
                    catToken();
                    ch = get_ch();
                } else {
                    Error::getInstance().error('a', line);
                }
                break;
            case '<':
                catToken();
                ch = get_ch();
                if (ch == '=') {
                    symbol = LexTypeNames[LEQ];
                    catToken();
                    ch = get_ch();
                } else {
                    symbol = LexTypeNames[LSS];
                }
                break;
            case '>':
                catToken();
                ch = get_ch();
                if (ch == '=') {
                    symbol = LexTypeNames[GEQ];
                    catToken();
                    ch = get_ch();
                } else {
                    symbol = LexTypeNames[GRE];
                }
                break;
            case '=':
                catToken();
                ch = get_ch();
                if (ch == '=') {
                    symbol = LexTypeNames[EQL];
                    catToken();
                    ch = get_ch();
                } else {
                    symbol = LexTypeNames[ASSIGN];
                }
                break;
            case ';':
                symbol = LexTypeNames[SEMICN];
                catToken();
                ch = get_ch();
                break;
            case ',':
                symbol = LexTypeNames[COMMA];
                catToken();
                ch = get_ch();
                break;
            case '(':
                symbol = LexTypeNames[LPARENT];
                catToken();
                ch = get_ch();
                break;
            case ')':
                symbol = LexTypeNames[RPARENT];
                catToken();
                ch = get_ch();
                break;
            case '[':
                symbol = LexTypeNames[LBRACK];
                catToken();
                ch = get_ch();
                break;
            case ']':
                symbol = LexTypeNames[RBRACK];
                catToken();
                ch = get_ch();
                break;
            case '{':
                symbol = LexTypeNames[LBRACE];
                catToken();
                ch = get_ch();
                break;
            case '}':
                symbol = LexTypeNames[RBRACE];
                catToken();
                ch = get_ch();
                break;
            case '"':
                catToken();
                ch = get_ch();
                while (ch != '"') {
                    catToken();
                    ch = get_ch();
                }
                catToken();
                symbol = LexTypeNames[STRCON];
                ch = get_ch();
                break;
            case '\'':
                catToken();
                ch = get_ch();
                catToken();
                if (ch == '\\') {
                    ch = get_ch();
                    catToken();
                }
                ch = get_ch();
                catToken();
                symbol = LexTypeNames[CHRCON];
                ch = get_ch();
                break;
            default:
                break;
        }
    }
    return true;
}

// 获取当前 token 值
string Lexer::getToken() const {
    return token;
}

// 获取当前的符号类型
string Lexer::getLexType() const {
    return symbol;
}