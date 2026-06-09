#ifndef COMPILER_EXP_H
#define COMPILER_EXP_H

#include <utility>

#include "vector"
#include "string"

using namespace std;

class Exp {
public:
    // 构造方法
    Exp(vector<vector<pair<string, string>>> words,
        vector<pair<string, string>> symbols);

    // 获取 words
    [[nodiscard]] const vector<vector<pair<string, string>>> &getWords() const;

    // 获取 symbols
    [[nodiscard]] const vector<pair<string, string>> &getSymbols() const;

private:
    vector<vector<pair<string, string>>> words;
    vector<pair<string, string>> symbols;
};


#endif //COMPILER_EXP_H
