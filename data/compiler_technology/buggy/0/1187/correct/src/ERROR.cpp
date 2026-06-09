#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "ERROR.h"

inline std::string error_to_string(Error::ErrorType type) {
    static const std::unordered_map<Error::ErrorType, std::string>
        error_type_str = {
#define X(a) {Error::a, #a},
            ERRORTYPE
#undef X
        };
    return error_type_str.at(type);
}

void Error::throwError(){
    std::filebuf outbuf;
    if (outbuf.open("error.txt", std::ios::out) == nullptr) {
        //ERROR open
        return;
    }
    std::ostream os(&outbuf);
    os << lineno << " " << error_to_string(type) << std::endl;
}