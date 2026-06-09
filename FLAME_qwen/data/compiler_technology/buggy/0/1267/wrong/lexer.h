#ifndef LEXER_H
#define LEXER_H
#include <utility>
using namespace std;
int nowLineNum = 1;

class Word {
    string typeCode = "";
    string str = "";//原始串,无论正误都储存，作为退出flag
    int check = 0;
public:
    Word(string typeCode,string str) {
        this->typeCode = move(typeCode);
        this->str = move(str);
        check = 0;
    }

    Word() {
        check = 0;
    }

    bool isError() const {
        return check == 1;
    }

    void set_error() {
        check = 1;
    }

    string get_str() {
        return str;
    }

    string get_typeCode() {
        return typeCode;
    }

    void reset(string typeCode,string str,int check) {
        this->typeCode = move(typeCode);
        this->str = move(str);
        this->check = check;
    }
};
bool isAZ(char temp) {
    return temp >= 'a' && temp <='z' || temp >= 'A' && temp <='Z';
}

bool isNum(char temp) {
    return temp >= '0' && temp <= '9';
}

string getWordType(string singleWord) {
    if (singleWord == "main") {
        return"MAINTK";
    }
    else if (singleWord == "const") {
        return"CONSTTK";
    }
    else if (singleWord == "int") {
        return"INTTK";
    }
    else if (singleWord == "char") {
        return"CHARTK";
    }
    else if (singleWord == "break") {
        return "BREAKTK";
    }
    else if (singleWord == "continue") {
        return "CONTINUETK";
    }
    else if (singleWord == "if") {
        return "IFTK";
    }
    else if (singleWord == "else") {
        return "ELSETK";
    }
    else if (singleWord == "for") {
        return "FORTK";
    }
    else if (singleWord == "getint") {
        return "GETINTTK";
    }
    else if (singleWord == "getchar") {
        return "GETCHARTK";
    }
    else if (singleWord == "printf") {
        return "PRINTFTK";
    }
    else if (singleWord == "return") {
        return "RETURNTK";
    }
    else if (singleWord == "void") {
        return "VOIDTK";
    }
    else {
        return "IDENFR";
    }
}

bool isCal(char temp) {
    return temp == '+' || temp == '-'
    || temp == '*' || temp == '/' || temp == '%';
}

string getCalType(string singleWord) {
    if (singleWord == "+") return "PLUS";
    if (singleWord == "-") return "MINU";
    if (singleWord == "*") return "MULT";
    if (singleWord == "/") return "DIV";
    if (singleWord == "%") return "MOD";
    return "";
}

bool isCompare(char temp) {
    return temp == '<' || temp == '>' || temp == '=';
}

string getCompareType1(string singleWord) {
    if (singleWord == "<=") return "LEQ";
    if (singleWord == ">=") return "GEQ";
    if (singleWord == "==") return "EQL";
    if (singleWord == "!=") return "NEQ";
    return "";
}

string getCompareType2(string singleWord) {
    if (singleWord == "<") return "LSS";
    if (singleWord == ">") return "GRE";
    if (singleWord == "=") return "ASSIGN";
    return "";
}

bool isBracket(char temp) {
    return temp == '(' || temp == ')' || temp == '['
    || temp == ']' || temp == '{' || temp == '}';
}

string getBracketType(string singleWord) {
    if (singleWord == "(") return "LPARENT";
    if (singleWord == ")") return "RPARENT";
    if (singleWord == "[") return "LBRACK";
    if (singleWord == "]") return "RBRACK";
    if (singleWord == "{") return "LBRACE";
    if (singleWord == "}") return "RBRACE";
    return "";
}

bool isEnd(char temp) {
    return temp == ';' || temp == ',';
}

string getEndType(string singleWord) {
    if (singleWord == ",") return "COMMA";
    if (singleWord == ";") return "SEMICN";
    return "";
}

bool isNot(char temp) {
    return temp == '!';
}

string getLogicType (string singleWord) {
    if (singleWord == "!") return "NOT";
    if (singleWord == "&&") return "AND";
    if (singleWord == "||") return "OR";
    return "";
}

bool isLogic(char temp) {
    return temp == '|' || temp == '&';
}

char del_note(ifstream &file) {
    char ch;
    if (file.eof()) {
        return '/';
    }
    file.get(ch);
    if (ch != '/' && ch != '*') {
        file.seekg(-1,ios::cur);
        return '/';
    }
    if (ch == '/') {
        while (!file.eof() && ch != '\n') {
            file.get(ch);
        }
        if (ch == '\n') nowLineNum++;
        if (!file.eof()) file.get(ch);
        else ch = ' ';
        return ch;
    }
    else {
        //默认注释一定匹配,所以未检查eof边界
        file.get(ch);
        if (ch == '\n') nowLineNum++;
        char before = ch;
        file.get(ch);
        while (before != '*' && ch != '/') {
            if (ch == '\n') nowLineNum++;
            before = ch;
            file.get(ch);
        }
        return ' ';
    }
}

Word lexer_getWord(ifstream &file) {
    string singleWord = "";
    char temp = ' ';
    Word ans;
    //去前导空白
    while (!file.eof()) {
        file.get(temp);
        if (temp == '\n') {
            nowLineNum++;
            continue;
        }
        if (temp != ' ' && temp != '\t') {
            break;
        }
    }
    if (file.eof() && (temp == ' ' || temp == '\t' || temp == '\n')) {
        return ans;
    }
    //去注释
    if (temp == '/') temp = del_note(file);

    //类型判断
    if (temp == '\'' || temp == '\"') {
        char before = temp;//防止出现转义的单双引号导致意外结束
        singleWord.push_back(temp);
        while (!file.eof()) {
            char ch;
            file.get(ch);
            singleWord.push_back(ch);
            if (ch == temp && before != '\\') break;
            before = ch;
        }
        if (temp == '\'') {
            ans.reset("CHRCON",singleWord,0);
            return ans;
        }
        else {
            ans.reset("STRCON",singleWord,0);
            return ans;
        }
    }
    else if (isNum(temp)) {
        char ch = temp;
        singleWord.push_back(temp);
        while (!file.eof()) {
            file.get(ch);
            if (isNum(ch)) {
                singleWord.push_back(ch);
            }
            else break;
        }
        if (!isNum(ch)) file.seekg(-1,ios::cur);
        ans.reset("INTCON",singleWord,0);
        return ans;
    }
    else if (isAZ(temp) || temp == '_') {
        char ch = temp;
        singleWord.push_back(temp);
        while (!file.eof()) {
            file.get(ch);
            if (isNum(ch) || isAZ(ch) || ch == '_') {
                singleWord.push_back(ch);
            }
            else break;
        }
        if (!(isNum(ch) || isAZ(ch) || ch == '_')) file.seekg(-1,ios::cur);
        ans.reset(getWordType(singleWord),singleWord,0);
        return ans;
    }
    else if (isCal(temp)) {
        singleWord.push_back(temp);
        ans.reset(getCalType(singleWord),singleWord,0);
        return ans;
    }
    else if (isCompare(temp)) {
        singleWord.push_back(temp);
        char ch = ' ';
        int check = 0;
        if (!file.eof()) {
            file.get(ch);
            check = 1;
        }
        if (ch == '=') {
            singleWord.push_back(ch);
            ans.reset(getCompareType1(singleWord),singleWord,0);
            return ans;
        }
        else {
            if (check == 1) file.seekg(-1,ios::cur);
            ans.reset(getCompareType2(singleWord),singleWord,0);
            return ans;
        }
    }
    else if (isBracket(temp)) {
        singleWord.push_back(temp);
        ans.reset(getBracketType(singleWord),singleWord,0);
        return ans;
    }
    else if (isEnd(temp)) {
        singleWord.push_back(temp);
        ans.reset(getEndType(singleWord),singleWord,0);
        return ans;
    }
    else if (isNot(temp)) {
        singleWord.push_back(temp);
        char ch = ' ';
        int check = 0;
        if (!file.eof()) {
            file.get(ch);
            check = 1;
        }
        if (ch == '=') {
            singleWord.push_back(ch);
            ans.reset(getCompareType1(singleWord),singleWord,0);
            return ans;
        }
        else {
            if (check == 1) file.seekg(-1,ios::cur);
            ans.reset(getLogicType(singleWord),singleWord,0);
            return ans;
        }
    }
    else if (isLogic(temp)) {
        singleWord.push_back(temp);
        char ch = ' ';
        int check = 0;
        if (!file.eof()) {
            file.get(ch);
            check = 1;
        }
        if (ch == '&' && temp == '&' || ch == '|' && temp == '|') {
            singleWord.push_back(ch);
            ans.reset(getLogicType(singleWord),singleWord,0);
            return ans;
        }
        else {
            if (check == 1) file.seekg(-1,ios::cur);
            ans.reset("",singleWord,1);
            return ans;
        }
    }
    else {
        return ans;
    }
}


#endif //LEXER_H
