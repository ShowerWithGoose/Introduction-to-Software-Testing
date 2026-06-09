#ifndef COMPILER_ERRORLIST_H
#define COMPILER_ERRORLIST_H

#include <vector>
#include <string>
#include <algorithm>
#include "error.h"

class errorList {
private:
    std::vector<Error> errors;
    errorList() = default;  // Make the constructor private to prevent direct instantiation

public:
    static errorList& getInstance();

    std::vector<Error>& getErrorList() {
        return errors;
    }
    void addError(Error error) {
        errors.push_back(error);
    }
    bool haveError() {
        return !errors.empty();
    }
    static bool compareErrors(const Error& error1, const Error& error2) {
        return error1.line < error2.line;
    }
    void print(std::ostream &os)
    {
        std::sort(errors.begin(), errors.end(), compareErrors);
        for(const Error &error : errors) {
            error.print(os);
        }
    }
};

#endif // COMPILER_ERRORLIST_H