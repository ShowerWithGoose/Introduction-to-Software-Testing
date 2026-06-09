#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include <unordered_set>

using namespace std;


enum TokenType {
    CONSTTK, INTTK, CHARTK, VOIDTK, MAINTK, IDENFR, INTCON, STRCON, CHRCON, 
    ELSETK, IFTK, FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, BREAKTK, 
    CONTINUETK, PLUS, MINU, MULT, DIV, MOD, ASSIGN, EQL, NEQ, LSS, LEQ, 
    GRE, GEQ, NOT, AND, OR, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, 
    RBRACE, SEMICN, COMMA, INVALID
};


map<TokenType, string> tokenTypeToStr = {
    {CONSTTK, "CONSTTK"}, {INTTK, "INTTK"}, {CHARTK, "CHARTK"}, {VOIDTK, "VOIDTK"},
    {MAINTK, "MAINTK"}, {IDENFR, "IDENFR"}, {INTCON, "INTCON"}, {STRCON, "STRCON"}, 
    {CHRCON, "CHRCON"}, {ELSETK, "ELSETK"}, {IFTK, "IFTK"}, {FORTK, "FORTK"},
    {GETINTTK, "GETINTTK"}, {GETCHARTK, "GETCHARTK"}, {PRINTFTK, "PRINTFTK"}, 
    {RETURNTK, "RETURNTK"}, {BREAKTK, "BREAKTK"}, {CONTINUETK, "CONTINUETK"},
    {PLUS, "PLUS"}, {MINU, "MINU"}, {MULT, "MULT"}, {DIV, "DIV"}, {MOD, "MOD"},
    {ASSIGN, "ASSIGN"}, {EQL, "EQL"}, {NEQ, "NEQ"}, {LSS, "LSS"}, {LEQ, "LEQ"},
    {GRE, "GRE"}, {GEQ, "GEQ"}, {NOT, "NOT"}, {AND, "AND"}, {OR, "OR"}, 
    {LPARENT, "LPARENT"}, {RPARENT, "RPARENT"}, {LBRACK, "LBRACK"}, 
    {RBRACK, "RBRACK"}, {LBRACE, "LBRACE"}, {RBRACE, "RBRACE"}, 
    {SEMICN, "SEMICN"}, {COMMA, "COMMA"}, {INVALID, "INVALID"}
};


enum ErrorType {
    INVALID_CHAR = 'a'
};


vector<string> lines; 
ofstream lexerOut, errorOut; 
int currentLine = 0;


void readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "无法打开文件: " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
}


void outputToken(TokenType type, const string& value) {
    lexerOut << tokenTypeToStr[type] << " " << value << endl;
}


void outputError(int line, ErrorType errorType) {
    errorOut << line + 1 << " " << char(errorType) << endl;
}

bool isKeyword(const string &str) {
    static unordered_set<string> keywords = {
        "const", "int", "char", "void", "if", "else", "while", "for",
        "break", "continue", "return", "main", "getint", "getchar", "printf"
        // 这里可以添加所有的关键字
    };
    return keywords.find(str) != keywords.end();
}

TokenType getKeywordToken(const string &keyword) {
    if (keyword == "const") return CONSTTK;
    if (keyword == "int") return INTTK;
    if (keyword == "char") return CHARTK;
    if (keyword == "void") return VOIDTK;
    if (keyword == "if") return IFTK;
    if (keyword == "else") return ELSETK;
    if (keyword == "for") return FORTK;
    if (keyword == "break") return BREAKTK;
    if (keyword == "continue") return CONTINUETK;
    if (keyword == "return") return RETURNTK;
    if (keyword == "main") return MAINTK;
    if (keyword == "getint") return GETINTTK;
    if (keyword == "getchar") return GETCHARTK;
    if (keyword == "printf") return PRINTFTK;
}

void lexerAnalysis() {
    bool inBlockComment = false;

    for (currentLine = 0; currentLine < lines.size(); ++currentLine) {
        string line = lines[currentLine];
        for (size_t i = 0; i < line.size();) {
            if (isspace(line[i])) {
                ++i;
                continue;
            }

            // 处理注释部分
            if (!inBlockComment) {
                // 检查是否是单行注释 "//"
                if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/') {
                    // 单行注释，跳过当前行剩下的部分
                    break;
                }

                // 检查是否是多行注释的开始 "/*"
                if (i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*') {
                    inBlockComment = true;  // 进入多行注释状态
                    i += 2;
                    continue;
                }
            }

            // 如果已经在多行注释中，查找多行注释的结束 "*/"
            if (inBlockComment) {
                while (i + 1 < line.size() && !(line[i] == '*' && line[i + 1] == '/')) {
                    ++i;
                }

                if (i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/') {
                    inBlockComment = false;  // 退出多行注释状态
                    i += 2;
                } else {
                    // 如果本行没有找到结束标志，跳过整行
                    break;
                }
                continue;
            }
            
            // 标识符或关键字
            if (isalpha(line[i]) || line[i] == '_') {  // 标识符或关键字必须以字母或下划线开头
                string ident = "";
                while (i < line.size() && (isalnum(line[i]) || line[i] == '_')) {
                    ident += line[i++];
                }

                // 检查是否是关键字
                if (isKeyword(ident)) {
                    outputToken(getKeywordToken(ident), ident);  // 输出关键字
                } else {
                    outputToken(IDENFR, ident);  // 输出标识符
                }
                continue;
            }
            
            else if (isdigit(line[i])) {
                string num;
                while (isdigit(line[i])) {
                    num += line[i++];
                }
                outputToken(INTCON, num);
            }
            
            else if (line[i] == '\"') {
                string strConst = "\"";
                ++i; 
                while (i < line.size() && line[i] != '\"') {
                    strConst += line[i++];
                }
                if (i < line.size() && line[i] == '\"') {
                    strConst += '\"'; 
                    ++i;
                    outputToken(STRCON, strConst); 
                } else {
                    
                    outputError(currentLine, INVALID_CHAR);
                }
            }

            // 字符常量
            else if (line[i] == '\'') {
                ++i;  // 跳过第一个单引号
                if (i < line.size()) {
                    char ch;
                    string charValue = "'";  // 初始化为包含第一个单引号

                    // 如果是转义字符
                    if (line[i] == '\\') {
                        ++i;  // 跳过反斜杠 '\'
                        if (i < line.size()) {
                            switch (line[i]) {
                                case 'n': ch = '\n'; charValue += "\\n"; break;
                                case '0': ch = '\0'; charValue += "\\0"; break;
                                case 't': ch = '\t'; charValue += "\\t"; break;
                                case '\'': ch = '\''; charValue += "\\'"; break;
                                case '\"': ch = '\"'; charValue += "\\\""; break;
                                case '\\': ch = '\\'; charValue += "\\\\"; break;
                                default:
                                    // 非法的转义字符，报错
                                    outputError(currentLine, INVALID_CHAR);
                                    ++i;
                                    continue;
                            }
                        }
                    }
                    // 普通字符常量
                    else {
                        ch = line[i];
                        charValue += ch;
                    }

                    ++i;  // 跳过字符本身
                    if (i < line.size() && line[i] == '\'') {
                        ++i;  // 跳过结尾的单引号
                        charValue += "'";  // 添加结尾的单引号
                        outputToken(CHRCON, charValue);  // 输出字符常量（带有单引号）
                    } else {
                        // 没有找到结尾的单引号，报错
                        outputError(currentLine, INVALID_CHAR);
                    }
                } else {
                    // 未找到字符常量的具体内容，报错
                    outputError(currentLine, INVALID_CHAR);
                }
                continue;
            }
            
            else {
                switch (line[i]) {
                    // 处理 < 和 <=
                    case '<':
                        if (i + 1 < line.size() && line[i + 1] == '=') {
                            outputToken(LEQ, "<=");  // 小于等于
                            i += 2;
                        } else {
                            outputToken(LSS, "<");  // 小于
                            ++i;
                        }
                        continue;

                    // 处理 > 和 >=
                    case '>':
                        if (i + 1 < line.size() && line[i + 1] == '=') {
                            outputToken(GEQ, ">=");  // 大于等于
                            i += 2;
                        } else {
                            outputToken(GRE, ">");  // 大于
                            ++i;
                        }
                        continue;

                    // 处理 == 和 =
                    case '=':
                        if (i + 1 < line.size() && line[i + 1] == '=') {
                            outputToken(EQL, "==");  // 等于
                            i += 2;
                        } else {
                            outputToken(ASSIGN, "=");  // 赋值
                            ++i;
                        }
                        continue;

                    // 处理 !=
                    case '!':
                        if (i + 1 < line.size() && line[i + 1] == '=') {
                            outputToken(NEQ, "!=");  // 不等于
                            i += 2;
                        } else {
                            outputToken(NOT, "!");  // 取反
                            ++i;
                        }
                        continue;

                    case '+': outputToken(PLUS, "+"); break;
                    case '-': outputToken(MINU, "-"); break;
                    case '*': outputToken(MULT, "*"); break;
                    case '/': outputToken(DIV, "/"); break;
                    case '%': outputToken(MOD, "%"); break;
                    case '(': outputToken(LPARENT, "("); break;
                    case ')': outputToken(RPARENT, ")"); break;
                    case '{': outputToken(LBRACE, "{"); break;
                    case '}': outputToken(RBRACE, "}"); break;
                    case '[': outputToken(LBRACK, "["); break;
                    case ']': outputToken(RBRACK, "]"); break;
                    case ';': outputToken(SEMICN, ";"); break;
                    case ',': outputToken(COMMA, ","); break;

                    
                    case '&':
                        if (i + 1 < line.size() && line[i + 1] == '&') {
                            outputToken(AND, "&&");
                            i += 2;
                        } else {
                            outputError(currentLine, INVALID_CHAR);
                            ++i;
                        }
                        continue;

                    
                    case '|':
                        if (i + 1 < line.size() && line[i + 1] == '|') {
                            outputToken(OR, "||");
                            i += 2;
                        } else {
                            outputError(currentLine, INVALID_CHAR);
                            ++i;
                        }
                        continue;

                    default: 
                        outputError(currentLine, INVALID_CHAR);
                        ++i;
                        continue;
                }
                ++i;
            }
        }
    }
}

int main() {
    
    lexerOut.open("lexer.txt");
    errorOut.open("error.txt");

    
    readFile("testfile.txt");

    
    lexerAnalysis();

    
    lexerOut.close();
    errorOut.close();

    return 0;
}
