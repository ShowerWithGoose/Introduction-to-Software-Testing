#define ERRORTYPE X(a) X(b) X(c) X(d) X(e) X(f) X(g) X(h) X(i) X(j) X(k) X(l) X(m)

class Error {
public:
    enum ErrorType {
#define X(a) a,
        ERRORTYPE
#undef X
        MAX
    }type;
    int lineno;
    void throwError();
    Error(ErrorType type, int lineno) 
        : type(type), lineno(lineno) {}

};