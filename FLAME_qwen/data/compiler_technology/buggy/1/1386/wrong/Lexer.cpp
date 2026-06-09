#include "tools.h"
#include <mutex>
const char* SymbolStrings[] = {
        "IDENFR", "INTCON", "STRCON", "CHRCON",
        "MAINTK", "CONSTTK", "INTTK", "CHARTK",
        "BREAKTK", "CONTINUETK", "IFTK", "ELSETK",
        "NOT", "AND", "OR", "FORTK",
        "GETINTTK", "GETCHARTK", "PRINTFTK", "RETURNTK",
        "PLUS", "MINU", "VOIDTK", "MULT",
        "DIV", "MOD", "LSS", "LEQ",
        "GRE", "GEQ", "EQL", "NEQ",
        "ASSIGN", "SEMICN", "COMMA", "LPARENT",
        "RPARENT", "LBRACK", "RBRACK", "LBRACE",
        "RBRACE"
};
std::string symbolToString(Symbol symbol) {
    if (symbol >= IDENFR && symbol <= RBRACE) {
        return SymbolStrings[symbol];
    } else {
        return "UNKNOWN";
    }
}

Lexer::Lexer(std::string in,std::string out,std::string err_out){
    isOutput = false;
    input.open(in);
    output.open(out);
    err_output.open(err_out);
    peekingNum = 0;
    line = 1;
}
int Lexer::isSpace(){
    return t_char == ' ';
}
int Lexer::isNewline(){
    return t_char == '\n' || t_char == '\r' ;
}
int Lexer::isUnderLine() {
    return t_char == '_';
}
int Lexer::isTab(){
    return t_char == '\t';
}
int Lexer::isLetter(){
    if((t_char >= 'a'&& t_char <= 'z') || (t_char >= 'A'&& t_char <= 'Z')){
        return 1;
    }
    return 0;
}
int Lexer::isDigit(){
    if(t_char >= '0'&& t_char <= '9'){
        return 1;
    }
    return 0;
}

int Lexer::isComma() {
    return t_char == ',';
}

int Lexer::isSemi() {
    return t_char == ';';
}

int Lexer::isNot() {
    return t_char == '!';
}

int Lexer::isSingleAnd() {
    return t_char == '&';
}

int Lexer::isSingleOr() {
    return t_char == '|';
}

int Lexer::isPlus() {
    return t_char == '+';
}

int Lexer::isMinus() {
    return t_char == '-';
}

int Lexer::isDivi() {
    return t_char == '/';
}

int Lexer::isStar() {
    return t_char == '*';
}
int Lexer::isMod() {
    return t_char == '%';
}

int Lexer::isLess() {
    return t_char == '<';
}

int Lexer::isGreater() {
    return t_char == '>';
}

int Lexer::isEqu() {
    return t_char == '=';
}

int Lexer::isLpar() {
    return t_char == '(';
}

int Lexer::isRpar() {
    return t_char == ')';
}

int Lexer::isLbrack() {
    return t_char == '[';
}

int Lexer::isRbrack() {
    return t_char == ']';
}

int Lexer::isLbrace() {
    return t_char == '{';
}

int Lexer::isRbrace() {
    return t_char == '}';
}
void Lexer::cleanStr() {
    t_string = "\0";
}
int Lexer::tranNum() {
    sscanf(t_string.c_str(), "%d", &num);
    return num;
}
void Lexer::retract() {
    if(isNewline())line = tLine;
    input.unget();
}
void Lexer::catStr() {
    t_string += t_char;
}
void Lexer::myGetchar() {
    t_char = input.get();
    if(isNewline() && !isPeeking) line++;
}
Symbol Lexer::reserver() {
    if(t_string == "main") return MAINTK;
    else if (t_string == "const")return CONSTTK;
    else if (t_string == "int")return INTTK;
    else if (t_string == "char")return CHARTK;
    else if (t_string == "break")return BREAKTK;
    else if (t_string == "continue")return CONTINUETK;
    else if (t_string == "if")return IFTK;
    else if (t_string == "else")return ELSETK;
    else if (t_string == "for")return FORTK;
    else if (t_string == "getint")return GETINTTK;
    else if (t_string == "getchar")return GETCHARTK;
    else if (t_string == "printf")return PRINTFTK;
    else if (t_string == "return")return RETURNTK;
    else if (t_string == "void")return VOIDTK;
    return IDENFR;
}
int Lexer::getToken() {
    cleanStr();
    tLine = line;
    myGetchar();
    while (isSpace() || isNewline() || isTab()) {
        myGetchar();
    }
    if(isLetter() || isUnderLine()){
        while (isLetter() || isDigit() || isUnderLine())
        {
            catStr();
            myGetchar();
        }
        retract();
        token.type = reserver();
        token.value = t_string;
    }
    else if(isDigit()){
        while (isDigit()){
            catStr(); myGetchar();
        }
        retract();
        num = tranNum();
        token.type = INTCON;
        token.value = t_string;
    }
    else if(isNot()){
        myGetchar();
        if (isEqu()){
            token.type = NEQ;
            token.value = "!=";
        } else{
            token.type = NOT;
            token.value = "!";
            retract();
        }
    }
    else if (isSingleAnd()){
        myGetchar();
        if(isSingleAnd()){
            token.type = AND;
            token.value = "&&";
        } else{
            token.type = AND;
            token.value = "&";
            retract();
            if(!isPeeking)errorOutput(ErrorType ::a,line);
        }
    }
    else if (isSingleOr()){
        myGetchar();
        if(isSingleOr()){
            token.type = OR;
            token.value = "||";
        } else{
            token.type = OR;
            token.value = "|";
            retract();
            if(!isPeeking)errorOutput(ErrorType ::a,line);
        }
    }
    else if(isPlus()){
        token.type = PLUS;
        token.value = "+";
    }
    else if(isMinus()){
        token.type = MINU;
        token.value = "-";
    }
    else if(isStar()){
        token.type = MULT;
        token.value = "*";
    }
    else if(isDivi()){
        myGetchar();
        if((isStar())){
            do{
                do{
                    myGetchar();
                }while (!isStar());
                do
                {
                    myGetchar();
                    if(isDivi())return getToken();
                } while (isStar());
            }while(!isStar());
        }
        else if (isDivi()){
            do{
                myGetchar();
            }while(!isNewline()&& !input.eof());
            return getToken();
        }
        retract();
        token.type = DIV;
        token.value = "/";
    }
    else if(isMod()){
        token.type = MOD;
        token.value = "%";
    }
    else if(isLess()){
        myGetchar();
        if(isEqu()){
            token.type = LEQ;
            token.value = "<=";
        }
        else{
            token.type = LSS;
            token.value = "<";
            retract();
        }
    }
    else if(isGreater()){
        myGetchar();
        if(isEqu()){
            token.type = GEQ;
            token.value = ">=";
        }
        else{
            token.type = GRE;
            token.value = ">";
            retract();
        }
    }
    else if(isEqu()){
        myGetchar();
        if(isEqu()){
            token.type = EQL;
            token.value = "==";
        }
        else{
            token.type = ASSIGN;
            token.value = "=";
            retract();
        }
    }
    else if(isSemi()){
        token.type = SEMICN;
        token.value = ";";
    }
    else if(isComma()){
        token.type = COMMA;
        token.value = ",";
    }
    else if(isLpar()){
        token.type = LPARENT;
        token.value = "(";
    }
    else if(isRpar()){
        token.type = RPARENT;
        token.value = ")";
    }
    else if(isLbrack()){
        token.type = LBRACK;
        token.value = "[";
    }
    else if(isRbrack()){
        token.type = RBRACK;
        token.value = "]";
    }
    else if(isLbrace()){
        token.type = LBRACE;
        token.value = "{";
    }
    else if(isRbrace()){
        token.type = RBRACE;
        token.value = "}";
    }
    else if(t_char == '"'){
        t_string = "\"";
        do{
            myGetchar();
            if(t_char == '\\') {
                t_string += t_char;
                myGetchar();
            }
            t_string += t_char;
        }while(t_char != '\"');
        token.type = STRCON;
        token.value = t_string;
    }
    else if(t_char == '\''){
        t_string = "\'";
        myGetchar();
        if(t_char == '\\'){
            t_string += t_char;
            myGetchar();
        }
        t_string += t_char;
        myGetchar();
        t_string += t_char;
        token.type = CHRCON;
        token.value = t_string;
    }
    else if(input.eof())return EOF;
    if(isOutput)outputToken();
    return 0;
}
void Lexer::outputToken() {
    output<<symbolToString(token.type)<<" "<<token.value<<std::endl;
}
void Lexer::errorOutput(ErrorType e,int tLine) {
    error(e,tLine,err_output);
}
void Lexer::closeOutput() {
    isOutput = false;
}
void Lexer::openOutput() {
    isOutput = true;
}
void Lexer::startPeeking() {
    peekingNum ++;
    isPeeking = true;
}
void Lexer::finishPeeking() {
    peekingNum --;
    if(peekingNum == 0){
        isPeeking = false;
    }
}
void Lexer::closeStream() {
    input.close();
    output.close();
    err_output.close();
}
