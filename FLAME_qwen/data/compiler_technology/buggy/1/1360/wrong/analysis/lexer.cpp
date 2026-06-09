#include "lexer.h"
#include "error/errorList.h"
#include <cctype>

Lexer::Lexer(const std::string &source) : source(source), position(0), line(1) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (position < source.size()) {
        skipWhitespace();
        if (position >= source.size()) break;

        char current = source[position];
        if (current == '/') {
            if (position + 1 < source.size() && source[position + 1] == '/') {
                skipLineComment();
            } else if (position + 1 < source.size() && source[position + 1] == '*') {
                skipBlockComment();
            } else {
                tokens.push_back(handleSpecialTokens());
            }
        } else if (isalpha(current) || current == '_') {
            tokens.push_back(identifier());
        } else if (isdigit(current)) {
            tokens.push_back(integer());
        } else if (current == '"') {
            tokens.push_back(stringLiteral());
        } else if (current == '\'') {
            tokens.push_back(charLiteral());
        } else {
            tokens.push_back(handleSpecialTokens());
        }
    }
    return tokens;
}

void Lexer::skipWhitespace() {
    while (position < source.size() && isspace(source[position])) {
        if (source[position] == '\n') {
            line++;
        }
        position++;
    }
}

void Lexer::skipLineComment() {
    while (position < source.size() && source[position] != '\n') {
        position++;
    }
}

void Lexer::skipBlockComment() {
    position += 2;
    while (position + 1 < source.size() && !(source[position] == '*' && source[position + 1] == '/')) {
        if (source[position] == '\n') {
            line++;
        }
        position++;
    }
    position += 2;
}

Token Lexer::identifier() {
    int start = position;
    while (position < source.size() && (isalnum(source[position]) || source[position] == '_')) {
        position++;
    }
    std::string id = source.substr(start, position - start);
    if (id == "const") return {CONSTTK, id,line};
    if (id == "char") return {CHARTK, id,line};
    if (id == "int") return {INTTK, id,line};
    if (id == "void") return {VOIDTK, id,line};
    if (id == "main") return {MAINTK, id,line};
    if (id == "for") return {FORTK, id,line};
    if (id == "break") return {BREAKTK, id,line};
    if (id == "continue") return {CONTINUETK, id,line};
    if (id == "if") return {IFTK, id,line};
    if (id == "getint") return {GETINTTK, id,line};
    if (id == "getchar") return {GETCHARTK, id,line};
    if (id == "printf") return {PRINTFTK, id,line};
    if (id == "return") return {RETURNTK, id,line};
    if (id == "else") return {ELSETK, id,line};
    return {IDENFR, id,line};
}

Token Lexer::integer() {
    int start = position;
    while (position < source.size() && isdigit(source[position])) {
        position++;
    }
    return {INTCON, source.substr(start, position - start),line};
}

Token Lexer::stringLiteral() {
    int start = position;
    position++;
    while (position < source.size() && (source[position] != '"')) {
        position++;
    }
    if (position < source.size()) {
        position++; // Skip the closing quote
        return {STRCON, source.substr(start , position - start),line}; // Exclude quotes
    }
    return {ERROR, ""};
}

Token Lexer::charLiteral() {
    int start = position;
    position++;
    if(source[position]=='\\'&&source[position+1]=='0')
    {
        position += 3;
        return {CHRCON,"'\\0'",line};
    }
    if(source[position]=='\\'&&source[position+1]=='\'')
    {
        position += 3;
        return {CHRCON,"'\\\''",line};
    }
    if(source[position]=='\\'&&source[position+1]=='n')
    {
        position += 3;
        return {CHRCON,"'\\n'",line};
    }
    if(source[position]=='\\'&&source[position+1]=='t')
    {
        position += 3;
        return {CHRCON,"'\\t'",line};
    }
    if (position < source.size()) {
        position++;
        if (position < source.size() && source[position] == '\'') {
            position++;

            return {CHRCON, source.substr(start, position - start),line};
        }
    }
}

Token Lexer::handleSpecialTokens() {
    char current = source[position];
    switch (current) {
        case ';': position++; return {SEMICN, ";",line};
        case ',': position++; return {COMMA, ",",line};
        case '{': position++; return {LBRACE, "{",line};
        case '}': position++; return {RBRACE, "}",line};
        case '(': position++; return {LPARENT, "(",line};
        case ')': position++; return {RPARENT, ")",line};
        case '[': position++; return {LBRACK, "[",line};
        case ']': position++; return {RBRACK, "]",line};
        case '+': position++; return {PLUS, "+",line};
        case '-': position++; return {MINU, "-",line};
        case '*': position++; return {MULT, "*",line};
        case '/': position++; return {DIV, "/",line};
        case '%': position++; return {MOD, "%",line};
        case '<': position++;
            if (position < source.size() && source[position] == '=') {
                position++;
                return {LEQ, "<=",line};
            }
            return {LSS, "<",line};
        case '>': position++;
            if (position < source.size() && source[position] == '=') {
                position++;
                return {GEQ, ">=",line};
            }
            return {GRE, ">",line};

        case '&': position++;
            if (position  < source.size() && source[position] == '&') {
                position += 1;
                return {AND, "&&",line};
            }
            errorList::getInstance().addError({a,line});
            return {AND, "&&",line};
        case '|': position++;
            if (position  < source.size() && source[position] == '|') {
                position += 1;
                return {OR, "||",line};
            }
            errorList::getInstance().addError({a,line});
            return {AND, "&&",line};
        case '=': position++;
            if (position + 1 < source.size() && source[position] == '=') {
                position += 1;
                return {EQL, "==",line};
            }
            return {ASSIGN, "=",line};
        case '!': position++;
            if (position + 1 < source.size() && source[position] == '=') {
                position += 1;
                return {NEQ, "!=",line};
            }
            return {NOT, "!",line};

    }
}

