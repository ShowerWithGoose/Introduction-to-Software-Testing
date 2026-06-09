#ifndef ERROR_H
#define ERROR_H
class Error {
    int occurLineNum;
    char type;
public:
    Error(int occurLineNum,char type) {
        this->occurLineNum = occurLineNum;
        this->type = type;
    }
    int get_lineNum() {
        return occurLineNum;
    }
    char get_type() {
        return type;
    }
};

#endif //ERROR_H
