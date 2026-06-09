/**
 * Error class
 * @refitem error
 * @auther
 * @data 2024/10/14
 */
#ifndef COMPILER_ERROR_H
#define COMPILER_ERROR_H

#include <string>

struct errorItem {
    int lineNum;
    std::string errorType;
};

class Error {
public:
    static void sortError();
};


#endif //COMPILER_ERROR_H
