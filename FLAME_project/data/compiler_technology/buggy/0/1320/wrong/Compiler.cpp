#include <fstream>
#include <unordered_map>

// Error handler class
class ErrorHandler {
   private:
    std::ostream& out;

   public:
    ErrorHandler(std::ostream& out) : out(out) {}
    ~ErrorHandler() {}

    void error(int ln, char type) {
        out << ln << " " << type << std::endl;
        return;
    }
};

std::ofstream error_out("error.txt");
ErrorHandler errorHandler(error_out);

// Reserve identifier
#define X_RESERVE_IDENTIFIER                \
    X(UNDEFTK, "UNDEFTK", "")               \
    X(MAINTK, "MAINTK", "main")             \
    X(CONSTTK, "CONSTTK", "const")          \
    X(INTTK, "INTTK", "int")                \
    X(CHARTK, "CHARTK", "char")             \
    X(BREAKTK, "BREAKTK", "break")          \
    X(CONTINUETK, "CONTINUETK", "continue") \
    X(IFTK, "IFTK", "if")                   \
    X(ELSETK, "ELSETK", "else")             \
    X(FORTK, "FORTK", "for")                \
    X(GETINTTK, "GETINTTK", "getint")       \
    X(GETCHARTK, "GETCHARTK", "getchar")    \
    X(PRINTFTK, "PRINTFTK", "printf")       \
    X(RETURNTK, "RETURNTK", "return")       \
    X(VOIDTK, "VOIDTK", "void")

enum class Reserve {
#define X(a, b, c) a,
    X_RESERVE_IDENTIFIER
#undef X
};

std::unordered_map<std::string, Reserve> StringReserve = {
#define X(a, b, c) {c, Reserve::a},
    X_RESERVE_IDENTIFIER
#undef X
};

// Token type
#define X_TOKEN_TYPE           \
    X(IDENFR, "IDENFR", "")    \
    X(INTCON, "INTCON", "")    \
    X(STRCON, "STRCON", "")    \
    X(CHRCON, "CHRCON", "")    \
    X(NOT, "NOT", "!")         \
    X(AND, "AND", "&&")        \
    X(OR, "OR", "||")          \
    X(PLUS, "PLUS", "+")       \
    X(MINU, "MINU", "-")       \
    X(MULT, "MULT", "*")       \
    X(DIV, "DIV", "/")         \
    X(MOD, "MOD", "%")         \
    X(LSS, "LSS", "<")         \
    X(LEQ, "LEQ", "<=")        \
    X(GRE, "GRE", ">")         \
    X(GEQ, "GEQ", ">=")        \
    X(EQL, "EQL", "==")        \
    X(NEQ, "NEQ", "!=")        \
    X(ASSIGN, "ASSIGN", "=")   \
    X(SEMICN, "SEMICN", ";")   \
    X(COMMA, "COMMA", ",")     \
    X(LPARENT, "LPARENT", "(") \
    X(RPARENT, "RPARENT", ")") \
    X(LBRACK, "LBRACK", "[")   \
    X(RBRACK, "RBRACK", "]")   \
    X(LBRACE, "LBRACE", "{")   \
    X(RBRACE, "RBRACE", "}")   \
    X(NOTE_TK, "NOTE_TK", "")  \
    X(EOF_TK, "EOF_TK", "")

enum class TokenType {
#define X(a, b, c) a,
    X_TOKEN_TYPE X_RESERVE_IDENTIFIER
#undef X
};

std::unordered_map<std::string, TokenType> StringTokenType = {
#define X(a, b, c) {c, TokenType::a},
    X_TOKEN_TYPE X_RESERVE_IDENTIFIER
#undef X
};

std::unordered_map<TokenType, std::string> TokenTypeName = {
#define X(a, b, c) {TokenType::a, b},
    X_TOKEN_TYPE X_RESERVE_IDENTIFIER
#undef X
};

// Token class
class Token {
   private:
   public:
    TokenType type;
    std::string typeName;
    std::string value;
    unsigned int ln;
    Token() = default;
    Token(TokenType type, std::string value, unsigned int ln)
        : type(type),
          typeName(TokenTypeName.find(type)->second),
          value(value),
          ln(ln) {}
    ~Token() {}
};

// Lexer class
class Lexer {
   private:
    std::istream& src;
    unsigned int cur_ln;

   public:
    Lexer(std::istream& src_stream) : src(src_stream), cur_ln(1) {}
    ~Lexer() {}

    TokenType is_reserve(std::string value) {
        auto it = StringReserve.find(value);
        if (it != StringReserve.end() && it->second != Reserve::UNDEFTK) {
            return StringTokenType.find(value)->second;
        } else {
            return TokenType::UNDEFTK;
        }
    }

    void next(Token& token) {
        std::string cur_token;
        char ch = src.get();
        while (ch == ' ' || ch == '\t' || ch == '\n') {
            if (ch == '\n') cur_ln++;
            ch = src.get();
        }

        if (ch == -1) {
            token = Token(TokenType::EOF_TK, "", cur_ln);
            return;
        }

        if (ch == '_' || isalpha(ch)) {
            cur_token += ch;
            ch = src.get();
            while (ch == '_' || isalpha(ch) || isdigit(ch)) {
                cur_token += ch;
                ch = src.get();
            }
            src.unget();
            TokenType type = is_reserve(cur_token);
            if (type == TokenType::UNDEFTK) type = TokenType::IDENFR;
            token = Token(type, cur_token, cur_ln);
        } else if (isdigit(ch)) {
            cur_token += ch;
            ch = src.get();
            while (isdigit(ch)) {
                cur_token += ch;
                ch = src.get();
            }
            src.unget();
            token = Token(TokenType::INTCON, cur_token, cur_ln);
        } else if (ch == '\"') {
            cur_token += ch;
            ch = src.get();
            while (ch != '\"') {
                cur_token += ch;
                ch = src.get();
            }
            cur_token += ch;
            token = Token(TokenType::STRCON, cur_token, cur_ln);
        } else if (ch == '\'') {
            cur_token += ch;
            ch = src.get();
            if (ch == '\\') {
                cur_token += ch;
                ch = src.get();
            }
            cur_token += ch;
            ch = src.get();
            cur_token += ch;
            token = Token(TokenType::CHRCON, cur_token, cur_ln);
        } else if (ch == '!') {
            cur_token += ch;
            ch = src.get();
            if (ch == '=') {
                cur_token += ch;
                token = Token(TokenType::NEQ, cur_token, cur_ln);
            } else {
                src.unget();
                token = Token(TokenType::NOT, cur_token, cur_ln);
            }
        } else if (ch == '&') {
            cur_token += ch;
            ch = src.get();
            if (ch == '&') {
                cur_token += ch;
                token = Token(TokenType::AND, cur_token, cur_ln);
            } else {
                errorHandler.error(cur_ln, 'a');
                src.unget();
                token = Token(TokenType::AND, cur_token, cur_ln);
            }
        } else if (ch == '|') {
            cur_token += ch;
            ch = src.get();
            if (ch == '|') {
                cur_token += ch;
                token = Token(TokenType::OR, cur_token, cur_ln);
            } else {
                errorHandler.error(cur_ln, 'a');
                src.unget();
                token = Token(TokenType::OR, cur_token, cur_ln);
            }
        } else if (ch == '+') {
            cur_token += ch;
            token = Token(TokenType::PLUS, cur_token, cur_ln);
        } else if (ch == '-') {
            cur_token += ch;
            token = Token(TokenType::MINU, cur_token, cur_ln);
        } else if (ch == '*') {
            cur_token += ch;
            token = Token(TokenType::MULT, cur_token, cur_ln);
        } else if (ch == '/') {
            cur_token += ch;
            ch = src.get();

            if (ch == '/') {
                cur_token += ch;
                ch = src.get();

                while (ch != '\n') {
                    cur_token += ch;
                    ch = src.get();
                }
                src.unget();
                token = Token(TokenType::NOTE_TK, cur_token, cur_ln);
            } else if (ch == '*') {
                cur_token += ch;
                ch = src.get();

                while (1) {
                    while (ch != '*') {
                        cur_token += ch;
                        ch = src.get();
                        if (ch == '\n') cur_ln++;
                    }
                    while (ch == '*') {
                        cur_token += ch;
                        ch = src.get();
                    }
                    if (ch == '/') {
                        token = Token(TokenType::NOTE_TK, cur_token, cur_ln);
                        break;
                    }
                }
            } else {
                src.unget();
                token = Token(TokenType::DIV, cur_token, cur_ln);
            }
        } else if (ch == '%') {
            cur_token += ch;
            token = Token(TokenType::MOD, cur_token, cur_ln);
        } else if (ch == '<') {
            cur_token += ch;
            ch = src.get();
            if (ch == '=') {
                cur_token += ch;
                token = Token(TokenType::LEQ, cur_token, cur_ln);
            } else {
                src.unget();
                token = Token(TokenType::LSS, cur_token, cur_ln);
            }
        } else if (ch == '>') {
            cur_token += ch;
            ch = src.get();
            if (ch == '=') {
                cur_token += ch;
                token = Token(TokenType::GEQ, cur_token, cur_ln);
            } else {
                src.unget();
                token = Token(TokenType::GRE, cur_token, cur_ln);
            }
        } else if (ch == '=') {
            cur_token += ch;
            ch = src.get();
            if (ch == '=') {
                cur_token += ch;
                token = Token(TokenType::EQL, cur_token, cur_ln);
            } else {
                src.unget();
                token = Token(TokenType::ASSIGN, cur_token, cur_ln);
            }
        } else if (ch == ';') {
            cur_token += ch;
            token = Token(TokenType::SEMICN, cur_token, cur_ln);
        } else if (ch == ',') {
            cur_token += ch;
            token = Token(TokenType::COMMA, cur_token, cur_ln);
        } else if (ch == '(') {
            cur_token += ch;
            token = Token(TokenType::LPARENT, cur_token, cur_ln);
        } else if (ch == ')') {
            cur_token += ch;
            token = Token(TokenType::RPARENT, cur_token, cur_ln);
        } else if (ch == '[') {
            cur_token += ch;
            token = Token(TokenType::LBRACK, cur_token, cur_ln);
        } else if (ch == ']') {
            cur_token += ch;
            token = Token(TokenType::RBRACK, cur_token, cur_ln);
        } else if (ch == '{') {
            cur_token += ch;
            token = Token(TokenType::LBRACE, cur_token, cur_ln);
        } else if (ch == '}') {
            cur_token += ch;
            token = Token(TokenType::RBRACE, cur_token, cur_ln);
        }

        return;
    }
};

int main() {
    std::ifstream testfile;
    testfile.open("testfile.txt");

    std::ofstream lexer_out;
    lexer_out.open("lexer.txt");

    Token token;
    Lexer lexer(testfile);
    while (1) {
        lexer.next(token);
        if (token.type == TokenType::EOF_TK) break;
        if (token.type == TokenType::NOTE_TK) continue;
        lexer_out << token.typeName << " " << token.value << std::endl;
    }

    testfile.close();
    lexer_out.close();
    error_out.close();
    return 0;
}