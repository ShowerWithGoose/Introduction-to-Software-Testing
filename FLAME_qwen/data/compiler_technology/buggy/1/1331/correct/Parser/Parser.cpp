//
// Created by  on 2024/10/2.
//

#include "Parser.h"
#include "LexType.h"
#include "AST.h"
#include "iostream"
#include "Error.h"
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

Parser::Parser(const vector<pair<string, string>> &lexer_words, const vector<int> &lines) {
    for (auto &lexer_word: lexer_words) {
        this->lexer_words.push_back(lexer_word);
    }
    for (auto &line: lines) {
        this->lines.push_back(line);
    }
    index = 0;
    output.open("./parser.txt");
    output.flush();
    output.close();
    analyseCompUnit();
}

void Parser::getWord(AST &ast) {
    current_word = getNextWord();
    AST c(current_word.first, lines[index], current_word.second);
    ast.children.push_back(c);
    parser_words.emplace_back(current_word.first + " " + current_word.second);
    index++;
}

void Parser::getWordWithoutPush() {
    current_word = getNextWord();
    index++;
}

pair<string, string> Parser::getNextWord() {
    return lexer_words[index];
}

pair<string, string> Parser::getNext2Word() {
    return lexer_words[index + 1];
}

pair<string, string> Parser::getNext3Word() {
    return lexer_words[index + 2];
}

AST Parser::analyseCompUnit() {
    AST ast("<CompUnit>", lines[index], "");
    AST c{};
    pair<string, string> word = getNextWord();
    while (word.first == "CONSTTK" ||
           (word.first == "INTTK" && getNext2Word().first == "IDENFR" && getNext3Word().first != "LPARENT") ||
           word.first == "CHARTK" && getNext2Word().first == "IDENFR" && getNext3Word().first != "LPARENT") {
        c = analyseDecl();
        ast.children.push_back(c);
        word = getNextWord();
    }
    while ((word.first == "INTTK" && getNext2Word().first == "IDENFR" && getNext3Word().first == "LPARENT") ||
           (word.first == "CHARTK" && getNext2Word().first == "IDENFR" && getNext3Word().first == "LPARENT") ||
           word.first == "VOIDTK") {
        c = analyseFuncDef();
        ast.children.push_back(c);
        word = getNextWord();
    }
    if (word.first == "INTTK" && getNext2Word().first == "MAINTK") {
        c = analyseMainFuncDef();
        ast.children.push_back(c);
    }
    parser_words.emplace_back("<CompUnit>");
    postOrderTraversal(ast, 0);
    return ast;
}

AST Parser::analyseDecl() {
    AST ast("<Decl>", lines[index], "");
    AST c{};
    pair<string, string> word = getNextWord();
    if (word.first == "CONSTTK") {
        c = analyseConstDecl();
        ast.children.push_back(c);
    } else if (word.first == "INTTK" || word.first == "CHARTK") {
        c = analyseVarDecl();
        ast.children.push_back(c);
    }
    return ast;
}

AST Parser::analyseFuncDef() {
    AST ast("<FuncDef>", lines[index], "");
    AST c{};
    c = analyseFuncType();
    ast.children.push_back(c);
    getWord(ast);//Ident
    if (current_word.first == "IDENFR") {
        getWord(ast);//'('
        if (current_word.first == "LPARENT") {
            pair<string, string> word = getNextWord();
            if (word.first != "RPARENT") {
                if (word.first == "LBRACE") {
                    Error::getInstance().error('j', lines[index - 1]);
                } else {
                    c = analyseFuncFParams();
                    ast.children.push_back(c);
                    if (getNextWord().first == "RPARENT")
                        getWord(ast);//')'
                    else
                        Error::getInstance().error('j', lines[index - 1]);
                }
            } else
                getWord(ast);//')'
        }
    }
    c = analyseBlock();
    ast.children.push_back(c);
    parser_words.emplace_back("<FuncDef>");
    return ast;
}

AST Parser::analyseFuncFParams() {
    AST ast("<FuncFParams>", lines[index], "");
    AST c{};
    c = analyseFuncFParam();
    ast.children.push_back(c);
    pair<string, string> word = getNextWord();
    while (word.first == "COMMA") {
        getWord(ast);//,
        c = analyseFuncFParam();
        ast.children.push_back(c);
        word = getNextWord();
    }
    parser_words.emplace_back("<FuncFParams>");
    return ast;
}

AST Parser::analyseFuncFParam() {
    AST ast("<FuncFParam>", lines[index], "");
    AST c{};
    c = analyseBType();
    ast.children.push_back(c);
//    getWord(ast);//int or char
    getWord(ast);//Ident
    pair<string, string> word = getNextWord();
    if (word.first == "LBRACK") {
        getWord(ast);//[
        if (getNextWord().first != "RBRACK")
            Error::getInstance().error('k', lines[index - 1]);
        else
            getWord(ast);//]
    }
    parser_words.emplace_back("<FuncFParam>");
    return ast;
}

AST Parser::analyseFuncType() {
    AST ast("<FuncType>", lines[index], "");
    getWord(ast);//int or char or void
    parser_words.emplace_back("<FuncType>");
    return ast;
}

AST Parser::analyseBlock() {
    AST ast("<Block>", lines[index], "");
    AST c{};
    getWord(ast);//{
    pair<string, string> word = getNextWord();
    while (word.first != "RBRACE") {
        c = analyseBlockItem();
        ast.children.push_back(c);
        word = getNextWord();
    }
    getWord(ast);//}
    parser_words.emplace_back("<Block>");
    return ast;
}

AST Parser::analyseBlockItem() {
    AST ast("<BlockItem>", lines[index], "");
    AST c{};
    pair<string, string> word = getNextWord();
    if (word.first == "CONSTTK" ||
        (word.first == "INTTK" && getNext2Word().first == "IDENFR" && getNext3Word().first != "LPARENT") ||
        word.first == "CHARTK" && getNext2Word().first == "IDENFR" && getNext3Word().first != "LPARENT") {
        c = analyseDecl();
        ast.children.push_back(c);
    } else if (isStmtType(word.first)) {
        c = analyseStmt();
        ast.children.push_back(c);
    }
    return ast;
}

AST Parser::analyseMainFuncDef() {
    AST ast("<MainFuncDef>", lines[index], "");
    AST c{};
    getWord(ast);//int
    getWord(ast);//main
    getWord(ast);//'('
    if (getNextWord().first != "RPARENT")
        Error::getInstance().error('j', lines[index - 1]);
    else
        getWord(ast);
    c = analyseBlock();
    ast.children.push_back(c);
    parser_words.emplace_back("<MainFuncDef>");
    return ast;
}

AST Parser::analyseConstDecl() {
    AST ast("<ConstDecl>", lines[index], "");
    AST c{};
    getWord(ast);//const
    c = analyseBType();
    ast.children.push_back(c);
    c = analyseConstDef();
    ast.children.push_back(c);
    pair<string, string> word = getNextWord();
    while (word.first == "COMMA") {
        getWord(ast);
        c = analyseConstDef();
        ast.children.push_back(c);
        word = getNextWord();
    }
    if (getNextWord().first != "SEMICN") {
        Error::getInstance().error('i', lines[index - 1]);
    } else
        getWord(ast);//;
    parser_words.emplace_back("<ConstDecl>");
    return ast;
}

AST Parser::analyseVarDecl() {
    AST ast("<VarDecl>", lines[index], "");
    AST c{};
//    getWord(ast);//int or char
    c = analyseBType();
    ast.children.push_back(c);
    c = analyseVarDef();
    ast.children.push_back(c);
    pair<string, string> word = getNextWord();
    while (word.first == "COMMA") {
        getWord(ast);
        c = analyseVarDef();
        ast.children.push_back(c);
        word = getNextWord();
    }
    if (getNextWord().first != "SEMICN") {
        Error::getInstance().error('i', lines[index - 1]);
    } else
        getWord(ast);//;
    parser_words.emplace_back("<VarDecl>");
    return ast;
}

AST Parser::analyseBType() {
    AST ast("<BType>", lines[index], "");
    getWord(ast);//int or char
    return ast;
}

AST Parser::analyseConstDef() {
    AST ast("<ConstDef>", lines[index], "");
    AST c{};
    getWord(ast);//indent
    pair<string, string> word = getNextWord();
    if (word.first == "LBRACK") {
        getWord(ast);//[
        c = analyseConstExp(getExp());
        ast.children.push_back(c);
        if (getNextWord().first != "RBRACK")
            Error::getInstance().error('k', lines[index - 1]);
        else
            getWord(ast);
    }
    getWord(ast);//=
    c = analyseConstInitVal();
    ast.children.push_back(c);
    parser_words.emplace_back("<ConstDef>");
    return ast;
}

AST Parser::analyseVarDef() {
    AST ast("<VarDef>", lines[index], "");
    AST c{};
    getWord(ast);//indent
    pair<string, string> word = getNextWord();
    if (word.first == "LBRACK") {
        getWord(ast);//[
        c = analyseConstExp(getExp());
        ast.children.push_back(c);
        if (getNextWord().first != "RBRACK")
            Error::getInstance().error('k', lines[index - 1]);
        else
            getWord(ast);//]
    }
    if (getNextWord().first == "ASSIGN") {
        getWord(ast);//=
        c = analyseInitVal();
        ast.children.push_back(c);
    }
    parser_words.emplace_back("<VarDef>");
    return ast;
}

AST Parser::analyseConstExp(const vector<pair<string, string>> &exp) {
    AST ast("<ConstExp>", lines[index], "");
    AST c{};
    c = analyseAddExp(exp);
    ast.children.push_back(c);
    parser_words.emplace_back("<ConstExp>");
    return ast;
}

AST Parser::analyseConstInitVal() {
    AST ast("<ConstInitVal>", lines[index], "");
    AST c{};
    pair<string, string> word = getNextWord();
    if (word.first == "LBRACE") {//遇到左大括号
        getWord(ast);//'{'
        word = getNextWord();
        if (word.first != "RBRACE") {
            c = analyseConstExp(getExp());
            ast.children.push_back(c);
            pair<string, string> word2 = getNextWord();
            while (word2.first == "COMMA") {
                getWord(ast);//,
                c = analyseConstExp(getExp());
                ast.children.push_back(c);
                word2 = getNextWord();
            }
        }
        getWord(ast);//'}'
    } else if (word.first == "STRCON") {
        getWord(ast);
    } else {
        c = analyseConstExp(getExp());
        ast.children.push_back(c);
    }
    parser_words.emplace_back("<ConstInitVal>");
    return ast;
}

AST Parser::analyseInitVal() {
    AST ast("<InitVal>", lines[index], "");
    AST c{};
    pair<string, string> word = getNextWord();
    if (word.first == "LBRACE") {//遇到左大括号
        getWord(ast);//'{'
        word = getNextWord();
        if (word.first != "RBRACE") {//空数组
            c = analyseExp(getExp());
            ast.children.push_back(c);
            pair<string, string> word2 = getNextWord();
            while (word2.first == "COMMA") {
                getWord(ast);//,
                c = analyseExp(getExp());
                ast.children.push_back(c);
                word2 = getNextWord();
            }
        }
        getWord(ast);//'}'
    } else if (word.first == "STRCON") {
        getWord(ast);
    } else {
        c = analyseExp(getExp());
        ast.children.push_back(c);
    }
    parser_words.emplace_back("<InitVal>");
    return ast;
}

AST Parser::analyseExp(const vector<pair<string, string>> &exp) {
    AST ast("<Exp>", lines[index], "");
    AST c{};
    c = analyseAddExp(exp);
    ast.children.push_back(c);
    parser_words.emplace_back("<Exp>");
    return ast;
}

AST Parser::analyseAddExp(const vector<pair<string, string>> &exp) {
    AST ast("<AddExp>", lines[index], "");
    AST m{};
    vector<string> symbols = {"PLUS", "MINU"};
    Exp exps = divideExp(exp, symbols);
    int i = 0;
    for (auto &item: exps.getWords()) {
        m = analyseMulExp(item);
        ast.children.push_back(m);
        parser_words.emplace_back("<AddExp>");
        if (i < exps.getSymbols().size()) {
            // 符号
            AST op(exps.getSymbols()[i].first, lines[index], exps.getSymbols()[i].second);
            AST a("<AddExp>", lines[index], "");
            a.children.push_back(ast);
            a.children.push_back(op);
            ast = a;
            parser_words.emplace_back(exps.getSymbols()[i].first + " " + exps.getSymbols()[i].second);
            i++;
        }
    }
    return ast;
}

AST Parser::analyseMulExp(const vector<pair<string, string>> &exp) {
    AST ast("<MulExp>", lines[index], "");
    AST u{};
    vector<string> symbols = {"MULT", "DIV", "MOD"};
    Exp exps = divideExp(exp, symbols);
    int i = 0;
    for (auto &item: exps.getWords()) {
        u = analyseUnaryExp(item);
        ast.children.push_back(u);
        parser_words.emplace_back("<MulExp>");
        if (i < exps.getSymbols().size()) {
            // 符号
            AST op(exps.getSymbols()[i].first, lines[index], exps.getSymbols()[i].second);
            AST m("<MulExp>", lines[index], "");
            m.children.push_back(ast);
            m.children.push_back(op);
            ast = m;
            parser_words.emplace_back(exps.getSymbols()[i].first + " " + exps.getSymbols()[i].second);
            i++;
        }
    }
    return ast;
}

AST Parser::analyseUnaryExp(const vector<pair<string, string>> &exp) {
    AST ast("<UnaryExp>", lines[index], "");
    AST c{};
    pair<string, string> word = exp[0];
    if (exp.size() == 1) {
        c = analysePrimaryExp(exp);
        ast.children.push_back(c);
    } else {
        pair<string, string> word2 = exp[1];
        if (word.first == "PLUS" || word.first == "MINU" || word.first == "NOT") {
            // 一元表达式
            c = analyseUnaryOp(exp[0]);
            ast.children.push_back(c);
            vector<pair<string, string>> new_exp;
            for (int i = 1; i < exp.size(); ++i) {
                new_exp.emplace_back(exp[i]);
            }
            c = analyseUnaryExp(new_exp);
//            for (auto &item: c.children) {
//                cout << item.type << endl;
//            }
            ast.children.push_back(c);
        } else if (word.first == "IDENFR" && word2.first == "LPARENT") {
            AST c1(word.first, lines[index], word.second);
            AST c2(word2.first, lines[index], word2.second);
            ast.children.push_back(c1);
            ast.children.push_back(c2);
            parser_words.emplace_back(word.first + " " + word.second);//IDENFR
            parser_words.emplace_back(word2.first + " " + word2.second);//(
            vector<pair<string, string>> new_exp;
            pair<string, string> word3 = exp[exp.size() - 1];
            if (word3.first != "RPARENT") {
                Error::getInstance().error('j', lines[index - 1]);
                for (int i = 2; i < exp.size(); ++i) {
                    new_exp.emplace_back(exp[i]);
                }
                if (!new_exp.empty()) {
                    c = analyseFuncRParams(new_exp);
                    ast.children.push_back(c);
                }
            } else {
                for (int i = 2; i < exp.size() - 1; ++i) {
                    new_exp.emplace_back(exp[i]);
                }
                if (!new_exp.empty()) {
                    c = analyseFuncRParams(new_exp);
                    ast.children.push_back(c);
                }
                AST c3(word3.first, lines[index], word3.second);
                ast.children.push_back(c3);
                parser_words.emplace_back(word3.first + " " + word3.second);//)
            }
        } else {
            c = analysePrimaryExp(exp);
            ast.children.push_back(c);
        }
    }
    parser_words.emplace_back("<UnaryExp>");
//    for (auto &item: ast.children) {
//        cout << item.type << endl;
//    }
    return ast;
}

AST Parser::analyseFuncRParams(const vector<pair<string, string>> &exp) {
    AST ast("<FuncRParams>", lines[index], "");
    AST c{};
    vector<string> symbols = {"COMMA"};
    Exp exps = divideExp(exp, symbols);
    int i = 0;
    for (auto &item: exps.getWords()) {
        c = analyseExp(item);
        ast.children.push_back(c);
        if (i < exps.getSymbols().size()) {
            // 符号
            AST op(exps.getSymbols()[i].first, lines[index], exps.getSymbols()[i].second);
            ast.children.push_back(op);
            parser_words.emplace_back(exps.getSymbols()[i].first + " " + exps.getSymbols()[i].second);
            i++;
        }
    }
    parser_words.emplace_back("<FuncRParams>");
    return ast;
}

AST Parser::analyseUnaryOp(const pair<string, string> &word) {
    AST ast("<UnaryOp>", lines[index], "");
    AST a(word.first, lines[index], word.second);
    ast.children.push_back(a);
    parser_words.emplace_back(word.first + " " + word.second);
    parser_words.emplace_back("<UnaryOp>");
    return ast;
}

AST Parser::analyseLAndExp(const vector<pair<std::string, std::string>> &exp) {
    AST ast("<LAndExp>", lines[index], "");
    AST e{};
    vector<string> symbols = {"AND"};
    Exp exps = divideExp(exp, symbols);
    int i = 0;
    for (auto &item: exps.getWords()) {
        e = analyseEqExp(item);
        ast.children.push_back(e);
        parser_words.emplace_back("<LAndExp>");
        if (i < exps.getSymbols().size()) {
            // 符号
            AST op(exps.getSymbols()[i].first, lines[index], exps.getSymbols()[i].second);
            AST a("<LAndExp>", lines[index], "");
            a.children.push_back(ast);
            a.children.push_back(op);
            ast = a;
            parser_words.emplace_back(exps.getSymbols()[i].first + " " + exps.getSymbols()[i].second);
            i++;
        }
    }
    return ast;
}

AST Parser::analyseLOrExp(const vector<pair<string, string>> &exp) {
    AST ast("<LOrExp>", lines[index], "");
    AST l{};
    vector<string> symbols = {"OR"};
    Exp exps = divideExp(exp, symbols);
    int i = 0;
    for (auto &item: exps.getWords()) {
        l = analyseLAndExp(item);
        ast.children.push_back(l);
        parser_words.emplace_back("<LOrExp>");
        if (i < exps.getSymbols().size()) {
            // 符号
            AST op(exps.getSymbols()[i].first, lines[index], exps.getSymbols()[i].second);
            AST a("<LOrExp>", lines[index], "");
            a.children.push_back(ast);
            a.children.push_back(op);
            ast = a;
            parser_words.emplace_back(exps.getSymbols()[i].first + " " + exps.getSymbols()[i].second);
            i++;
        }
    }
    return ast;
}

AST Parser::analysePrimaryExp(const vector<pair<string, string>> &exp) {
    AST ast("<PrimaryExp>", lines[index], "");
    AST c{};
    pair<string, string> word = exp[0];
    if (word.first == "LPARENT") {
        AST c1(word.first, lines[index], word.second);
        ast.children.push_back(c1);
        parser_words.emplace_back(word.first + " " + word.second);//'('
        vector<pair<string, string>> new_exp;
        pair<string, string> word2 = exp[exp.size() - 1];
        if (word2.first != "RPARENT") {
            Error::getInstance().error('j', lines[index - 1]);
            for (int i = 1; i < exp.size(); ++i) {
                new_exp.emplace_back(exp[i]);
            }
            c = analyseExp(new_exp);
            ast.children.push_back(c);
        } else {
            for (int i = 1; i < exp.size() - 1; ++i) {
                new_exp.emplace_back(exp[i]);
            }
            c = analyseExp(new_exp);
            ast.children.push_back(c);
            AST c2(word2.first, lines[index], word2.second);
            ast.children.push_back(c2);
            parser_words.emplace_back(word2.first + " " + word2.second);//')'
        }
    } else if (word.first == "IDENFR") {
        c = analyseLVal(exp);
        ast.children.push_back(c);
    } else if (word.first == "INTCON") {
        c = analyseNumber(word);
        ast.children.push_back(c);
    } else if (word.first == "CHRCON") {
        c = analyseCharacter(word);
        ast.children.push_back(c);
    }
    parser_words.emplace_back("<PrimaryExp>");
    return ast;
}

AST Parser::analyseRelExp(const vector<pair<string, string>> &exp) {
    AST ast("<RelExp>", lines[index], "");
    AST a{};
    vector<string> symbols = {"LSS", "LEQ", "GRE", "GEQ"};
    Exp exps = divideExp(exp, symbols);
    int i = 0;
    for (auto &item: exps.getWords()) {
        a = analyseAddExp(item);
        ast.children.push_back(a);
        parser_words.emplace_back("<RelExp>");
        if (i < exps.getSymbols().size()) {
            // 符号
            AST op(exps.getSymbols()[i].first, lines[index], exps.getSymbols()[i].second);
            AST a_("<RelExp>", lines[index], "");
            a_.children.push_back(ast);
            a_.children.push_back(op);
            ast = a_;
            parser_words.emplace_back(exps.getSymbols()[i].first + " " + exps.getSymbols()[i].second);
            i++;
        }
    }
    return ast;
}

AST Parser::analyseEqExp(const vector<pair<string, string>> &exp) {
    AST ast("<EqExp>", lines[index], "");
    AST r{};
    vector<string> symbols = {"EQL", "NEQ"};
    Exp exps = divideExp(exp, symbols);
    int i = 0;
    for (auto &item: exps.getWords()) {
        r = analyseRelExp(item);
        ast.children.push_back(r);
        parser_words.emplace_back("<EqExp>");
        if (i < exps.getSymbols().size()) {
            // 符号
            AST op(exps.getSymbols()[i].first, lines[index], exps.getSymbols()[i].second);
            AST a("<EqExp>", lines[index], "");
            a.children.push_back(ast);
            a.children.push_back(op);
            ast = a;
            parser_words.emplace_back(exps.getSymbols()[i].first + " " + exps.getSymbols()[i].second);
            i++;
        }
    }
    return ast;
}

AST Parser::analyseStmt() {
    int current_line = lines[index];
    AST ast("<Stmt>", lines[index], "");
    AST c{};
    pair<string, string> word = getNextWord();
    if (word.first == "IDENFR") {
        vector<pair<string, string>> exp = getExp();//区分LVal和Exp
        if (getNextWord().first != "SEMICN" && current_line == lines[index]) {
            c = analyseLVal(exp);
            ast.children.push_back(c);
            getWord(ast);//=
            if (getNextWord().first == "GETINTTK") {
                getWord(ast);//getint()
                getWord(ast);//(
                if (getNextWord().first != "RPARENT")
                    Error::getInstance().error('j', lines[index - 1]);
                else
                    getWord(ast);//)
                if (getNextWord().first != "SEMICN")
                    Error::getInstance().error('i', lines[index - 1]);
                else
                    getWord(ast);//;
            } else if (getNextWord().first == "GETCHARTK") {
                getWord(ast);//getchar()
                getWord(ast);//(
                if (getNextWord().first != "RPARENT")
                    Error::getInstance().error('j', lines[index - 1]);
                else
                    getWord(ast);//)
                if (getNextWord().first != "SEMICN")
                    Error::getInstance().error('i', lines[index - 1]);
                else
                    getWord(ast);//;
            } else {
                c = analyseExp(getExp());
                ast.children.push_back(c);
                if (getNextWord().first != "SEMICN")
                    Error::getInstance().error('i', lines[index - 1]);
                else
                    getWord(ast);//;
            }
        } else {
            c = analyseExp(exp);
            ast.children.push_back(c);
//            for (auto &item: c.children)
//                cout << item.type << endl;
            if (getNextWord().first != "SEMICN")
                Error::getInstance().error('i', lines[index - 1]);
            else
                getWord(ast);//;
        }
    } else if (isExpType(word.first)) {
        c = analyseExp(getExp());
        ast.children.push_back(c);
        if (getNextWord().first != "SEMICN")
            Error::getInstance().error('i', lines[index - 1]);
        else
            getWord(ast);//;
    } else if (word.first == "LBRACE") {
        c = analyseBlock();
        ast.children.push_back(c);
    } else if (word.first == "IFTK") {
        getWord(ast);//if
        getWord(ast);//(
        c = analyseCond();
        ast.children.push_back(c);
        if (getNextWord().first != "RPARENT")
            Error::getInstance().error('j', lines[index - 1]);
        else
            getWord(ast);//)
        c = analyseStmt();
        ast.children.push_back(c);
        pair<string, string> word2 = getNextWord();
        if (word2.first == "ELSETK") {
            getWord(ast);//else
            c = analyseStmt();
            ast.children.push_back(c);
        }
    } else if (word.first == "FORTK") {
        getWord(ast);//for
        getWord(ast);//(
        if (getNextWord().first != "SEMICN") {
            c = analyseForStmt();
            ast.children.push_back(c);
        }
        getWord(ast);//;
        if (getNextWord().first != "SEMICN") {
            c = analyseCond();
            ast.children.push_back(c);
        }
        getWord(ast);//;
        if (getNextWord().first != "RPARENT") {
            c = analyseForStmt();
            ast.children.push_back(c);
        }
        getWord(ast);//)
        c = analyseStmt();
        ast.children.push_back(c);
    } else if (word.first == "BREAKTK") {
        getWord(ast);//break;
        if (getNextWord().first != "SEMICN")
            Error::getInstance().error('i', lines[index - 1]);
        else
            getWord(ast);//;
    } else if (word.first == "CONTINUETK") {
        getWord(ast);//continue;
        if (getNextWord().first != "SEMICN")
            Error::getInstance().error('i', lines[index - 1]);
        else
            getWord(ast);//;
    } else if (word.first == "RETURNTK") {
        getWord(ast);//return;
        word = getNextWord();
        if (isExpType(word.first)) {
            c = analyseExp(getExp());
            ast.children.push_back(c);
        }
        if (getNextWord().first != "SEMICN")
            Error::getInstance().error('i', lines[index - 1]);
        else
            getWord(ast);//;
    } else if (word.first == "PRINTFTK") {
        getWord(ast);//printf
        getWord(ast);//(
        getWord(ast);//STRCON
        word = getNextWord();
        while (word.first == "COMMA") {
            getWord(ast);//,
            c = analyseExp(getExp());
            ast.children.push_back(c);
            word = getNextWord();
        }
        if (getNextWord().first != "RPARENT")
            Error::getInstance().error('j', lines[index - 1]);
        else
            getWord(ast);//)
        if (getNextWord().first != "SEMICN")
            Error::getInstance().error('i', lines[index - 1]);
        else
            getWord(ast);//;
    } else if (word.first == "SEMICN") {
        getWord(ast);//;
    }
    parser_words.emplace_back("<Stmt>");
    return ast;
}

AST Parser::analyseLVal(const vector<pair<string, string>> &exp) {
    AST ast("<LVal>", lines[index], "");
    AST c{};
    AST c1(exp[0].first, lines[index], exp[0].second);
    ast.children.push_back(c1);
    parser_words.emplace_back(exp[0].first + " " + exp[0].second);//存储indent
    if (exp.size() > 1 && exp[1].first == "LBRACK") {
        AST c2(exp[1].first, lines[index], exp[1].second);
        ast.children.push_back(c2);
        parser_words.emplace_back(exp[1].first + " " + exp[1].second);//存储[
        vector<pair<string, string>> exp2;
        if (exp[exp.size() - 1].first != "RBRACK") {
            Error::getInstance().error('k', lines[index - 1]);
            for (int i = 2; i < exp.size(); ++i) {
                exp2.emplace_back(exp[i]);
            }
            c = analyseExp(exp2);//存储表达式
            ast.children.push_back(c);
        } else {
            for (int i = 2; i < exp.size() - 1; ++i) {
                exp2.emplace_back(exp[i]);
            }
            c = analyseExp(exp2);//存储表达式
            ast.children.push_back(c);
            AST c3(exp[exp.size() - 1].first, lines[index], exp[exp.size() - 1].second);
            ast.children.push_back(c3);
            parser_words.emplace_back(exp[exp.size() - 1].first + " " + exp[exp.size() - 1].second);//存储]
        }
    }
    parser_words.emplace_back("<LVal>");
    return ast;
}

AST Parser::analyseCond() {
    AST ast("<Cond>", lines[index], "");
    AST c{};
    c = analyseLOrExp(getExp());
    ast.children.push_back(c);
    parser_words.emplace_back("<Cond>");
    return ast;
}

AST Parser::analyseForStmt() {
    AST ast("<ForStmt>", lines[index], "");
    AST c{};
    c = analyseLVal(getExp());
    ast.children.push_back(c);
    getWord(ast);//=
    c = analyseExp(getExp());
    ast.children.push_back(c);
    parser_words.emplace_back("<ForStmt>");
    return ast;
}

AST Parser::analyseNumber(const pair<string, string> &word) {
    AST ast("<Number>", lines[index], "");
    AST c(word.first, lines[index], word.second);
    ast.children.push_back(c);
    parser_words.emplace_back(word.first + " " + word.second);
    parser_words.emplace_back("<Number>");
    return ast;
}

AST Parser::analyseCharacter(const pair<string, string> &word) {
    AST ast("<Character>", lines[index], "");
    AST c(word.first, lines[index], word.second);
    ast.children.push_back(c);
    parser_words.emplace_back(word.first + " " + word.second);
    parser_words.emplace_back("<Character>");
    return ast;
}

vector<pair<string, string>> Parser::getExp() {
    vector<pair<string, string>> exp;
    bool inFunc = false;
    int func_index = 0;
    int parentheses_num = 0;
    int bracket_num = 0;
    pair<string, string> word = getNextWord();
    int current_line = lines[index];
    while (true) {
        if (word.first == "SEMICN" || word.first == "ASSIGN" || word.first == "LBRACE" || word.first == "RBRACE" ||
            (word.first == "COMMA" && !inFunc) || lines[index] != current_line)
            break;// 遇到分号、赋值符、左大括号,右大括号、非函数参数逗号，换行，则结束
        if (word.first == "IDENFR") {
            if (getNext2Word().first == "LPARENT") {
                inFunc = true;
            }
        }// 判断是否为函数调用
        if (word.first == "LPARENT") {
            parentheses_num++;// 记录左括号
            if (inFunc)
                func_index++;// 记录函数嵌套的层数
        }
        if (word.first == "RPARENT") {
            parentheses_num--;// 记录右括号
            if (inFunc) {
                func_index--;// 记录函数嵌套的层数
                if (func_index == 0)
                    inFunc = false;// 函数调用结束
            }
        }
        if (word.first == "LBRACK") {
            bracket_num++;// 记录左括号
        }
        if (word.first == "RBRACK") {
            bracket_num--;// 记录右括号
        }
        if (parentheses_num < 0) {
//            cout << index << endl;
            break;
        }
        if (bracket_num < 0) {
//            cout << "error" << endl;
            break;
        }
        getWordWithoutPush();
        exp.push_back(current_word);
        word = getNextWord();
    }
    return exp;
}

Exp Parser::divideExp(const vector<pair<string, string>> &exp, const vector<string> &symbol) {
    vector<vector<pair<string, string>>> exp_list;
    vector<pair<string, string>> exp1;
    vector<pair<string, string>> symbols;
    bool unaryFlag = false;// 排除一元操作符
    int parentheses_num = 0;// 记录小括号
    int bracket_num = 0;// 记录中括号
    for (const auto &word: exp) {
        if (word.first == "LPARENT")
            parentheses_num++;
        if (word.first == "RPARENT")
            parentheses_num--;
        if (word.first == "LBRACK")
            bracket_num++;
        if (word.first == "RBRACK")
            bracket_num--;
        if (std::find(symbol.begin(), symbol.end(), word.first) != symbol.end() && parentheses_num == 0 &&
            bracket_num == 0) {
            if (isUnaryType(word.first)) {
                if (!unaryFlag) {
                    // 是一元操作符
                    exp1.push_back(word);
                    continue;
                }
            }
            exp_list.push_back(exp1);
            symbols.push_back(word);
            exp1.clear();
        } else {
            exp1.push_back(word);
        }
        unaryFlag =
                word.first == "IDENFR" || word.first == "INTCON" || word.first == "CHRCON" || word.first == "RPARENT" ||
                word.first == "RBRACK";
    }
    exp_list.push_back(exp1);
    return {exp_list, symbols};
}

bool Parser::isStmtType(const string &type) {
    return type == "IDENFR"
           || type == "LBRACE"
           || type == "IFTK"
           || type == "ELSETK"
           || type == "FORTK"
           || type == "BREAKTK"
           || type == "CONTINUETK"
           || type == "RETURNTK"
           || type == "PRINTFTK"
           || type == "SEMICN"
           || isExpType(type);
}

bool Parser::isExpType(const string &type) {
    return type == "LPARENT"
           || type == "IDENFR"
           || type == "INTCON"
           || type == "CHRCON"
           || type == "NOT"
           || type == "PLUS"
           || type == "MINU";
}

bool Parser::isUnaryType(const string &type) {
    return type == "PLUS"
           || type == "MINU"
           || type == "NOT";
}

void Parser::outWords() {
    ofstream output;
    output.open("./parser.txt");
    if (output.is_open()) {
        for (auto const &i: parser_words) {
            output << i << endl;
        }
        output.close();  // 关闭文件
//    for (auto &parserWord: parser_words) {
//        cout << parserWord << endl;
//    }
    }
}

void Parser::postOrderTraversal(AST &astRoot, int depth) {
    for (AST &child: astRoot.children) {
        postOrderTraversal(child, depth + 1);
    }
    // 打印节点所有信息
//    cout << string(depth, '-') << "Node Type: " << astRoot.type << ", Line: " << astRoot.line << ", Token: "
//         << astRoot.token
//         << endl;
    output.open("./parser.txt", std::ios::app);
    if (!astRoot.token.empty()) {
        output << astRoot.type << " " << astRoot.token << endl;
    } else {
        if (astRoot.type != "<BlockItem>" && astRoot.type != "<Decl>" && astRoot.type != "<BType>")
            output << astRoot.type << endl;
    }
    output.close();
}