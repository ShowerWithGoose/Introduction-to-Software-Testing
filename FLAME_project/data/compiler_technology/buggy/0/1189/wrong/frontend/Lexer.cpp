#include "Lexer.h"

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

Lexer::Lexer(const string &fileText) {
    this->fileText = fileText;
    this->Char = '\0';
    this->LastChar = '\0';
    this->Token = "";
    this->symbol = IDENFR;
    this->lineNum = 1;
    this->curPos = 0;
    this->reserves = {
        {"main", MAINTK},
        {"const", CONSTTK},
        {"int", INTTK},
        {"char", CHARTK},
        {"break", BREAKTK},
        {"continue", CONTINUETK},
        {"if", IFTK},
        {"else", ELSETK},
        {"for", FORTK},
        {"getint", GETINTTK},
        {"getchar", GETCHARTK},
        {"printf", PRINTFTK},
        {"return", RETURNTK},
        {"void", VOIDTK}
    };
    this->typeToString = {
        {IDENFR, "IDENFR"},
        {INTCON, "INTCON"},
        {STRCON, "STRCON"},
        {CHRCON, "CHRCON"},
        {MAINTK, "MAINTK"},
        {CONSTTK, "CONSTTK"},
        {INTTK, "INTTK"},
        {CHARTK, "CHARTK"},
        {BREAKTK, "BREAKTK"},
        {CONTINUETK, "CONTINUETK"},
        {IFTK, "IFTK"},
        {ELSETK, "ELSETK"},
        {FORTK, "FORTK"},
        {GETINTTK, "GETINTTK"},
        {GETCHARTK, "GETCHARTK"},
        {PRINTFTK, "PRINTFTK"},
        {RETURNTK, "RETURNTK"},
        {VOIDTK, "VOIDTK"},
        {NOT, "NOT"},
        {AND, "AND"},
        {OR, "OR"},
        {PLUS, "PLUS"},
        {MINU, "MINU"},
        {MULT, "MULT"},
        {DIV, "DIV"},
        {MOD, "MOD"},
        {LSS, "LSS"},
        {LEQ, "LEQ"},
        {GRE, "GRE"},
        {GEQ, "GEQ"},
        {EQL, "EQL"},
        {NEQ, "NEQ"},
        {ASSIGN, "ASSIGN"},
        {SEMICN, "SEMICN"},
        {COMMA, "COMMA"},
        {LPARENT, "LPARENT"},
        {RPARENT, "RPARENT"},
        {LBRACK, "LBRACK"},
        {RBRACK, "RBRACK"},
        {LBRACE, "LBRACE"},
        {RBRACE, "RBRACE"}
    };
}

int Lexer::isReserve() {
    if (this->reserves.find(this->Token) != this->reserves.end()) {
        return this->reserves[this->Token];
    }
    return 0;
}


void Lexer::lexicalAnalysis() {
    vector<pair<TokenType, string> > result;
    vector<int> error;
    bool right = true;
    while (curPos < fileText.size()) {
        int code = getsym();
        if (code == 0) {
            continue;
        }
        if (code == -1) {
            error.push_back(lineNum);
            right = false;
        } else {
            result.emplace_back(symbol, Token);
        }
    }
    if (right) {
        ofstream out("lexer.txt");
        for (auto &i: result) {
            out << this->typeToString[i.first] << " " << i.second << endl;
        }
    } else {
        ofstream err("error.txt");
        for (int i: error) {
            err << i << " a" << endl;
        }
    }
}

int Lexer::getsym() {
    clearToken();
    getChar();
    while (this->Char == ' ' || this->Char == '\n' || this->Char == '\t') {
        if (this->Char == '\n') {
            lineNum++;
        }
        getChar();
    }
    if (this->Char == '\0') {
        return 0;
    }
    catToken();
    if (isLetter() || this->Char == '_') {
        getChar();
        while (isLetter() || isDigit() || this->Char == '_') {
            catToken();
            getChar();
        }
        retract();
        if (int resultValue = isReserve(); resultValue == 0) {
            // 标识符
            symbol = IDENFR;
        } else {
            symbol = static_cast<TokenType>(resultValue);
        }
    } else if (isDigit()) {
        getChar();
        while (isDigit()) {
            catToken();
            getChar();
        }
        retract();
        symbol = INTCON;
    } else if (this->Char == '\"') {
        // 是双引号
        getChar();
        while (this->Char != '\"') {
            catToken();
            getChar();
        }
        catToken();
        symbol = STRCON;
    } else if (this->Char == '!') {
        getChar();
        if (this->Char == '=') {
            catToken();
            symbol = NEQ;
        } else {
            retract();
            symbol = NOT;
        }
    } else if (this->Char == '&') {
        getChar();
        if (this->Char == '&') {
            catToken();
            symbol = AND;
        } else {
            retract();
            return -1;
        }
    } else if (this->Char == '|') {
        getChar();
        if (this->Char == '|') {
            catToken();
            symbol = OR;
        } else {
            retract();
            return -1;
        }
    } else if (this->Char == '+') symbol = PLUS;
    else if (this->Char == '-') symbol = MINU;
    else if (this->Char == '*') symbol = MULT;
    else if (this->Char == '%') symbol = MOD;
    else if (this->Char == '<') {
        getChar();
        if (this->Char == '=') {
            catToken();
            symbol = LEQ;
        } else {
            retract();
            symbol = LSS;
        }
    } else if (this->Char == '>') {
        getChar();
        if (this->Char == '=') {
            catToken();
            symbol = GEQ;
        } else {
            retract();
            symbol = GRE;
        }
    } else if (this->Char == '=') {
        getChar();
        if (this->Char == '=') {
            catToken();
            symbol = EQL;
        } else {
            retract();
            symbol = ASSIGN;
        }
    } else if (this->Char == ';') symbol = SEMICN;
    else if (this->Char == ',') symbol = COMMA;
    else if (this->Char == '(') symbol = LPARENT;
    else if (this->Char == ')') symbol = RPARENT;
    else if (this->Char == '[') symbol = LBRACK;
    else if (this->Char == ']') symbol = RBRACK;
    else if (this->Char == '{') symbol = LBRACE;
    else if (this->Char == '}') symbol = RBRACE;
    else if (this->Char == '/') {
        getChar();
        if (this->Char == '/') {
            getChar();
            while (this->Char != '\n') {
                getChar();
            }
            lineNum++;
            return 0;
        } else if (this->Char == '*') {
            getChar();
            while (curPos < fileText.length()) {
                while (this->Char != '*') {
                    if (this->Char == '\n') lineNum++;
                    getChar();
                }
                while (this->Char == '*') {
                    getChar();
                }
                if (this->Char == '/') {
                    return 0;
                }
            }
            return 0;
        } else {
            retract();
            symbol = DIV;
        }
    } else if (this->Char == '\'') {
        getChar();
        if (this->Char == '\\') {
            catToken();
            getChar();
            catToken();
        } else {
            catToken();
        }
        getChar();
        if (this->Char == '\'') {
            catToken();
            symbol = CHRCON;
        } else {
            retract();
            return -1;
        }
    } else {
        return -1;
    }
    return 1;
}

void Lexer::clearToken() {
    this->Token = "";
}

void Lexer::getChar() {
    if (curPos < fileText.size()) {
        this->LastChar = this->Char;
        this->Char = fileText[curPos];
        this->curPos++;
    } else {
        this->Char = '\0';
    }
}

void Lexer::catToken() {
    this->Token += this->Char;
}

bool Lexer::isLetter() const {
    return isalpha(this->Char);
}

bool Lexer::isDigit() const {
    return isdigit(this->Char);
}

void Lexer::retract() {
    this->curPos--;
    this->Char = LastChar;
}
