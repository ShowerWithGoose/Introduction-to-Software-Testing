//
// Created by  on 2024/9/20.
//

#ifndef ERROR_H
#define ERROR_H
#include <string>

class Error {
    char errorType;
    int line;

    public:
    Error(const char type, const int line) : errorType(type), line(line) {};

    std::string toString() const {
        return std::to_string(line) + ' ' + errorType;
    }
};

#endif //ERROR_H
