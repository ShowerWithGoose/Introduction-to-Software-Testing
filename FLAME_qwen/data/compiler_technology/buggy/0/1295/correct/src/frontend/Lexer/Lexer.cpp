//
// Created by  on 2024/10/1.
//

#include "Lexer.h"
#include "../../errors/Error.h"

namespace frontend {

    frontend::Lexer::~Lexer() {
        for (auto *token : tokenList) {
            delete token;
        }
    }

    void Lexer::matchOneToken() {
        static int lineNum = 1;  // 当前的行号
        int update_index;
        char cur = text[cur_index];
        char next = cur_index + 1 < text.size() ? text[cur_index + 1] : '\0';

        // 错误处理
        if (cur == '&' && next != '&' || cur == '|' && next != '|') {
            auto err = new error::Error(lineNum, 'a');
            error::errorList.push_back(err);
            std::string tmp = "&";
            tokenList.push_back(new Token(delimiter_to_type_map["&&"], tmp, lineNum));
            cur_index++;
            return;
        }

        // 判断注释
        if (cur == '/') {
            if (next == '/') {
                for (int i = cur_index + 2; i < text.size(); i++) {
                    char t = text[i];
                    if (t == '\n') {
                        lineNum++;
                        cur_index = i + 1;
                        return;
                    }
                }
                // 如果能走出循环，说明注释是最后一行的
                cur_index = int(text.size());
                return;
            } else if (next == '*') {
                for (int i = cur_index + 2; i + 1 < text.size(); i++) {
                    char t = text[i];
                    char p = text[i + 1];
                    if (t == '\n') lineNum++;
                    if (t == '*' && p == '/') {
                        cur_index = i + 2;
                        return;
                    }
                }
            }
        }

        if (text[cur_index] == '\n') {
            cur_index++;
            lineNum++;
            return;
        }

        // 空白字符直接跳过
        if (cur == ' ' || cur == '\t') {
            cur_index++;
            return;
        }

        // 匹配保留字
        if ((update_index = Token::tryMatchReserved(text, cur_index))) {
            std::string content = text.substr(cur_index, update_index - cur_index);
            tokenList.push_back(new Token(reserved_to_type_map[content], content, lineNum));
            cur_index = update_index;
            return;
        }

        // 匹配标识符
        if ((update_index = Token::tryMatchIdentifier(text, cur_index))) {
            std::string content = text.substr(cur_index, update_index - cur_index);
            tokenList.push_back(new Token(Token::TokenType::IDENFR, content, lineNum));
            cur_index = update_index;
            return;
        }

        // 匹配字符串
        if ((update_index = Token::tryMatchStr(text, cur_index))) {
            std::string content = text.substr(cur_index, update_index - cur_index);
            tokenList.push_back(new Token(Token::TokenType::STRCON, content, lineNum));
            cur_index = update_index;
            return;
        }

        // 匹配整数
        if ((update_index = Token::tryMatchInt(text, cur_index))) {
            std::string content = text.substr(cur_index, update_index - cur_index);
            tokenList.push_back(new Token(Token::TokenType::INTCON, content, lineNum));
            cur_index = update_index;
            return;
        }

        // 匹配字符
        if ((update_index = Token::tryMatchChar(text, cur_index))) {
            std::string content = text.substr(cur_index, update_index - cur_index);
            tokenList.push_back(new Token(Token::TokenType::CHRCON, content, lineNum));
            cur_index = update_index;
            return;
        }

        // 匹配分界符
        if ((update_index = Token::tryMatchDelimiter(text, cur_index))) {
            std::string content = text.substr(cur_index, update_index - cur_index);
            tokenList.push_back(new Token(delimiter_to_type_map[content], content, lineNum));
            cur_index = update_index;
            return;
        }
//        std::cerr << "匹配到未知token" << std::endl;
    }

    void Lexer::init() {
        while (cur_index < text.size()) {
            matchOneToken();
        }
    }

    void Lexer::printTokenList(const std::string& output_path) {
        std::ofstream file(output_path);
        for (auto *token : tokenList) {
            file << token_type_to_string_map[int(token->getTokenType())] << " " << token->getContent() << std::endl;
        }
    }
} // frontend