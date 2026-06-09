#include <iostream>
#include <fstream>
#include "error.h"
#include "token.h"
#include "lexer.h"

const std::unordered_map<std::string, Token::TokenType> Lexer::_keywords_table = {
    {"main" , Token::MAINTK},
    {"const" , Token::CONSTTK},
    {"int" , Token::INTTK},
    {"char" , Token::CHARTK},
    {"break" , Token::BREAKTK},
    {"continue" , Token::CONTINUETK},
    {"if" , Token::IFTK},
    {"else" , Token::ELSETK},
    {"for" , Token::FORTK},
    {"getint" , Token::GETINTTK},
    {"getchar" , Token::GETCHARTK},
    {"printf" , Token::PRINTFTK},
    {"return" , Token::RETURNTK},
    {"void" , Token::VOIDTK}
};

void Lexer::getToken(Token &token) {
    std::string content;
    char ch = _input.get();
    content.append(1, ch);
    if (isalpha(ch) || ch == '_') {
        ch = _input.get();
        while (isalnum(ch) || ch == '_') {
            content.append(1, ch);
            ch = _input.get();
        }
        _input.unget();
        const auto it = _keywords_table.find(content);
        const auto type = it == _keywords_table.end() ? Token::IDENFR : it->second;
        token = Token(type, content, _lineno);
    } else if (isdigit(ch)) {
        ch = _input.get();
        while (isdigit(ch)) {
            content.append(1, ch);
            ch = _input.get();
        }
        _input.unget();
        token = Token(Token::INTCON, content, _lineno);
    }
    else if (ch == '+') token = Token(Token::PLUS, content, _lineno);
    else if (ch == '-') token = Token(Token::MINU, content, _lineno);
    else if (ch == '*') token = Token(Token::MULT, content, _lineno);
    else if (ch == '%') token = Token(Token::MOD, content, _lineno);
    else if (ch == ';') token = Token(Token::SEMICN, content, _lineno);
    else if (ch == ',') token = Token(Token::COMMA, content, _lineno);
    else if (ch == '(') token = Token(Token::LPARENT, content, _lineno);
    else if (ch == ')') token = Token(Token::RPARENT, content, _lineno);
    else if (ch == '[') token = Token(Token::LBRACK, content, _lineno);
    else if (ch == ']') token = Token(Token::RBRACK, content, _lineno);
    else if (ch == '{') token = Token(Token::LBRACE, content, _lineno);
    else if (ch == '}') token = Token(Token::RBRACE, content, _lineno);
    else if (ch == '=') {
        ch = _input.get();
        if (ch == '=') {
            content.append(1, ch);
            token = Token(Token::EQL, content, _lineno);
        } else {
            _input.unget();
            token = Token(Token::ASSIGN, content, _lineno);
        }
    }
    else if (ch == '<') {
        ch = _input.get();
        if (ch == '=') {
            content.append(1, ch);
            token = Token(Token::LEQ, content, _lineno);
        } else {
            _input.unget();
            token = Token(Token::LSS, content, _lineno);
        }
    }
    else if (ch == '>') {
        ch = _input.get();
        if (ch == '=') {
            content.append(1, ch);
            token = Token(Token::GEQ, content, _lineno);
        } else {
            _input.unget();
            token = Token(Token::GRE, content, _lineno);
        }
    }
    else if (ch == '!') {
        ch = _input.get();
        if (ch == '=') {
            content.append(1, ch);
            token = Token(Token::NEQ, content, _lineno);
        } else {
            _input.unget();
            token = Token(Token::NOT, content, _lineno);
        }
    }
    else if (ch == '\"') {
        ch = _input.get();
        while (ch != '\"') {
            if (ch == '\\') {
                content.append(1, ch);
                ch = _input.get();
            }
            content.append(1, ch);
            ch = _input.get();
        }
        content.append(1, ch);
        token = Token(Token::STRCON, content, _lineno);
    }
    else if (ch == '\'') {
        ch = _input.get();
        if (ch == '\\') {
            content.append(1, ch);
            ch = _input.get();
        }
        content.append(1, ch);
        ch = _input.get();
        content.append(1, ch); //'
        token = Token(Token::CHRCON, content, _lineno);
    }
    else if (ch == '/') {
        ch = _input.get();
        if (ch == '*') {
            do {
                do {
                    ch = _input.get();
                } while (ch != '*');
                do {
                    ch = _input.get();
                    if (ch == '/') {
                        return getToken(token);
                    }// 处理完注释
                } while (ch == '*');
            } while (true);
        }
        if (ch == '/') {
            while (true) {
                ch = _input.get();
                if (ch == '\n' && ch != EOF) {
                    return getToken(token);
                }
            }
        }
        _input.unget();
        token = Token(Token::DIV, content, _lineno);
    }
    else if (ch == '&') {
        ch = _input.get();
        if (ch != '&') {
            _input.unget();
            token = Token(Token::ERROR, content, _lineno);
            ErrorReporter::error(_lineno, "a");
        }
        content.append(1, ch);
        token = Token(Token::AND, content, _lineno);
    }
    else if (ch == '|') {
        ch = _input.get();
        if (ch != '|') {
            _input.unget();
            token = Token(Token::ERROR, content, _lineno);
            ErrorReporter::error(_lineno, "a");
        }
        content.append(1, ch);
        token = Token(Token::OR, content, _lineno);
    }
    else if (ch == '\n') {
        _lineno++;
        return getToken(token);
    }
    else if (isblank(ch)) {
        return getToken(token);
    }
    else if (ch == EOF) {
        token = Token(Token::EOFTK, content, _lineno);
    }
    else {
        token = Token(Token::ERROR, content, _lineno);
        ErrorReporter::error(_lineno, "invalid char: \'" + content + "\'");
    }
}

int main() {
    std::ifstream infile("testfile.txt", std::ios::in);
    std::ofstream correctOut("lexer.txt", std::ios::out);
    std::ofstream errorOut("error.txt", std::ios::out);

    std::vector<std::string> lexerOutput;

    Lexer lexer(infile);
    Token token;

    lexer.getToken(token);
    while (token.type != Token::EOFTK) {
        lexerOutput.push_back(TokenType2Str(token.type) + " " + token.content);
        lexer.getToken(token);
    }

    if (ErrorReporter::get().has_error()) {
        ErrorReporter::get().print_error(errorOut);
    } else {
        for (const auto& str : lexerOutput) {
            correctOut << str << std::endl;
        }
    }

    infile.close();
    correctOut.close();
    errorOut.close();
}