/*
 * @brief: CLexicalAnalyzer is defined here.
 * @birth: Created on 2024/9/26.
 * @revision: last revised on 2024/9/26.
 */

#include "CLexicalAnalyzer.h"

using std::pair;

std::map<string, enum _TOKEN_TYPE> sg_cReservedMap = {
        pair<string, enum _TOKEN_TYPE>("main", MAINTK),
        pair<string, enum _TOKEN_TYPE>("const", CONSTTK),
        pair<string, enum _TOKEN_TYPE>("int", INTTK),
        pair<string, enum _TOKEN_TYPE>("char", CHARTK),
        pair<string, enum _TOKEN_TYPE>("break", BREAKTK),
        pair<string, enum _TOKEN_TYPE>("continue", CONTINUETK),
        pair<string, enum _TOKEN_TYPE>("if", IFTK),
        pair<string, enum _TOKEN_TYPE>("else", ELSETK),
        pair<string, enum _TOKEN_TYPE>("for", FORTK),
        pair<string, enum _TOKEN_TYPE>("getint", GETINTTK),
        pair<string, enum _TOKEN_TYPE>("getchar", GETCHARTK),
        pair<string, enum _TOKEN_TYPE>("printf", PRINTFTK),
        pair<string, enum _TOKEN_TYPE>("return", RETURNTK),
        pair<string, enum _TOKEN_TYPE>("void", VOIDTK)
};

char const* g_strTokenCategoryCode[41] = {
    "IDENFR", "INTCON", "STRCON", "CHRCON", "MAINTK",
    "CONSTTK", "INTTK", "CHARTK", "BREAKTK", "CONTINUETK",
    "IFTK", "ELSETK", "NOT", "AND", "OR",
    "FORTK", "GETINTTK", "GETCHARTK", "PRINTFTK", "RETURNTK",
    "PLUS", "MINU", "VOIDTK", "MULT", "DIV",
    "MOD", "LSS", "LEQ", "GRE", "GEQ",
    "EQL", "NEQ", "ASSIGN", "SEMICN", "COMMA",
    "LPARENT", "RPARENT", "LBRACK", "RBRACK", "LBRACE",
    "RBRACE"
};

static char matchEscapes(char ch) {
    switch (ch) {
        case 'a':
            return (char) 7;
        case 'b':
            return (char) 8;
        case 't':
            return (char) 9;
        case 'n':
            return (char) 10;
        case 'v':
            return (char) 11;
        case 'f':
            return (char) 12;
        case 'r':
            return (char) 13;
        case '0':
            return (char) 0;
        default:
            return ch;
    }
}

char CLexicalAnalyzer::NextChar() {
    // MODIFIES: this->m_nLineCount;
    // EFFECTS: Read the next char, and count the columns in the mean time.
    //    Every escape char started with \ will be interpreted.
    //    When this method is invoked for the first time, the very first char
    //       in the buffer will be returned.
    char ch = m_InputBuffer->GetChar();

    if (ch == '\\') {
        m_InputBuffer->MoveForwardBy1();
        this->m_nColumnCount++;
        ch = matchEscapes(m_InputBuffer->GetChar());
    }

    m_InputBuffer->MoveForwardBy1();
    this->m_nColumnCount++;

    return ch;
}

void* CLexicalAnalyzer::NextToken() {
    // MODIFIES: this->m_nTokenType;
    string* token = nullptr;
    char ch;

    // we must make sure that, when we run the 'switch' below,
    //     the 'forward' in the InputBuffer must be pointed to the
    //     first char in the token that will be returned this time.
    do {
        // 'switch' so as to simulate the FA
        switch ((ch = this->NextChar())) {
            case '\n':
                this->m_nLineCount++;
                this->m_nColumnCount = 1;
                break;
            case ' ':
            case '\t':
            case '\r':
                break;
            case '!':
                token = new string("!");
                if ((ch = CurrentChar()) != '=') {
                    this->m_nTokenType = NOT;
                } else {
                    token->push_back(ch);
                    this->m_nTokenType = NEQ;
                    this->NextChar();
                }
                break;
            case '&':
                token = new string("&&");
                this->m_nTokenType = AND;
                if (this->CurrentChar() != '&') {
                    throw LexicalError(m_nLineCount, m_nColumnCount, token);
                } else {
                    this->NextChar();
                }
                break;
            case '|':
                token = new string("||");
                this->m_nTokenType = OR;
                if (this->CurrentChar() != '|') {
                    throw LexicalError(m_nLineCount, m_nColumnCount, token);
                } else {
                    this->NextChar();
                }
                break;
            case '+':
                token = new string("+");
                this->m_nTokenType = PLUS;
                break;
            case '-':
                token = new string("-");
                this->m_nTokenType = MINU;
                break;
            case '*':
                token = new string("*");
                this->m_nTokenType = MULT;
                break;
            case '/':
                if (this->CurrentChar() == '/') {
                    do {
                        m_InputBuffer->MoveForwardBy1();
                        this->m_nColumnCount++;
                    } while (m_InputBuffer->GetChar() != '\n');
                } else if (this->CurrentChar() == '*') {
                    char first, second;
                    m_InputBuffer->MoveForwardBy1();
                    first = m_InputBuffer->GetChar();
                    m_InputBuffer->MoveForwardBy1();
                    second = m_InputBuffer->GetChar();
                    this->m_nColumnCount += 2;

                    while (first != '*' || second != '/') {
                        if (first == '\n') {
                            this->m_nLineCount++;
                            this->m_nColumnCount = 1;
                        }
                        m_InputBuffer->MoveForwardBy1();
                        first = second;
                        second = m_InputBuffer->GetChar();
                        this->m_nColumnCount++;
                    }
                    m_InputBuffer->MoveForwardBy1();
                    this->m_nColumnCount++;
                } else {
                    token = new string("/");
                    this->m_nTokenType = DIV;
                }
                break;
            case '%':
                token = new string("%");
                this->m_nTokenType = MOD;
                break;
            case '<':
                token = new string("<");
                if ((ch = CurrentChar()) != '=') {
                    this->m_nTokenType = LSS;
                } else {
                    token->push_back(ch);
                    this->m_nTokenType = LEQ;
                    this->NextChar();
                }
                break;
            case '>':
                token = new string(">");
                if ((ch = CurrentChar()) != '=') {
                    this->m_nTokenType = GRE;
                } else {
                    token->push_back(ch);
                    this->m_nTokenType = GEQ;
                    this->NextChar();
                }
                break;
            case '=':
                token = new string("=");
                if ((ch = CurrentChar()) != '=') {
                    this->m_nTokenType = ASSIGN;
                } else {
                    token->push_back(ch);
                    this->m_nTokenType = EQL;
                    this->NextChar();
                }
                break;
            case ';':
                token = new string(";");
                this->m_nTokenType = SEMICN;
                break;
            case ',':
                token = new string(",");
                this->m_nTokenType = COMMA;
                break;
            case '(':
                token = new string("(");
                this->m_nTokenType = LPARENT;
                break;
            case ')':
                token = new string(")");
                this->m_nTokenType = RPARENT;
                break;
            case '[':
                token = new string("[");
                this->m_nTokenType = LBRACK;
                break;
            case ']':
                token = new string("]");
                this->m_nTokenType = RBRACK;
                break;
            case '{':
                token = new string("{");
                this->m_nTokenType = LBRACE;
                break;
            case '}':
                token = new string("}");
                this->m_nTokenType = RBRACE;
                break;
            case EOF:
                return nullptr;
            default:
                token = dealNonterminal(ch);
        }
    } while (token == nullptr);

    return token;
}

static inline bool isLetter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

static inline bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

static bool isReserved(const string& word) {
    return (sg_cReservedMap.find(word) != sg_cReservedMap.end());
}

static int distinctWord(string* word) {
    if (isReserved(*word)) {
        return sg_cReservedMap[*word];
    } else {
        return IDENFR;
    }
}

string* CLexicalAnalyzer::dealNonterminal(char ch) {
    // EFFECTS: Generate tokens that are represented by non-terminal symbols.
    auto* token = new string(1, ch);

    if (ch == '\'') {
        token->push_back(this->NextChar());
        token->push_back(this->NextChar());
        this->m_nTokenType = CHRCON;
    } else if (ch == '\"') {
        char pre = ch;
        ch = this->NextChar();
        while (pre == '\\' || ch != '\"') {
            if (ch == '\n') {
                this->m_nLineCount++;
                this->m_nColumnCount = 1;
                do {
                    pre = ch;
                    ch = this->NextChar();
                    this->m_nColumnCount++;
                } while (ch == '\t' || ch == ' ');
                continue;
            } else {
                token->push_back(ch);
                pre = ch;
                ch = this->NextChar();
            }
        }
        token->push_back(ch);
        this->m_nTokenType = STRCON;
    } else if (isDigit(ch)) {
        if (ch != '0') {
            ch = this->CurrentChar();
            while (ch >= '0' && ch <= '9') {
                token->push_back(ch);
                this->NextChar();
                ch = this->CurrentChar();
            }
        }
        this->m_nTokenType = INTCON;
    } else if (ch == '_' || isLetter(ch)) {
        ch = this->CurrentChar();
        while (ch == '_' || isDigit(ch) || isLetter(ch)) {
            token->push_back(ch);
            this->NextChar();
            ch = this->CurrentChar();
        }
        this->m_nTokenType = distinctWord(token);
    } else {
        delete token;
        std::cout << "Wrong input?" << std::endl;
        return nullptr;
    }

    return token;
}