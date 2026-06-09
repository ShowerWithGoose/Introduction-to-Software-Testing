//
// Created by  on 2024/10/15.
//

#ifndef COMPILER_ERROR_H
#define COMPILER_ERROR_H
#include <vector>
#include <unordered_map>
#include <string>
#include <ostream>


enum ErrorType{
    a,
    i,//lack ;
    j,//lack )
    k //lack ]
};
struct Error{
    ErrorType type;
    int line;
    std::string value;
    void print(std::ostream &os) const;
};


#endif //COMPILER_ERROR_H
