#include "token.h"
#include "error.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <cctype>

const std::unordered_map<std::string, Token::TokenType> keywords_table = {
        {"main", Token::MAINTK},
        {"const", Token::CONSTTK},
        {"int", Token::INTTK},
        {"char", Token::CHARTK},
        {"break", Token::BREAKTK},
        {"continue", Token::CONTINUETK},
        {"if", Token::IFTK},
        {"else", Token::ELSETK},
        {"for", Token::FORTK},
        {"getint", Token::GETINTTK},
        {"getchar", Token::GETCHARTK},
        {"printf", Token::PRINTFTK},
        {"return", Token::RETURNTK},
        {"void", Token::VOIDTK},
};

void next_token(std::istream &input, Token &token, int &lineno) {
    std::string content;
    char ch = input.get();

    while (std::isspace(ch)) {
        if (ch == '\n') {
            lineno++;
        }
        ch = input.get();
    }

    content.append(1, ch);

    if (std::isalpha(ch) || ch == '_') {
        ch = input.get();
        while (std::isalnum(ch) || ch == '_') {
            content.append(1, ch);
            ch = input.get();
        }
        input.unget();
        auto it = keywords_table.find(content);
        auto type = it == keywords_table.end() ? Token::IDENFR : it->second;
        token = Token(type, content, lineno);
    } else if (std::isdigit(ch)) {
        content.clear(); // 清空之前的内容
        do {
            content.append(1, ch);
            ch = input.get();
        } while (std::isdigit(ch));

        input.unget(); // 将最后一个非数字字符放回输入流
        token = Token(Token::INTCON, content, lineno);
    } else if (ch == '+') {
        token = Token(Token::PLUS, content, lineno);
    } else if (ch == '-') {
        token = Token(Token::MINU, content, lineno);
    } else if (ch == '*') {
        token = Token(Token::MULT, content, lineno);
    } else if (ch == '/') {
        char next_char = input.get();

        if (next_char == '/') {
            // Single-line comment, skip until the end of line
            while (ch != '\n' && ch != EOF) {
                ch = input.get();
            }
            lineno++; // Move to next line
            return next_token(input, token, lineno);
        } else if (next_char == '*') {
            // Multi-line comment, skip until '*/'
            while (true) {
                ch = input.get();
                if (ch == EOF) break;
                if (ch == '*' && input.peek() == '/') {
                    input.get(); // Consume '/'
                    break;
                }
                if (ch == '\n') {
                    lineno++; // Update line number for each new line
                }
            }
            return next_token(input, token, lineno); // Continue to get the next token
        } else {
            // If not a comment, it's a division symbol
            input.unget();
            token = Token(Token::DIV, "/", lineno);
            return;
        }
    } else if (ch == '%') {
        token = Token(Token::MOD, content, lineno);
    } else if (ch == ';') {
        token = Token(Token::SEMICN, content, lineno);
    } else if (ch == ',') {
        token = Token(Token::COMMA, content, lineno);
    } else if (ch == '(') {
        token = Token(Token::LPARENT, content, lineno);
    } else if (ch == ')') {
        token = Token(Token::RPARENT, content, lineno);
    } else if (ch == '[') {
        token = Token(Token::LBRACK, content, lineno);
    } else if (ch == ']') {
        token = Token(Token::RBRACK, content, lineno);
    } else if (ch == '{') {
        token = Token(Token::LBRACE, content, lineno);
    } else if (ch == '}') {
        token = Token(Token::RBRACE, content, lineno);
    }else if (ch == '\'') {  // Character constant detection
        char next_char = input.get();
        if (next_char == '\\') {  // Check if it's a backslash (escape character)
            char escape_char = input.get();  // Get the next character after backslash
            switch (escape_char) {
                case 'a': next_char = '\a'; break;
                case 'b': next_char = '\b'; break;
                case 't': next_char = '\t'; break;
                case 'n': next_char = '\n'; break;
                case 'v': next_char = '\v'; break;
                case 'f': next_char = '\f'; break;
                case '"': next_char = '\"'; break;
                case '\'': next_char = '\''; break;
                case '\\': next_char = '\\'; break;
                case '0': next_char = '\0'; break;
                default:
                    token = Token(Token::ERR, std::string(1, ch), lineno);  // Invalid escape sequence
                    ErrorReporter::report(lineno, "invalid escape sequence: \\" + std::string(1, escape_char));
                    return;
            }
        }

        if (input.peek() == '\'') {  // Check if next character is a closing single quote
            input.get();  // Consume the closing single quote
            // Store the escape or regular character as a character constant
            token = Token(Token::CHRCON, "'" + std::string(1, next_char) + "'", lineno);
        } else {
            token = Token(Token::ERR, std::string(1, ch), lineno);  // Incorrect format, report error
            ErrorReporter::report(lineno, "invalid character constant: " + std::string(1, ch));
        }
    }else if (ch == '"') {
        //content.append(1, ch); // Append the starting "
        ch = input.get();

        // Read until the next "
        do{
            content.append(1, ch);
            ch = input.get();
        }while (ch != '"' && ch != EOF);

        if (ch == '"') {
            content.append(1, ch); // Append the closing "
            token = Token(Token::STRCON, content, lineno);
        } else {
            token = Token(Token::ERR, content, lineno);
            ErrorReporter::report(lineno, "unterminated string literal");
        }
    }
    else if (ch == '<') {
        ch = input.get();
        if (ch == '=') {
            content.append(1, ch);
            token = Token(Token::LEQ, content, lineno);
        } else {
            input.unget();
            token = Token(Token::LSS, content, lineno);
        }
    } else if (ch == '>') {
        ch = input.get();
        if (ch == '=') {
            content.append(1, ch);
            token = Token(Token::GEQ, content, lineno);
        } else {
            input.unget();
            token = Token(Token::GRE, content, lineno);
        }
    } else if (ch == '=') {
        ch = input.get();
        if (ch == '=') {
            content.append(1, ch);
            token = Token(Token::EQL, content, lineno);
        } else {
            input.unget();
            token = Token(Token::ASSIGN, content, lineno);
        }
    } else if (ch == '!') {
        ch = input.get();
        if (ch == '=') {
            content.append(1, ch);
            token = Token(Token::NEQ, content, lineno);
        } else {
            input.unget();
            token = Token(Token::NOT, content, lineno);
        }
    } else if (ch == '&') {
        ch = input.get();
        if (ch == '&') {
            content.append(1, ch);
            token = Token(Token::AND, content, lineno);
        } else {
            input.unget();
            token = Token(Token::ERR, content, lineno);
            ErrorReporter::report(lineno, "a");
        }
    } else if (ch == '|') {
        ch = input.get();
        if (ch == '|') {
            content.append(1, ch);
            token = Token(Token::OR, content, lineno);
        } else {
            input.unget();
            token = Token(Token::ERR, content, lineno);
            ErrorReporter::report(lineno, "a");
        }
    } else if (ch == EOF) {
        token = Token(Token::EOF_TK, content, lineno);
    } else {
        token = Token(Token::ERR, content, lineno);
        ErrorReporter::report(lineno, "invalid character: " + content);
    }
}

int main() {
    std::ifstream infile("testfile.txt");
    std::ofstream lexer_out("lexer.txt");
    int lineno = 1;
    Token token;

    if (!infile) {
        std::cerr << "Error: Cannot open testfile.txt" << std::endl;
        return 1;
    }

    while (true) {
        next_token(infile, token, lineno);
        if (token.type == Token::EOF_TK) break;
        if (token.type == Token::ERR) continue;
        lexer_out << token_type_to_string(token.type) << " " << token.content << std::endl;
    }

    if (ErrorReporter::has_errors()) {
        ErrorReporter::output_errors("error.txt");
        std::cout << "Errors encountered. Check error.txt for details." << std::endl;
    }

    return 0;
}
