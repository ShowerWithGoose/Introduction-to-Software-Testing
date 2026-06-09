// Error.h
#ifndef ERROR_H
#define ERROR_H

#include <string>
#include <fstream>
#include <vector>

struct Error {
    std::string type;
    int line;
};

extern bool hasError;
extern std::vector<Error> errors;

// 错误检查：解析 LAndExp 和 LOrExp
std::vector<Error> checkerror_a(const std::string &code, std::ofstream &errorFile);

#endif // ERROR_H
