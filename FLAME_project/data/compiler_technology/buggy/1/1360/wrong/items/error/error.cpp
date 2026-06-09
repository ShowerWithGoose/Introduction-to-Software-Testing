//
// Created by  on 2024/10/15.
//

#include "error.h"


void Error::print(std::ostream& os) const {
    static const std::unordered_map<ErrorType, std::string> typeToString = {
            {a, "a"},
            {i, "i"},
            {j, "j"},
            {k, "k"}
    };
    os << line << " " << typeToString.at(type) << "\n";
}