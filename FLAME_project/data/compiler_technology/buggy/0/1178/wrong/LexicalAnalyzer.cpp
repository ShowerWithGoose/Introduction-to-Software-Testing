#include "LexicalAnalyzer.h"

static char ch;         // 将读出来的的字符
static string str;   // 读到的字符串
static int lineNum = 1;     // 当前行号
static map<string, LexType> reserveWords;   // 保留字表

Lexer& Lexer::getInstance(std::ifstream &input, std::ofstream &output, std::ofstream &errorFile) {
    static Lexer instance(input, output, errorFile);  // 只创建一次实例
    return instance;
}

Lexer::Lexer(ifstream &input, ofstream &output, ofstream &errorFile)
        : sourceFile(input), outputFile(output), errorFile(errorFile) {
    //读入一个字符
    ch = sourceFile.get();
    // 初始化保留字表
    reserveWords["main"] = LexType::MAINTK;
    reserveWords["const"] = LexType::CONSTTK;
    reserveWords["int"] = LexType::INTTK;
    reserveWords["char"] = LexType::CHARTK;
    reserveWords["break"] = LexType::BREAKTK;
    reserveWords["continue"] = LexType::CONTINUETK;
    reserveWords["if"] = LexType::IFTK;
    reserveWords["else"] = LexType::ELSETK;
    reserveWords["for"] = LexType::FORTK;
    reserveWords["void"] = LexType::VOIDTK;
    reserveWords["getint"] = LexType::GETINTTK;
    reserveWords["getchar"] = LexType::GETCHARTK;
    reserveWords["printf"] = LexType::PRINTFTK;
    reserveWords["return"] = LexType::RETURNTK;
}

void Lexer::next() {
    token.symbol = NULL;
    token.number = 0;
    token.isNumber = 0;

    while (isspace(ch) && ch != '\n')
        ch = sourceFile.get();
    if (ch == '\n'){
        lineNum++;
        ch = sourceFile.get();
        next();
    }
    else if (isdigit(ch)) {                   //数字
        lexType = INTCON;                   //设置单词类别
        str.clear();                      // 清空之前的字符串内容
        str.append(1,ch);           // 将当前数字字符追加到字符串中

        while ((ch = sourceFile.get()) != EOF && isdigit(ch))
            str.append(1,ch);

        token.number = std::stoi(str);            // 将数字字符转化为整数
        token.isNumber = 1;
    }
    else if (isalpha(ch) || ch =='_') {                // 如果是字母字符
        str.clear();                       // 清空之前的字符串内容
        token.symbol = &str;
        str.append(1, ch);                 // 将当前字符追加到字符串中

        // 继续读取字母或数字字符，直到遇到非字母或非数字字符
        while ((ch = sourceFile.get()) != EOF && (isalnum(ch) || ch == '_')) {
            str.append(1, ch);             // 追加字符
        }

        // 检查是否为保留字
        auto it = reserveWords.find(str);  // 查找保留字表
        if (it == reserveWords.end()) {
            lexType = IDENFR;               // 如果不是保留字，标记为标识符
        }
        else {
            lexType = it->second;           // 如果是保留字，设置为相应的保留字类型
        }
    }
    else if (ch == '\"') {      //字符串
        token.symbol = &str;    // 令 token.symbol 指向新读的字符串
        str.clear();            // 清空字符串以备用
        str.append(1, ch);
        ch = sourceFile.get();
        while (ch == 32 || ch == 33 || (ch >= 35 && ch <= 126)) {
            str.append(1, ch);              // 添加字符到字符串
            ch = sourceFile.get();                // 读取下一个字符
        }
        if (ch != '\"') {                   // 如果未遇到结尾的双引号
            lexType = LexType::ILLEGAL;     // 设置为非法类型
            str.clear();
            str.append(1, ch);            // 将非法字符加入 token
        }
        else {
            lexType = LexType::STRCON;    // 字符串类型
            str.append(1, ch);
        }
        ch = sourceFile.get();                // 读取下一个字符备用
    }
    else if (ch == '\'') {                  //字符常量
        str.clear();
        str.append(1, ch);
        ch = sourceFile.get();              // 跳过开头的单引号
        if (ch == '\'' || ch == EOF) {
            lexType = LexType::ILLEGAL;     // 单引号内没有字符或到达文件尾部
            return;
        }

        token.number = ch;          // 将字符的 ASCII 值存入 token.number
        token.symbol = &str;
        str.append(1, ch);
        lexType = LexType::CHRCON;  // 设置为字符常量类型

        ch = sourceFile.get();  // 读取结尾的单引号
        if (ch != '\'') {
            lexType = LexType::ILLEGAL;  // 如果结尾没有单引号，则标记为非法
        }
        str.append(1, ch);
        ch = sourceFile.get();  // 读取下一个字符备用
    }
    else {
        token.symbol = &str;
        str.clear();
        str.append(1, ch);

        switch (ch) {
            // 界符
            case '(':
                lexType = LPARENT;
                break;
            case ')':
                lexType = RPARENT;
                break;
            case '[':
                lexType = LBRACK;
                break;
            case ']':
                lexType = RBRACK;
                break;
            case '{':
                lexType = LBRACE;
                break;
            case '}':
                lexType = RBRACE;
                break;
            case ';':
                lexType = SEMICN;
                break;
            case ',':
                lexType = COMMA;
                break;

                // 运算符
            case '+':
                lexType = PLUS;
                break;
            case '-':
                lexType = MINU;
                break;
            case '*':
                lexType = MULT;
                break;
            case '/':
                ch = sourceFile.peek();         // 查看下一个字符，但不消耗它
                if (ch == '/') {                // 单行注释
                    sourceFile.get();           // 消耗 '/' 字符
                    while (ch != '\n' && ch != EOF) {
                        ch = sourceFile.get();  // 跳过当前行的所有字符
                    }
                    return next();              // 读取下一行的内容
                }
                else if (ch == '*') {           // 多行注释
                    ch = sourceFile.get();      // 跳过 '*' 字符

                    while (true) {
                        if (ch == EOF) {        // 到达文件末尾
                            reportError(lineNum, "Unterminated comment"); // 记录未结束的注释错误
                            return next();      // 继续处理后续内容
                        }

                        // 更新行号
                        if (ch == '\n') {
                            lineNum++;      // 每次遇到换行符，行号加一
                        }

                        // 查找注释结束符
                        if (ch == '*') {
                            ch = sourceFile.get();  // 读取下一个字符
                            if (ch == '/') {        // 检测到结束字符 '/'
                                ch = sourceFile.get();
                                return next();
                            }
                            // 如果下一个字符不是 '/', 则继续循环以查找下一个字符
                        } else {
                            ch = sourceFile.get(); // 继续读取下一个字符
                        }
                    }
                }
                else{
                    lexType = DIV;
                }
                break;
            case '%':
                lexType = MOD;
                break;
            case '!':
                if (sourceFile.peek() == '=') { // '!='
                    ch = sourceFile.get(); // 消费 '='
                    str.append(1, ch);
                    lexType = NEQ;
                }
                else {
                    lexType = NOT;
                }
                break;
            case '&':
                if (sourceFile.peek() == '&') { // '&&'
                    ch = sourceFile.get(); // 消费第二个 '&'
                    str.append(1, ch);
                    lexType = AND;
                }
                else { // 单个 '&' 是非法的
                    lexType = ILLEGAL;
                    reportError(lineNum, "&"); // 记录错误，具体实现视你的需求而定
                }
                break;
            case '|':
                if (sourceFile.peek() == '|') { // '||'
                    ch = sourceFile.get(); // 消费第二个 '|'
                    str.append(1, ch);
                    lexType = OR;
                }
                else { // 单个 '|' 是非法的
                    lexType = ILLEGAL;
                    reportError(lineNum, "|"); // 记录错误
                }
                break;
            case '=':
                if (sourceFile.peek() == '=') { // '=='
                    ch = sourceFile.get(); // 消费第二个 '='
                    str.append(1, ch);
                    lexType = EQL;
                }
                else { // 单个 '='
                    lexType = ASSIGN;
                }
                break;
            case '<':
                if (sourceFile.peek() == '=') { // '<='
                    ch = sourceFile.get(); // 消费 '='
                    str.append(1, ch);
                    lexType = LEQ;
                }
                else if (sourceFile.peek() == '>') { // '<>'
                    ch = sourceFile.get(); // 消费 '>'
                    str.append(1, ch);
                    lexType = NEQ;
                }
                else { // '<'
                    lexType = LSS;
                }
                break;
            case '>':
                if (sourceFile.peek() == '=') { // '>='
                    ch = sourceFile.get(); // 消费 '='
                    str.append(1, ch);
                    lexType = GEQ;
                }
                else { // '>'
                    lexType = GRE;
                }
                break;
            case EOF: // 文件结束
                lexType = FINISH;
                break;
            default: // 其他非法字符
                lexType = ILLEGAL;
                reportError(lineNum, str); // 记录错误
                break;
        }
        ch = sourceFile.get();  // 此处需要再 get 一个新的字符备用
    }
}

string Lexer::getToken() {
    // 返回当前 token 的值，假设 token 是通过 `token.symbol` 来存储的
    if (token.symbol) {
        return *(token.symbol); // 返回指向字符串的内容
    } else {
        if (lexType == CHRCON)
            return string(1, static_cast<char>(token.number));
        return std::to_string(token.number); // 如果是数字，返回数字值
    }
}

string lexTypeToString(LexType type) {
    switch (type) {
        case LexType::ILLEGAL: return "ILLEGAL";
        case LexType::FINISH: return "FINISH";
        case LexType::IDENFR: return "IDENFR";
        case LexType::INTCON: return "INTCON";
        case LexType::STRCON: return "STRCON";
        case LexType::CHRCON: return "CHRCON";

            // 关键字
        case LexType::MAINTK: return "MAINTK";
        case LexType::CONSTTK: return "CONSTTK";
        case LexType::INTTK: return "INTTK";
        case LexType::CHARTK: return "CHARTK";
        case LexType::BREAKTK: return "BREAKTK";
        case LexType::CONTINUETK: return "CONTINUETK";
        case LexType::IFTK: return "IFTK";
        case LexType::ELSETK: return "ELSETK";
        case LexType::FORTK: return "FORTK";
        case LexType::VOIDTK: return "VOIDTK";
        case LexType::GETINTTK: return "GETINTTK";
        case LexType::GETCHARTK: return "GETCHARTK";
        case LexType::PRINTFTK: return "PRINTFTK";
        case LexType::RETURNTK: return "RETURNTK";

            // 运算符和分隔符
        case LexType::NOT: return "NOT";
        case LexType::AND: return "AND";
        case LexType::OR: return "OR";
        case LexType::MULT: return "MULT";
        case LexType::DIV: return "DIV";
        case LexType::MOD: return "MOD";
        case LexType::LSS: return "LSS";
        case LexType::LEQ: return "LEQ";
        case LexType::GRE: return "GRE";
        case LexType::GEQ: return "GEQ";
        case LexType::EQL: return "EQL";
        case LexType::NEQ: return "NEQ";
        case LexType::ASSIGN: return "ASSIGN";
        case LexType::PLUS: return "PLUS";
        case LexType::MINU: return "MINU";

            // 界符
        case LexType::LPARENT: return "LPARENT";
        case LexType::RPARENT: return "RPARENT";
        case LexType::LBRACK: return "LBRACK";
        case LexType::RBRACK: return "RBRACK";
        case LexType::LBRACE: return "LBRACE";
        case LexType::RBRACE: return "RBRACE";
        case LexType::SEMICN: return "SEMICN";
        case LexType::COMMA: return "COMMA";
        default: return "UNKNOWN";
    }
}

string Lexer::getLexType1() {
    return lexTypeToString(lexType);
}

LexType Lexer::getLexType() {
    // 直接返回当前的词法类型
    return lexType;
}


void Lexer::reportError(int line, string errStr) {
    cout << errStr << endl;
    if (!errorFile) {
        std::cerr << "Error opening error.txt file!" << std::endl;
        return;
    }
    errorFile << line << " " << "a" << std::endl; // 按要求写入错误信息
}





