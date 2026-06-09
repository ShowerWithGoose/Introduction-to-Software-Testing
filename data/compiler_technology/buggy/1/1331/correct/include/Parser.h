#ifndef COMPILER_PARSER_H
#define COMPILER_PARSER_H

#include "Exp.h"
#include "AST.h"
#include <string>
#include <list>
#include <vector>
#include <fstream>

using namespace std;

class Parser {
public:
    static Parser &getInstance(const vector<pair<string, string>> &lexer_words = {}, const vector<int> &lines = {}) {
        static Parser instance(lexer_words, lines);  // 使用带参数的构造函数
        return instance;
    }

    // 删除拷贝构造函数和赋值操作符，以防止复制
    Parser(const Parser &) = delete;

    Parser &operator=(const Parser &) = delete;

    void outWords();

    AST root;

private:
    ofstream output;

    // 构造函数，传入文件
    explicit Parser(const vector<pair<string, string>> &lexer_words, const vector<int> &lines);

    vector<pair<string, string>> lexer_words;

    vector<string> parser_words;

    pair<string, string> current_word;

    vector<int> lines;

    size_t index;

    void getWord(AST &ast);

    void getWordWithoutPush();

    pair<string, string> getNextWord();// 获取下一个单词

    pair<string, string> getNext2Word();// 获取下两个单词

    pair<string, string> getNext3Word();// 获取下三个单词

    AST analyseCompUnit();// 分析CompUnit

    AST analyseDecl();// 分析Decl

    AST analyseFuncDef();// 分析FuncDef

    AST analyseMainFuncDef();

    AST analyseConstDecl();

    AST analyseVarDecl();

    AST analyseBType();

    AST analyseConstDef();

    AST analyseVarDef();

    AST analyseConstExp(const vector<pair<string, string>> &exp);

    vector<pair<string, string>> getExp();

    AST analyseConstInitVal();

    AST analyseInitVal();

    AST analyseExp(const vector<pair<string, string>> &exp);

    AST analyseAddExp(const vector<pair<string, string>> &vector);

    AST analyseFuncType();

    AST analyseFuncFParams();

    AST analyseBlock();

    AST analyseFuncFParam();

    static bool isStmtType(const string &str);

    static bool isExpType(const string &str);

    static bool isUnaryType(const string &str);

    AST analyseBlockItem();

    AST analyseStmt();

    AST analyseLVal(const vector<pair<string, string>> &exp);

    AST analyseCond();

    AST analyseForStmt();

    AST analyseLAndExp(const vector<pair<string, string>> &exp);

    AST analyseLOrExp(const vector<pair<string, string>> &vector);

    AST analyseMulExp(const vector<pair<string, string>> &exp);

    AST analyseUnaryExp(const vector<pair<string, string>> &exp);

    Exp divideExp(const vector<pair<string, string>> &exp, const vector<string> &symbol);

    AST analyseUnaryOp(const pair<string, string> &word);

    AST analyseFuncRParams(const vector<pair<string, string>> &exp);

    AST analysePrimaryExp(const vector<pair<string, string>> &exp);

    AST analyseRelExp(const vector<pair<string, string>> &exp);

    AST analyseEqExp(const vector<pair<string, string>> &exp);

    AST analyseNumber(const pair<string, string> &word);

    AST analyseCharacter(const pair<string, string> &word);

    void postOrderTraversal(AST &astRoot, int depth);
};


#endif //COMPILER_PARSER_H
