//
// Created by  on 2024/10/2.
//

#ifndef SYS_COMPILER_ERROR_H
#define SYS_COMPILER_ERROR_H

#include <vector>

namespace error {

    class Error {
    public:
        Error(int lineNum, char category) : lineNum(lineNum), category(category) {}
    public:
        int lineNum;  // 报错行号
        char category;  // 错误类别
    };

    extern std::vector<Error *> errorList;
    extern void printErrorList();
} // error

#endif //SYS_COMPILER_ERROR_H
