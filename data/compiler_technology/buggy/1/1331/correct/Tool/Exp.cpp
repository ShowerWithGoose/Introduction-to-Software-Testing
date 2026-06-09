#include "Exp.h"

using namespace std;

// 构造方法
Exp::Exp(vector<vector<pair<string, string>>> words,
         vector<pair<string, string>> symbols)
        : words(std::move(words)), symbols(std::move(symbols)) {}

// 获取 words
[[nodiscard]] const vector<vector<pair<string, string>>> &Exp::getWords() const {
    return words;
}

// 获取 symbols
[[nodiscard]] const vector<pair<string, string>> &Exp::getSymbols() const {
    return symbols;
}