#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>
#include <vector>

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


TokenType isKeyword(const string& word) {
    if (word == "const") return CONSTTK;
    if (word == "int") return INTTK;
    if (word == "char") return CHARTK;
    if (word == "void") return VOIDTK;
    if (word == "main") return MAINTK;
    if (word == "else") return ELSETK;
    if (word == "if") return IFTK;
    if (word == "for") return FORTK;
    if (word == "getint") return GETINTTK;
    if (word == "getchar") return GETCHARTK;
    if (word == "printf") return PRINTFTK;
    if (word == "return") return RETURNTK;
    if (word == "break") return BREAKTK;
    if (word == "continue") return CONTINUETK;
    return IDENFR; 
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
            
            if (isalpha(line[i])) {
                string word;
                while (isalnum(line[i])) {
                    word += line[i++];
                }
                TokenType type = isKeyword(word);
                outputToken(type, word);
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

            else if (line[i] == '\'') {
                string charConst = "'";
                ++i;
                if (i < line.size() && line[i] != '\'' && line[i + 1] == '\'') {
                    charConst += line[i++];
                    charConst += '\'';
                    ++i;
                    outputToken(CHRCON, charConst);
                } else {
                    outputError(currentLine, INVALID_CHAR);
                    ++i;
                }
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
