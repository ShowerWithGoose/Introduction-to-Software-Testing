// LogicalExpressionChecker.cpp
#include "Error.h"
#include <vector>
#include "Token.h"

std::vector<Error> checkerror_a(const std::string &code, std::ofstream &errorFile) {
    std::vector<Error> errors;
    int i = 0, line = 1;
    while (i < code.size()) {
        if (std::isspace(code[i])) {
            if (code[i] == '\n') line++;
            i++;
        } else if (std::isalpha(code[i]) || code[i] == '_') {
            while (i < code.size() && (std::isalnum(code[i]) || code[i] == '_')) i++;
        } else if (std::isdigit(code[i])) {
            while (i < code.size() && std::isdigit(code[i])) i++;
        } else if (code[i] == '"') {
            while (i < code.size() && code[i] != '"') i++;
            i++;
        } else if (code[i] == '\'') {
            while (i < code.size() && code[i] != '\'') i++;
            i++;
        } else {
            if (i + 1 < code.size()) {
                std::string twoCharOp = code.substr(i, 2);
                if (operators.count(twoCharOp)) {
                    i += 2;
                    continue;
                }
            }
            if (code[i] == '&') {
                if (i + 1 >= code.size() || code[i + 1] != '&') {
                    errors.push_back({"a",line});
                } else {
                    i += 2;
                }
            } else if (code[i] == '|') {
                if (i + 1 >= code.size() || code[i + 1] != '|') {
                    errors.push_back({"a",line});
                } else {
                    i += 2;
                }
            } else {
                i++;
            }
        }
    }
    return errors;
}