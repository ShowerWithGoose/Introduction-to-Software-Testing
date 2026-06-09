#include "tools.h"
#include <fstream>
void error(ErrorType e,int line, std::ofstream &err){
    switch (e){
        case ErrorType::a:
            err<<line<<" a"<<std::endl;
            break;
        case ErrorType::b:
            err<<line<<" b"<<std::endl;
            break;
        case ErrorType::c:
            err << line << " c" << std::endl;
            break;
        case ErrorType::d:
            err << line << " d" << std::endl;
            break;
        case ErrorType::e:
            err << line << " e" << std::endl;
            break;
        case ErrorType::f:
            err << line << " f" << std::endl;
            break;
        case ErrorType::g:
            err << line << " g" << std::endl;
            break;
        case ErrorType::h:
            err << line << " h" << std::endl;
            break;
        case ErrorType::i:
            err << line << " i" << std::endl;
            break;
        case ErrorType::j:
            err << line << " j" << std::endl;
            break;
        case ErrorType::k:
            err << line << " k" << std::endl;
            break;
        case ErrorType::l:
            err << line << " l" << std::endl;
            break;
        case ErrorType::m:
            err << line << " m" << std::endl;
            break;
        default:
            break;
    }

}
