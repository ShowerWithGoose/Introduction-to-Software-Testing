#ifndef COMPILER_LEXER_H
#define COMPILER_LEXER_H

#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <cctype>
#include <unordered_map>
#include "LexType.h"  // 假设 LexType.h 中定义了 LexType 枚举
#include "Error.h"

#define MAX_TOKEN_LEN 10000
using namespace std;

class Lexer {
public:
    // 获取单例实例
    static Lexer &getInstance(const string &file = "") {
        static Lexer instance(file);  // 使用局部静态变量确保只创建一个实例
        return instance;
    }

    // 删除拷贝构造函数和赋值操作符，以防止复制
    Lexer(const Lexer &) = delete;

    Lexer &operator=(const Lexer &) = delete;

    // 获取当前的单词值
    string getToken() const;

    // 获取当前的单词类型（LexType）
    string getLexType() const;

    // 处理下一个单词，返回是否成功
    bool next();

    int getLine() const;

private:
    // 构造函数，传入文件
    explicit Lexer(const string &file);

    // 清除当前 token
    void clearToken();

    // 追加字符到当前 token
    void catToken();

    // 关键字匹配
    LexType reserver();

    char get_ch();

    // 转换数字字符串为整数
    unsigned long long transNum();

    // 成员变量
    unordered_map<LexType, string> marchMap;  // 映射符号类型到字符串
    char ch{};// 当前读取的字符
    string token;// 存储当前单词
    unsigned long long num{};// 存储转换的数字
    string content; // 文件
    string symbol;// 当前识别出的单词类型
    int line = 1;// 当前行号
    size_t index = 0;//当前位置
};

#endif //COMPILER_LEXER_H
