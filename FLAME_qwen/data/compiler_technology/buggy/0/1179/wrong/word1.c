#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN 100
#define MAX_LINE_LEN 256
#define MAX_VARIABLES 1000
#define MAX_FUNCTIONS 100
#define MAX_PARAMETERS 20
#define ERROR_FILENAME "error.txt"

typedef enum {
    IDENFR = 1, ELSETK, VOIDTK, SEMICN, INTCON, NOT, MULT, COMMA, STRCON, AND, DIV,
    LPARENT, CHRCON, OR, MOD, RPARENT, MAINTK, FORTK, LSS, LBRACK, CONSTTK,
    GETINTTK, LEQ, RBRACK, INTTK, GETCHARTK, GRE, LBRACE, CHARTK, PRINTFTK,
    GEQ, RBRACE, BREAKTK, RETURNTK, EQL, CONTINUETK, PLUS, NEQ, IFTK, MINU, ASSIGN,
    ERROR_TOKEN, UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LEN];
    int lineNumber;
} Token;

typedef struct {
    char name[MAX_TOKEN_LEN];  // 变量名称
    TokenType type;            // 变量类型 (INTTK, CHARTK 等)
    int scopeLevel;            // 作用域层级
    int isConstant;            // 是否为常量 (1 表示是常量, 0 表示不是)
} VariableSymbol;


typedef struct {
    char name[MAX_TOKEN_LEN];        // 函数名称
    TokenType returnType;            // 返回类型 (INTTK, VOIDTK 等)
    int paramCount;                  // 参数个数
    TokenType paramTypes[MAX_PARAMETERS];  // 参数类型列表
} FunctionSymbol;

VariableSymbol variableTable[MAX_VARIABLES];  // 变量表
int variableCount = 0;                        // 变量数量

FunctionSymbol functionTable[MAX_FUNCTIONS];  // 函数表
int functionCount = 0;                        // 函数数量

int currentScopeLevel = 0;  // 当前作用域层级
TokenType currentReturnType = VOIDTK;
int currentFunctionHasReturn = 0;
int cycleDepth = 0;  // 用于标记当前的循环深度
int errorCount = 0;  // 全局错误计数器
int insideFunctionBody = 0;
// 函数声明
void checkTypeA(const char* line, int lineNumber);
void checkTypeC(const char* name, int lineNumber);
void addVariable(const char* name, TokenType type, int lineNumber);
void addFunction(const char* name, TokenType returnType, int paramCount, TokenType paramTypes[], int lineNumber);
int isVariableDefined(const char* name, int scopeLevel);
int isFunctionDefined(const char* name);
void enterScope();
void exitScope();
void PrintError(const char* errorType, int lineNumber);
Token getNextToken(const char* line, int* currentIndex, int lineNumber);
const char* tokenTypeToString(TokenType type);
int isIdentifierStart(char c);
int isIdentifierPart(char c);
int parseFunctionDefinition(const char* line, int* currentIndex, int lineNumber);
int parseFunctionCall(const char* line, int* currentIndex, TokenType* callParamTypes, int lineNumber);
void checkFunctionCall(const char* functionName, TokenType* callParamTypes, int numParams, int lineNumber);
void checkReturnStatement(const char* line, int* currentIndex, int lineNumber);
void checkReturnInLine(const char* line, int lineNumber);
void checkMissingReturn(int lineNumber);
void addVariableWithConstFlag(const char* name, TokenType type, int lineNumber, int isConstant);
void checkAssignment(const char* line, int* currentIndex, int lineNumber);
void checkMissingSemicolon(const char* line, int* currentIndex, int lineNumber);
int checkMissingRightParenthesis(const char* line, int* currentIndex, int lineNumber);
void checkMissingRightBracket(const char* line, int lineNumber);
void checkPrintfFormat(const char* line, int lineNumber);
int main() {
    FILE* inputFile = fopen("testfile.txt", "r");
    if (!inputFile) {
        perror("无法打开输入文件");
        return 1;
    }

    FILE* lexerOutput = fopen("lexer.txt", "w");  // 打开 lexer 输出文件
    if (!lexerOutput) {
        perror("无法创建 lexer 输出文件");
        fclose(inputFile);
        return 1;
    }

    FILE* errorFile = fopen(ERROR_FILENAME, "w");
    if (!errorFile) {
        perror("无法创建错误输出文件");
        fclose(inputFile);
        fclose(lexerOutput);
        return 1;
    }

    Token token;
    int lineNumber = 1;
    char line[MAX_LINE_LEN];
    int currentIndex = 0;
    currentScopeLevel = 0;
    int isConstVar = 0;
    // 第一次循环：进行词法分析并输出结果
    while (fgets(line, sizeof(line), inputFile)) {
        currentIndex = 0;

        // 输出词法分析结果并检查 Token
        while ((token = getNextToken(line, &currentIndex, lineNumber)).type != -1) {
            if (token.type != ERROR_TOKEN && token.type != UNKNOWN) {
                // 将分析结果输出到 lexer 文件
                fprintf(lexerOutput, "%s %s\n", tokenTypeToString(token.type), token.value);
            }
        }
        lineNumber++;
    }
    // 重置文件指针到文件开头
    fseek(inputFile, 0, SEEK_SET);
    lineNumber = 1;
    while (fgets(line, sizeof(line), inputFile)) {
        currentIndex = 0;

        checkTypeA(line, lineNumber);  

        lineNumber++;  
    }

    fclose(inputFile);
    fclose(lexerOutput);
    fclose(errorFile);
    if (errorCount > 0) {
        remove("lexer.txt");
    }

    if (errorCount == 0) {
        remove(ERROR_FILENAME);
    }

    return 0;
}

void checkPrintfFormat(const char* line, int lineNumber) {
    int formatSpecifierCount = 0;  // 统计格式化占位符的个数
    int argumentCount = 0;         // 统计实际传入的参数个数
    int i = 0;
    int inFormatString = 0;        // 标记是否在格式化字符串内
    int parsingArguments = 0;      // 标记是否开始解析参数

    // 遍历整个行，检查 printf 的格式化字符串和参数
    while (line[i] != '\0') {
        if (line[i] == '\"') {
            inFormatString = !inFormatString;  // 切换字符串内外状态
        }

        if (inFormatString && line[i] == '%' && line[i + 1] != '%') {
            // 统计格式化占位符 (排除 '%%')
            formatSpecifierCount++;
        }

        // 检查是否遇到了 '('，表示即将开始解析参数部分
        if (line[i] == '(' && !inFormatString) {
            parsingArguments = 1;  // 开始解析参数
        }

        // 在解析参数阶段，检查逗号，逗号后为参数
        if (parsingArguments && line[i] == ',' && !inFormatString) {
            argumentCount++;  // 统计参数个数
        }

        // 检查是否遇到了 ')' 和 ';'，表示参数解析结束
        if (parsingArguments && line[i] == ')' && !inFormatString) {
            // 右括号标志参数解析结束
            parsingArguments = 0;  // 停止解析参数

            // 检查右括号后面是否直接跟随分号
            while (isspace(line[i + 1])) i++;  // 跳过空白字符
            if (line[i + 1] != ';') {
                PrintError("i", lineNumber);
               
            }
            break;  // 结束循环
        }

        i++;
    }

    // 如果遇到了参数部分并且参数部分不为空
    if (parsingArguments && argumentCount > 0) {
        argumentCount++;  // 实际传入的参数个数，最后一个参数后没有逗号
    }

    // 如果格式化占位符与参数个数不匹配，报告 l 类错误
    if (formatSpecifierCount != argumentCount) {
        PrintError("l", lineNumber);  // 报告 l 类错误
      
    }
}





void checkMissingSemicolon(const char* line, int* currentIndex, int lineNumber) {
    int len = strlen(line);

    // 遍历直到行末，跳过空白和其他字符，找到最后一个有效字符
    while (*currentIndex < len && (isspace(line[*currentIndex]) || line[*currentIndex] != ';')) {
        (*currentIndex)++;
    }

    // 保存当前字符到变量中
    char currentChar = line[*currentIndex];

    // 打印当前字符用于调试
    

    // 如果当前字符不是分号，则报 i 类错误
    if (currentChar != ';') {
        PrintError("i", lineNumber);  // 报告 i 类错误
        
    }
}



// 检查赋值操作中的常量修改 (H 类错误)
void checkAssignment(const char* line, int* currentIndex, int lineNumber) {
    *currentIndex = 0;  // 重置 currentIndex，从行首开始解析

    Token token = getNextToken(line, currentIndex, lineNumber);

    // 检查是否是标识符 (左值)
    if (token.type == IDENFR) {
        char variableName[MAX_TOKEN_LEN];
        strcpy(variableName, token.value);

        // 获取下一个 token，检查是否是赋值符号 '='
        token = getNextToken(line, currentIndex, lineNumber);
        if (token.type == ASSIGN) {
            // 如果是赋值操作，检查左值是否是常量
            for (int i = 0; i < variableCount; i++) {
                if (strcmp(variableTable[i].name, variableName) == 0 && variableTable[i].scopeLevel == currentScopeLevel) {
                    // 如果变量是常量，则报错
                    if (variableTable[i].isConstant) {
                        PrintError("h", lineNumber);  // H 类错误
                       
                    }
                    break;
                }
            }
        }
    }
}


void addVariableWithConstFlag(const char* name, TokenType type, int lineNumber, int isConstant) {
    if (variableCount < MAX_VARIABLES) {
        strcpy(variableTable[variableCount].name, name);
        variableTable[variableCount].type = type;
        variableTable[variableCount].scopeLevel = currentScopeLevel;
        variableTable[variableCount].isConstant = isConstant;  // 设置是否为常量
        variableCount++;

    }
}


void checkMissingReturn(int lineNumber) {
    if (currentReturnType != VOIDTK && currentFunctionHasReturn == 0) {
        PrintError("g", lineNumber);  // G 类错误
     
    }
}

// 解析函数调用，计算参数个数并检查
int parseFunctionCall(const char* line, int* currentIndex, TokenType* callParamTypes, int lineNumber) {
    Token token;
    int paramCount = 0;
    int tempIndex1 = *currentIndex;

    if (checkMissingRightParenthesis(line, &tempIndex1, lineNumber)) {
        return 0;
    }
    // 解析函数调用中的参数
    token = getNextToken(line, currentIndex, lineNumber);
    if (token.type == LPARENT) {  // 确认是函数调用的左括号 '('
        while (1) {
            token = getNextToken(line, currentIndex, lineNumber);
            if (token.type == RPARENT) {  // 参数列表结束，找到右括号 ')'
                break;
            }
            if (token.type == COMMA) {
                continue;  // 跳过逗号
            }
            // 记录参数类型
            callParamTypes[paramCount] = token.type;
            paramCount++;  // 每个非逗号和右括号的 token 都被认为是一个参数
        }
    }
    else {
    }

    return paramCount;
}


// 检查函数调用的参数个数和类型是否匹配
void checkFunctionCall(const char* functionName, TokenType* callParamTypes, int numParams, int lineNumber) {
    for (int i = 0; i < functionCount; i++) {
        // 在函数表中匹配函数名
        if (strcmp(functionTable[i].name, functionName) == 0) {
            // 检查参数个数是否匹配
            if (functionTable[i].paramCount != numParams) {
                PrintError("d", lineNumber);  // 报告 d 类错误（参数个数不匹配）
              
            }
            else {
                // 检查参数类型是否匹配
                for (int j = 0; j < numParams; j++) {
                    if (functionTable[i].paramTypes[j] != callParamTypes[j]) {
                        PrintError("e", lineNumber);  // 报告 e 类错误（参数类型不匹配）
                       
                        return;  // 参数类型不匹配，提前返回
                    }
                }
            
            }
            return;
        }
    }
    // 如果找不到该函数名，抛出未定义错误

}

void checkReturnStatement(const char* line, int* currentIndex, int lineNumber) {
    // 检查是否是 return 语句
    const char* returnPos = strstr(line, "return");

    if (returnPos != NULL) {
        // 移动 currentIndex 到 return 之后的部分
        *currentIndex = returnPos - line + 6;  // 跳过 "return" 的长度

        // 检查 return 后面是否是空的（即 return;）
        const char* afterReturn = line + *currentIndex;

        // 跳过空白字符
        while (isspace(*afterReturn)) {
            afterReturn++;
        }

        // void 函数的处理：return 后面有表达式时报 F 类错误
        if (currentReturnType == VOIDTK) {
            if (*afterReturn != ';') {  // 检查 return 后是否有返回值
                PrintError("f", lineNumber);  // F 类错误
               
            }
        }
        // 非 void 函数的处理：return 后面没有表达式时报 G 类错误
        else if (currentReturnType == INTTK || currentReturnType == CHARTK) {
            if (*afterReturn == ';') {  // 检查 return 后是否直接是分号
                PrintError("g", lineNumber);  // G 类错误
              
            }
            else {
                // return 语句后有值，符合规则
              
            }
        }
    }
}


int checkMissingRightParenthesis(const char* line, int* currentIndex, int lineNumber) {
    // 跳过空格，找到实际的字符
    while (isspace(line[*currentIndex])) {
        (*currentIndex)++;
    }

    // 遍历整行，检查是否有右括号 ')'
    while (line[*currentIndex] != '\0') {
        if (line[*currentIndex] == ')') {
            return 0;  // 找到右括号，返回 0 表示右括号存在
        }
        (*currentIndex)++;
    }

    // 如果遍历到结尾还没有找到右括号，返回 1 表示缺少右括号
    PrintError("j", lineNumber);  // 报告 j 类错误
  
    return 1;  // 缺少右括号
}


// 检查是否是函数定义
int parseFunctionDefinition(const char* line, int* currentIndex, int lineNumber) {
    Token token;
    TokenType paramTypes[MAX_PARAMETERS];
    int paramCount = 0;
    int tempIndex = *currentIndex;

    // 解析返回类型 (int, void, char)
    token = getNextToken(line, &tempIndex, lineNumber);
    TokenType returnType = token.type;


    // 解析函数名
    token = getNextToken(line, &tempIndex, lineNumber);
    if (token.type != IDENFR && strcmp(token.value, "main") != 0) {
        return 0;
    }

    // 保存函数名
    char functionName[MAX_TOKEN_LEN];
    strcpy(functionName, token.value);



    // 解析左括号 '('
    token = getNextToken(line, &tempIndex, lineNumber);
    if (token.type != LPARENT) {
        return 0; // 不是函数定义
    }
    else
    {
        currentFunctionHasReturn = 0;
        currentReturnType = returnType;
    }

    // 解析参数部分
    while (1) {

        int tempIndex1 = *currentIndex;

        if (checkMissingRightParenthesis(line, &tempIndex1, lineNumber)) {
            break;
        }

        // 获取下一个 token
        token = getNextToken(line, &tempIndex, lineNumber);

        // 检查是否是右括号，函数定义结束
        if (token.type == RPARENT) {
            break;
        }

        // 检查参数类型 (int, char)
        if (token.type == INTTK || token.type == CHARTK) {
            paramTypes[paramCount] = token.type;  // 记录参数类型
            paramCount++;

            // 获取参数名
            token = getNextToken(line, &tempIndex, lineNumber);
            if (token.type == IDENFR) {
                // 在添加之前检查重定义
                if (isVariableDefined(token.value, currentScopeLevel)) {
                    PrintError("b", lineNumber);  // 报告重定义错误
                }
                // 添加到变量表
                addVariable(token.value, paramTypes[paramCount - 1], lineNumber);
            }
        }

        // 检查是否是逗号，如果是，则继续解析下一个参数
        if (token.type == COMMA) {
            continue;
        }
    }
    // 检查是否存在左大括号 '{' 表示函数体的开始
    token = getNextToken(line, &tempIndex, lineNumber);
    if (token.type == LBRACE) {
        // 进入函数体，增加作用域
        currentScopeLevel++;
    }
    else {
    }
    // 在添加之前检查函数重定义
    if (isFunctionDefined(functionName)) {
        PrintError("b", lineNumber);  // 报告重定义错误
    }
    // 添加函数到函数表
    addFunction(functionName, returnType, paramCount, paramTypes, lineNumber);
    // 更新索引
    *currentIndex = tempIndex;
    return 1;  // 确认是函数定义
}

void checkMissingRightBracket(const char* line, int lineNumber) {
    int leftBracketCount = 0;
    int rightBracketCount = 0;

    // 遍历行，统计左中括号 '[' 和右中括号 ']' 的数量
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '[') {
            leftBracketCount++;
        }
        else if (line[i] == ']') {
            rightBracketCount++;
        }
    }

    // 如果左中括号数量多于右中括号，则报 k 类错误
    if (leftBracketCount > rightBracketCount) {
        PrintError("k", lineNumber);  // 报告 k 类错误
    }
}

void checkReturnInLine(const char* line, int lineNumber) {
    if (strstr(line, "return") != NULL) {  // 如果该行包含 "return"
        // 找到 "return" 关键字的位置
        const char* returnPos = strstr(line, "return") + 6;  // 跳过 "return"

        // 跳过空白字符
        while (isspace(*returnPos)) {
            returnPos++;
        }

        // 如果 return 后面不是 ; ，则认为是有返回值的 return 语句
        if (*returnPos != ';') {
            currentFunctionHasReturn = 1;  // 标记函数有有效的 return
        }
    }
}

// 仅检查标识符是否在当前作用域中定义
int isIdentifierDefinedInCurrentScope(const char* name, int scopeLevel) {

    if (isVariableDefined(name, scopeLevel)) {
        return 1;
    }

    if (isFunctionDefined(name)) {
        return 1;
    }

    return 0;
}


// 检查非法字符的 A 类错误，仅处理单个 '&' 和 '|' 的非法情况
void checkTypeA(const char* line, int lineNumber) {
    int i = 0;
    FILE* errorFile = fopen(ERROR_FILENAME, "a");
    if (!errorFile) {
        perror("无法打开错误文件");
        return;
    }

    while (line[i] != '\0' && line[i] != '"') {  // 只处理到遇到双引号的部分

        // 检查 '&' 是否与另一个 '&' 结合成合法的 '&&'
        if (line[i] == '&') {
            if (line[i + 1] == '&') {
                i += 2;  // 合法的 '&&'，跳过
            }
            else {
                // 单个 '&' 是非法字符，报告 A 类错误
                fprintf(errorFile, "%d a\n", lineNumber);
                errorCount++;
                break;
            }
        }
        // 检查 '|' 是否与另一个 '|' 结合成合法的 '||'
        else if (line[i] == '|') {
            if (line[i + 1] == '|') {
                i += 2;  // 合法的 '||'，跳过
            }
            else {
                // 单个 '|' 是非法字符，报告 A 类错误
                fprintf(errorFile, "%d a\n", lineNumber);
                errorCount++;
                break;
            }
        }
        else {
            // 其他字符默认合法，继续检查下一个字符
            i++;
        }
    }

    fclose(errorFile);
}


// 检查 C 类错误（标识符未定义）
void checkTypeC(const char* name, int lineNumber) {
    if (!isIdentifierDefinedInCurrentScope(name, currentScopeLevel)) {
        PrintError("c", lineNumber);  // 报告 C 类错误
    }
}


// 添加变量到符号表
void addVariable(const char* name, TokenType type, int lineNumber) {
    if (variableCount < MAX_VARIABLES) {

        strcpy(variableTable[variableCount].name, name);
        variableTable[variableCount].type = type;
        variableTable[variableCount].scopeLevel = currentScopeLevel;
        variableCount++;
      
    }
}

// 添加函数到符号表
void addFunction(const char* name, TokenType returnType, int paramCount, TokenType paramTypes[], int lineNumber) {
    if (functionCount < MAX_FUNCTIONS) {

        strcpy(functionTable[functionCount].name, name);
        functionTable[functionCount].returnType = returnType;
        functionTable[functionCount].paramCount = paramCount;
        memcpy(functionTable[functionCount].paramTypes, paramTypes, paramCount * sizeof(TokenType));
        functionCount++;
      
    }
}

// 检查变量是否已定义
int isVariableDefined(const char* name, int scopeLevel) {
 

    for (int i = 0; i < variableCount; i++) {
        if (strcmp(variableTable[i].name, name) == 0 && variableTable[i].scopeLevel == scopeLevel) {
   
            return 1;
        }
    }
    return 0;
}

// 检查函数是否已定义
int isFunctionDefined(const char* name) {

    for (int i = 0; i < functionCount; i++) {

        if (strcmp(functionTable[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}


// 进入新的作用域
void enterScope() {
    currentScopeLevel++;
}

// 离开作用域
void exitScope() {
    // 移除当前作用域的变量
    for (int i = variableCount - 1; i >= 0; i--) {
        if (variableTable[i].scopeLevel == currentScopeLevel) {
            variableCount--;
        }
    }
    currentScopeLevel--;
}

// 打印错误到错误文件
void PrintError(const char* errorType, int lineNumber) {
    FILE* errorFile = fopen(ERROR_FILENAME, "a");
    if (errorFile) {
        fprintf(errorFile, "%d %s\n", lineNumber, errorType);
        fclose(errorFile);
    }
    errorCount++;
}


Token getNextToken(const char* line, int* currentIndex, int lineNumber) {
    Token token;
    token.type = ERROR_TOKEN;
    token.value[0] = '\0';
    token.lineNumber = lineNumber;

    int i = *currentIndex;
    int len = strlen(line);

    // Skip white spaces
    while (i < len && isspace(line[i])) {
        if (line[i] == '\n') {
            break;
        }
        i++;
    }

    if (i + 1 < len && line[i] == '/' && line[i + 1] == '/') {
        *currentIndex = len;  // Skip the entire line
        token.type = (TokenType)(-1);  // End of line
        return token;
    }

    if (i >= len) {
        token.type = (TokenType)(-1);  // End of line
        *currentIndex = i;
        return token;
    }

    char c = line[i];

    if (isIdentifierStart(c)) {
        // Identifier or keyword
        int start = i;
        i++;
        while (i < len && isIdentifierPart(line[i])) {
            i++;
        }
        int length = i - start;
        if (length >= MAX_TOKEN_LEN) length = MAX_TOKEN_LEN - 1;
        strncpy(token.value, line + start, length);
        token.value[length] = '\0';

        // Check if the token is a keyword
        if (strcmp(token.value, "else") == 0) token.type = ELSETK;
        else if (strcmp(token.value, "void") == 0) token.type = VOIDTK;
        else if (strcmp(token.value, "const") == 0) token.type = CONSTTK;
        else if (strcmp(token.value, "int") == 0) token.type = INTTK;
        else if (strcmp(token.value, "main") == 0) token.type = MAINTK;
        else if (strcmp(token.value, "printf") == 0) token.type = PRINTFTK;
        else if (strcmp(token.value, "return") == 0) token.type = RETURNTK;
        else if (strcmp(token.value, "if") == 0) token.type = IFTK;
        else if (strcmp(token.value, "for") == 0) token.type = FORTK;
        else if (strcmp(token.value, "break") == 0) token.type = BREAKTK;
        else if (strcmp(token.value, "continue") == 0) token.type = CONTINUETK;
        else if (strcmp(token.value, "getint") == 0) token.type = GETINTTK;
        else if (strcmp(token.value, "getchar") == 0) token.type = GETCHARTK;
        else if (strcmp(token.value, "char") == 0) token.type = CHARTK;
        else token.type = IDENFR;  // Otherwise, it's an identifier

        *currentIndex = i;
        return token;
    }

    if (isdigit(c)) {
        // Integer constant
        int start = i;
        i++;
        while (i < len && isdigit(line[i])) {
            i++;
        }
        int length = i - start;
        if (length >= MAX_TOKEN_LEN) length = MAX_TOKEN_LEN - 1;
        strncpy(token.value, line + start, length);
        token.value[length] = '\0';
        token.type = INTCON;

        *currentIndex = i;
        return token;
    }

    // Handle string constant
    if (c == '"') {
        token.value[0] = '"';
        int j = 1;
        i++;
        while (i < len && line[i] != '"') {
            if (j < MAX_TOKEN_LEN - 2) {
                token.value[j++] = line[i++];
            }
            else {
                i++;
            }
        }
        if (i < len && line[i] == '"') {
            token.value[j++] = '"';
            token.value[j] = '\0';
            token.type = STRCON;
            i++;
        }
        else {
            token.type = ERROR_TOKEN;
            strcpy(token.value, "Unclosed string constant");
        }
        *currentIndex = i;
        return token;
    }

    // Handle character constant
    if (c == '\'') {
        token.value[0] = '\'';
        int j = 1;
        i++;
        if (i < len && line[i] != '\'' && line[i] != '\\') {
            token.value[j++] = line[i++];
            if (i < len && line[i] == '\'') {
                token.value[j++] = '\'';
                token.value[j] = '\0';
                token.type = CHRCON;
                i++;
            }
            else {
                token.type = ERROR_TOKEN;
                strcpy(token.value, "Unclosed char constant");
            }
        }
        else if (i < len && line[i] == '\\') {
            token.value[j++] = line[i++];
            if (i < len) {
                token.value[j++] = line[i++];
                if (i < len && line[i] == '\'') {
                    token.value[j++] = '\'';
                    token.value[j] = '\0';
                    token.type = CHRCON;
                    i++;
                }
                else {
                    token.type = ERROR_TOKEN;
                    strcpy(token.value, "Unclosed char constant");
                }
            }
            else {
                token.type = ERROR_TOKEN;
                strcpy(token.value, "Unclosed char constant");
            }
        }
        else {
            token.type = ERROR_TOKEN;
            strcpy(token.value, "Invalid char constant");
        }
        *currentIndex = i;
        return token;
    }

    // Handle other symbols (including illegal ones)
    switch (c) {
    case '%':
        token.type = MOD;  // MOD 对应取模操作符 %
        strcpy(token.value, "%");
        i++;
        break;
    case '!':  // 处理逻辑非运算符
        if (i + 1 < len && line[i + 1] == '=') {
            token.type = NEQ;  // 如果是 '!=', 设置为不等于
            strcpy(token.value, "!=");
            i += 2;
        }
        else {
            token.type = NOT;  // 如果仅是 '!', 设置为逻辑非
            strcpy(token.value, "!");
            i++;
        }
        break;
    case '+':
        token.type = PLUS;
        strcpy(token.value, "+");
        i++;
        break;
    case '-':
        token.type = MINU;
        strcpy(token.value, "-");
        i++;
        break;
    case '*':
        token.type = MULT;
        strcpy(token.value, "*");
        i++;
        break;
    case '/':
        token.type = DIV;
        strcpy(token.value, "/");
        i++;
        break;
    case '(':
        token.type = LPARENT;
        strcpy(token.value, "(");
        i++;
        break;
    case ')':
        token.type = RPARENT;
        strcpy(token.value, ")");
        i++;
        break;
    case '{':
        token.type = LBRACE;
        strcpy(token.value, "{");
        i++;
        break;
    case '}':
        token.type = RBRACE;
        strcpy(token.value, "}");
        i++;
        break;
    case ';':
        token.type = SEMICN;
        strcpy(token.value, ";");
        i++;
        break;
    case ',':
        token.type = COMMA;
        strcpy(token.value, ",");
        i++;
        break;
    case '=':
        if (i + 1 < len && line[i + 1] == '=') {
            token.type = EQL;
            strcpy(token.value, "==");
            i += 2;
        }
        else {
            token.type = ASSIGN;
            strcpy(token.value, "=");
            i++;
        }
        break;
    case '[':
        token.type = LBRACK;
        strcpy(token.value, "[");
        i++;
        break;
    case ']':
        token.type = RBRACK;
        strcpy(token.value, "]");
        i++;
        break;
    case '>':
        if (i + 1 < len && line[i + 1] == '=') {
            token.type = GEQ;  // 大于等于 >=
            strcpy(token.value, ">=");
            i += 2;
        }
        else {
            token.type = GRE;  // 大于 >
            strcpy(token.value, ">");
            i++;
        }
        break;

    case '<':
        if (i + 1 < len && line[i + 1] == '=') {
            token.type = LEQ;  // 小于等于 <=
            strcpy(token.value, "<=");
            i += 2;
        }
        else {
            token.type = LSS;  // 小于 <
            strcpy(token.value, "<");
            i++;
        }
        break;
    case '&': 
        if (i + 1 < len && line[i + 1] == '&') {
            token.type = AND;
            strcpy(token.value, "&&");
            i += 2;
        }
        else {
            token.type = UNKNOWN;
            strcpy(token.value, "&");
            i++;
        }
        break;
    case '|':  
        if (i + 1 < len && line[i + 1] == '|') {
            token.type = OR;
            strcpy(token.value, "||");
            i += 2;
        }
        else {
            token.type = UNKNOWN;
            strcpy(token.value, "|");
            i++;
        }
        break;
    default:
        token.type = UNKNOWN;
        strcpy(token.value, "UNKNOWN");
        i++;
        break;
    }

    *currentIndex = i;
    return token;
}

int isIdentifierStart(char c) {
    return isalpha(c) || c == '_';
}

int isIdentifierPart(char c) {
    return isalnum(c) || c == '_';
}

const char* tokenTypeToString(TokenType type) {
    switch (type) {
    case IDENFR: return "IDENFR";
    case ELSETK: return "ELSETK";
    case VOIDTK: return "VOIDTK";
    case SEMICN: return "SEMICN";
    case INTCON: return "INTCON";
    case NOT: return "NOT";
    case MULT: return "MULT";
    case COMMA: return "COMMA";
    case STRCON: return "STRCON";
    case AND: return "AND";
    case DIV: return "DIV";
    case LPARENT: return "LPARENT";
    case CHRCON: return "CHRCON";
    case OR: return "OR";
    case MOD: return "MOD";
    case RPARENT: return "RPARENT";
    case MAINTK: return "MAINTK";
    case FORTK: return "FORTK";
    case LSS: return "LSS";
    case LBRACK: return "LBRACK";
    case CONSTTK: return "CONSTTK";
    case GETINTTK: return "GETINTTK";
    case LEQ: return "LEQ";
    case RBRACK: return "RBRACK";
    case INTTK: return "INTTK";
    case GETCHARTK: return "GETCHARTK";
    case GRE: return "GRE";
    case LBRACE: return "LBRACE";
    case CHARTK: return "CHARTK";
    case PRINTFTK: return "PRINTFTK";
    case GEQ: return "GEQ";
    case RBRACE: return "RBRACE";
    case BREAKTK: return "BREAKTK";
    case RETURNTK: return "RETURNTK";
    case EQL: return "EQL";
    case CONTINUETK: return "CONTINUETK";
    case PLUS: return "PLUS";
    case NEQ: return "NEQ";
    case IFTK: return "IFTK";
    case MINU: return "MINU";
    case ASSIGN: return "ASSIGN";
    case ERROR_TOKEN: return "ERROR_TOKEN";
    case UNKNOWN: return "UNKNOWN";
    default: return "UNKNOWN";
    }
}
