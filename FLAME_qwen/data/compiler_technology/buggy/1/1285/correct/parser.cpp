// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>
#include <bits/stdc++.h>
using namespace std;

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 256

FILE *input;
FILE *output;
FILE *error;

//lexical-analysis
char names[14][20] = {"main", "const", "int", "break", "if", "continue", "else", "for", "getint", "printf", "getchar", "return", "void", "char"};
char codes[14][20] = {"MAINTK", "CONSTTK", "INTTK", "BREAKTK", "IFTK", "CONTINUETK", "ELSETK", "FORTK", "GETINTTK", "PRINTFTK", "GETCHARTK", "RETURNTK", "VOIDTK", "CHARTK"};

char curLine[MAX_TOKEN_LENGTH];  // 存放读入的当前行
char token[MAX_LINE_LENGTH];
int curPos = 0;
int inMultLineComment = 0;
char a[20]; 

typedef struct error{
    int lineNum;
    char type;
}Error;

std::vector<Error *> errors;

//grammar-analysis
typedef struct token{
    char token[MAX_TOKEN_LENGTH];
    char symbol[MAX_TOKEN_LENGTH];
    int lineNum;
    
} Token;

std::vector<Token *> tokens;







//lexical-analysis
char* getSym(int lineNum) {
    for(int i = 0; i < 256; i++){
        token[i] = '\0';
    }
    for(int i = 0; i < 20; i++){
        a[i] = '\0';
    }
    int length = strlen(curLine), tokenPos = 0;
    while(curLine[curPos] == ' ' && curPos < length) curPos++;

    if(curPos >= length){
        strcpy(a, "EMPTY_LINE");
        return a;
    }

    if(!inMultLineComment){
        if((curLine[curPos] >= 'a' && curLine[curPos] <= 'z') || (curLine[curPos] >= 'A' && curLine[curPos] <= 'Z') || curLine[curPos] == '_'){
            while((curLine[curPos] >= 'a' && curLine[curPos] <= 'z') || (curLine[curPos] >= 'A' && curLine[curPos] <= 'Z') || (curLine[curPos] >= '0' && curLine[curPos] <= '9') || curLine[curPos] == '_'){
                token[tokenPos++] = curLine[curPos++];
            }
            int flag = 0;
            for(int i = 0; i < 14; i++){
                if(strcmp(token, names[i]) == 0){
                    flag = 1;
                    return codes[i];
                }
            }
            if(flag == 0){
            	strcpy(a, "IDENFR");
                return a;
            }
        }
        else if(curLine[curPos] == '\"'){
            do {
                if(curLine[curPos] == '\\' && curLine[curPos + 1] == '\"'){
                    token[tokenPos++] = curLine[curPos++];
                    token[tokenPos++] = curLine[curPos++];
                }
                else if(curLine[curPos] == '\\' && curLine[curPos + 1] == '\''){
                    token[tokenPos++] = curLine[curPos++];
                    token[tokenPos++] = curLine[curPos++];
                }
                else{
                    token[tokenPos++] = curLine[curPos++];
                }
            } while (curLine[curPos] != '\"');
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "STRCON");
            return a;
        }
        else if(curLine[curPos] == '\''){
            do {
                if(curLine[curPos] == '\\' && curLine[curPos + 1] == '\"'){
                    token[tokenPos++] = curLine[curPos++];
                    token[tokenPos++] = curLine[curPos++];
                }
                else if(curLine[curPos] == '\\' && curLine[curPos + 1] == '\''){
                    token[tokenPos++] = curLine[curPos++];
                    token[tokenPos++] = curLine[curPos++];
                }
                else{
                    token[tokenPos++] = curLine[curPos++];
                }
            } while (curLine[curPos] != '\'');
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "CHRCON");
            return a;
        }
        else if(curLine[curPos] == '/' && curLine[curPos + 1] == '/'){
        	strcpy(a, "SINGLE_LINE_COMMENT");
            return a;
        }
        else if(curLine[curPos] == '/' && curLine[curPos + 1] == '*'){
            curPos += 2;
            while (1) {
                while (curPos < length && curLine[curPos] != '*') curPos++;
                if (curPos >= length) {  // 多行注释不在这行结束
                    inMultLineComment = 1;
                    strcpy(a, "MULTI_LINE_COMMENT");
                    return a;
                } else if (curLine[curPos + 1] == '/') {
                    curPos += 2;
                    strcpy(a, "MULTI_LINE_COMMENT");
                    return a;
                } // else: 单独出现一个*
                curPos++;
            }
        }
        else if(curLine[curPos] >= '0' && curLine[curPos] <= '9'){
            do {
                token[tokenPos++] = curLine[curPos++];
            } while (curLine[curPos] >= '0' && curLine[curPos] <= '9');
            strcpy(a, "INTCON");
            return a;
        }
        else if(curLine[curPos] == '!'){
            token[tokenPos++] = curLine[curPos];
            if (curLine[++curPos] != '='){
            	strcpy(a, "NOT");
                return a;
            }
            else {
                token[tokenPos++] = curLine[curPos++];
                strcpy(a, "NEQ");
                return a;
            }
        }
        else if(curLine[curPos] == '&'){
            if(curLine[curPos + 1] == '&'){
                token[tokenPos++] = curLine[curPos++];
                token[tokenPos++] = curLine[curPos++];
                strcpy(a, "AND");
                return a;
            }
            else{
            	strcpy(a, "ERROR");
                return a;
            }
        }
        else if(curLine[curPos] == '|'){
            if(curLine[curPos + 1] == '|'){
                token[tokenPos++] = curLine[curPos++];
                token[tokenPos++] = curLine[curPos++];
                strcpy(a, "OR");
                return a;
            }
            else{
            	strcpy(a, "ERROR");
                return a;
            }
        }
        else if(curLine[curPos] == '+'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "PLUS");
            return a;
        }
        else if(curLine[curPos] == '-'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "MINU");
            return a;
        }
        else if(curLine[curPos] == '*'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "MULT");
            return a;
        }
        else if(curLine[curPos] == '/'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "DIV");
            return a;
        }
        else if(curLine[curPos] == '%'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "MOD");
            return a;
        }
        else if(curLine[curPos] == '<'){
            token[tokenPos++] = curLine[curPos++];
            if(curLine[curPos] != '='){
            	strcpy(a, "LSS");
                return a;
            }
            else{
                token[tokenPos++] = curLine[curPos++];
                strcpy(a, "LEQ");
                return a;
            }
        }
        else if(curLine[curPos] == '>'){
            token[tokenPos++] = curLine[curPos++];
            if(curLine[curPos] != '='){
            	strcpy(a, "GRE");
                return a;
            }
            else{
                token[tokenPos++] = curLine[curPos++];
                strcpy(a, "GEQ");
                return a;
            }
        }
        else if(curLine[curPos] == '='){
            token[tokenPos++] = curLine[curPos++];
            if(curLine[curPos] != '='){
            	strcpy(a, "ASSIGN");
                return a;
            }
            else{
                token[tokenPos++] = curLine[curPos++];
                strcpy(a, "EQL");
                return a;
            }
        }
        else if(curLine[curPos] == ';'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "SEMICN");
            return a;
        }
        else if(curLine[curPos] == ','){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "COMMA");
            return a;
        }
        else if(curLine[curPos] == '('){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "LPARENT");
            return a;
        }
        else if(curLine[curPos] == ')'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "RPARENT");
            return a;
        }
        else if(curLine[curPos] == '['){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "LBRACK");
            return a;
        }
        else if(curLine[curPos] == ']'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "RBRACK");
            return a;
        }
        else if(curLine[curPos] == '{'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "LBRACE");
            return a;
        }
        else if(curLine[curPos] == '}'){
            token[tokenPos++] = curLine[curPos++];
            strcpy(a, "RBRACE");
            return a;
        }
        else if(curLine[curPos] == '\a' || curLine[curPos] == '\b' || curLine[curPos] == '\t' || curLine[curPos] == '\n' || curLine[curPos] == '\v' || curLine[curPos] == '\f' || curLine[curPos] == '\\' || curLine[curPos] == '\0'){
            strcpy(a, "ELSE");
            return a;
        }
    }
    else{
        while(1){
            while(curPos < length && curLine[curPos] != '*') curPos++;
            if(curPos >= length) {  // 多行注释不在这行结束
                strcpy(a, "MULTI_LINE_COMMENT");
                return a;
            } else if (curLine[curPos + 1] == '/') {
                inMultLineComment = 0;
                curPos += 2;
                strcpy(a, "MULTI_LINE_COMMENT");
                return a;
            } // else: 单独出现一个*
            curPos++;
        }
    }
    strcpy(a, "EMPTY_LINE");
    return a;
}

void parseLine(int lineNum){
    curPos = 0;
    int length = strlen(curLine);
    while(curPos < length){
    	char symbol[20];
    	for(int i = 0; i < 20; i++){
    		symbol[i] = '\0';
		}
		strcpy(symbol, getSym(lineNum));
        if(strcmp(symbol, "SINGLE_LINE_COMMENT") == 0 || strcmp(symbol, "EMPTY_LINE") == 0)
            return;  // 单行注释，后面的也不用看了
        if(strcmp(symbol, "ERROR") == 0){
        	curPos++; 
            //错误输出
            Error *myerror = new Error;
            myerror->lineNum = lineNum;
            myerror->type = 'a';
            errors.push_back(myerror);
            //将&/|也放入tokens
            if(strcpy(token, "&") == 0){
                strcpy(symbol, "AND");
            }
            else{
                strcpy(symbol, "OR");
            }
            Token *mytoken = new Token;
            strcpy(mytoken->symbol, symbol);
            strcpy(mytoken->token, token);
            mytoken->lineNum = lineNum;
            tokens.push_back(mytoken);
        }
        else if(strcmp(symbol, "ELSE") == 0){
        	curPos++;
        }
        else if(strcmp(symbol, "MULTI_LINE_COMMENT") != 0) {
            //将第二次上机的输出注释掉
            //fprintf(output, "%s %s\n", symbol, token);
            Token *mytoken = new Token;
            strcpy(mytoken->symbol, symbol);
            strcpy(mytoken->token, token);
            mytoken->lineNum = lineNum;
            tokens.push_back(mytoken);
        }
    }
}

void lexer() {
    for(int i = 0; i < 1024; i++){
        curLine[i] = '\0';
    }
    int lineNum = 0;
    while (fgets(curLine, MAX_LINE_LENGTH, input) != NULL) {
        lineNum++;
        parseLine(lineNum);
    }
}















//grammar-analysis
//左递归的depth嵌套有问题，需要递归修改！！！！！！！！！！！！！！

int tokenPos = -1;
Token *curToken;

typedef struct node{
    std::vector<struct node *> children;
    struct node *parent;
    int depth;
    Token *token;
    char GrammarItem[MAX_TOKEN_LENGTH];
    
} Node;

void nextItem();
void printParser(Node *root);
void inputParserError(int lineNum, char type);
void parse();
Node *CompUnit(int depth);
Node *Decl(int depth);
Node *Ident(int depth);
Node *IntConst(int depth);
Node *StringConst(int depth);
Node *CharConst(int depth);
Node *ConstDecl(int depth);
Node *BType(int depth);
Node *ConstDef(int depth);
Node *ConstInitVal(int depth);
Node *VarDecl(int depth);
Node *VarDef(int depth);
Node *InitVal(int depth);
Node *FuncDef(int depth);
Node *MainFuncDef(int depth);
Node *FuncType(int depth);
Node *FuncFParams(int depth);
Node *FuncFParam(int depth);
Node *Block(int depth);
Node *BlockItem(int depth);
int semicnFirst();
Node *Stmt(int depth);
Node *ForStmt(int depth);
Node *Exp(int depth);
Node *Cond(int depth);
Node *LVal(int depth);
Node *PrimaryExp(int depth);
Node *Number(int depth);
Node *Character(int depth);
Node *UnaryExp(int depth);
Node *UnaryOp(int depth);
Node *FuncRParams(int depth);
Node *MulExp(int depth);
Node *AddExp(int depth);
Node *RelExp(int depth);
Node *EqExp(int depth);
Node *LAndExp(int depth);
Node *LOrExp(int depth);
Node *ConstExp(int depth);

void nextItem(){
    int tokenLength = tokens.size();
    if (tokenPos < tokenLength - 1) {
        curToken = tokens[++tokenPos];
    } else {
        return;
    }
}

void printParser(Node *root){
    std::vector<Node*> children = root->children;
    int size = children.size();
    if(children.size() > 0){
        for(int i = 0; i < size; i++){
            printParser(children[i]);
        }
    }
    if(children.size() == 0){
        fprintf(output, "%s %s\n", root->token->symbol, root->token->token);
    }
    else if(strcmp(root->GrammarItem, "BlockItem") != 0 && strcmp(root->GrammarItem, "BType") != 0 && strcmp(root->GrammarItem, "Decl") != 0){
        fprintf(output, "<%s>\n", root->GrammarItem);
    }
}

void inputParserError(int lineNum, char type){
    Error *myerror = new Error;
    myerror->lineNum = lineNum;
    myerror->type = type;
    errors.push_back(myerror);
    return;
}

void parse(){
    nextItem();
    Node *root = CompUnit(1);
    printParser(root);
    return;
}

// 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef 
Node *CompUnit(int depth){
    Node *root = new Node;
    strcpy(root->GrammarItem, "CompUnit");
    root->parent = NULL;
    root->depth = depth;
    Node *child = NULL;
    while(strcmp(tokens[tokenPos + 2]->symbol, "LPARENT") != 0){
        child = Decl(depth + 1);
        root->children.push_back(child);
        child->parent = root;
    }
    while(strcmp(tokens[tokenPos + 1]->symbol, "MAINTK") != 0){
        child = FuncDef(depth + 1);
        root->children.push_back(child);
        child->parent = root;
    }
    child = MainFuncDef(depth + 1);
    root->children.push_back(child);
    child->parent = root;
    return root;
}

// 声明 Decl → ConstDecl | VarDecl 
Node *Decl(int depth){
    Node *decl = new Node;
    strcpy(decl->GrammarItem, "Decl");
    decl->depth = depth;
    Node *child = NULL;
    if(strcmp(curToken->symbol, "CONSTTK") == 0){
        child = ConstDecl(depth + 1);
    }
    else{
        child = VarDecl(depth + 1);
    }
    decl->children.push_back(child);
    child->parent = decl;
    return decl;
}

// 标识符 Ident
Node *Ident(int depth){
    Node *ident = new Node;
    ident->token = curToken;
    ident->depth = depth;
    nextItem();

    return ident;
}

// int常量 IntConst
Node *IntConst(int depth){
    Node *intConst = new Node;
    intConst->token = curToken;
    intConst->depth = depth;
    nextItem();

    return intConst;
}

// 字符串常量 StringConst
Node *StringConst(int depth){
    Node *stringConst = new Node;
    stringConst->token = curToken;
    stringConst->depth = depth;
    nextItem();

    return stringConst;
}

// 字符常量 CharConst
Node *CharConst(int depth){
    Node *charConst = new Node;
    charConst->token = curToken;
    charConst->depth = depth;
    nextItem();

    return charConst;
}

// 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
Node *ConstDecl(int depth){
    Node *constDecl = new Node;
    strcpy(constDecl->GrammarItem, "ConstDecl");
    constDecl->depth = depth;
    Node *child = NULL;
    //'const'
    Node *consttk = new Node;
    consttk->token = curToken;
    consttk->parent = constDecl;
    consttk->depth = depth + 1;
    constDecl->children.push_back(consttk);
    nextItem();
    //BType
    child = BType(depth + 1);
    child->parent = constDecl;
    constDecl->children.push_back(child);
    //ConstDef
    child = ConstDef(depth + 1);
    child->parent = constDecl;
    constDecl->children.push_back(child);
    //{ ',' ConstDef }
    while(strcmp(curToken->symbol, "COMMA") == 0){
        Node *comma = new Node;
        comma->token = curToken;
        comma->parent = constDecl;
        comma->depth = depth + 1;
        constDecl->children.push_back(comma);
        nextItem();
        child = ConstDef(depth + 1);
        child->parent = constDecl;
        constDecl->children.push_back(child);
    }
    //';'
    if(strcmp(curToken->symbol, "SEMICN") == 0){
        Node *semicn = new Node;
        semicn->token = curToken;
        semicn->parent = constDecl;
        semicn->depth = depth + 1;
        constDecl->children.push_back(semicn);
        nextItem();
    }
    else{
        Token *token = new Token;
        strcpy(token->token, ";");
        strcpy(token->symbol, "SEMICN");
        token->lineNum = tokens[tokenPos - 1]->lineNum;
        Node *semicn = new Node;
        semicn->token = token;
        semicn->parent = constDecl;
        semicn->depth = depth + 1;
        constDecl->children.push_back(semicn);
        inputParserError(tokens[tokenPos - 1]->lineNum, 'i');
    }

    return constDecl;
}

// 基本类型 BType → 'int' | 'char' 
Node *BType(int depth){
    Node *bType = new Node;
    strcpy(bType->GrammarItem, "BType");
    bType->depth = depth;
    Node *child = new Node;
    child->token = curToken;
    child->parent = bType;
    child->depth = depth + 1;
    bType->children.push_back(child);
    nextItem();

    return bType;
}

// 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
Node *ConstDef(int depth){
    Node *constDef = new Node;
    strcpy(constDef->GrammarItem, "ConstDef");
    constDef->depth = depth;
    Node *child = NULL;
    //Ident
    child = Ident(depth + 1);
    child->parent = constDef;
    constDef->children.push_back(child);
    //{ '[' ConstExp ']' }
    while(strcmp(curToken->symbol, "LBRACK") == 0){
        //'['
        Node *lbrack = new Node;
        lbrack->token = curToken;
        lbrack->parent = constDef;
        lbrack->depth = depth + 1;
        constDef->children.push_back(lbrack);
        nextItem();
        //ConstExp
        child = ConstExp(depth + 1);
        child->parent = constDef;
        constDef->children.push_back(child);
        //']'
        if(strcmp(curToken->symbol, "RBRACK") == 0){
            Node *rbrack = new Node;
            rbrack->token = curToken;
            rbrack->parent = constDef;
            rbrack->depth = depth + 1;
            constDef->children.push_back(rbrack);
            nextItem();
        }
        else{
            Token *token = new Token;
            strcpy(token->token, "]");
            strcpy(token->symbol, "RBRACK");
            token->lineNum = tokens[tokenPos - 1]->lineNum;
            Node *rbrack = new Node;
            rbrack->token = token;
            rbrack->parent = constDef;
            rbrack->depth = depth + 1;
            constDef->children.push_back(rbrack);
            inputParserError(tokens[tokenPos - 1]->lineNum, 'k');
        }
    }
    //'='
    Node *assign = new Node;
    assign->token = curToken;
    assign->parent = constDef;
    assign->depth = depth + 1;
    constDef->children.push_back(assign);
    nextItem();
    //ConstInitVal
    child = ConstInitVal(depth + 1);
    child->parent = constDef;
    constDef->children.push_back(child);

    return constDef;
}

// 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
Node *ConstInitVal(int depth){
    Node *constInitVal = new Node;
    strcpy(constInitVal->GrammarItem, "ConstInitVal");
    constInitVal->depth = depth;
    Node *child = NULL;

    if(strcmp(curToken->symbol, "STRCON") == 0){ //StringConst
        child = StringConst(depth + 1);
        child->parent = constInitVal;
        constInitVal->children.push_back(child);
    }
    else if(strcmp(curToken->symbol, "LBRACE") != 0){ //ConstExp
        child = ConstExp(depth + 1);
        child->parent = constInitVal;
        constInitVal->children.push_back(child);
    }
    else{ //'{' [ ConstExp { ',' ConstExp } ] '}'
        //'{'
        Node *lbrace = new Node;
        lbrace->token = curToken;
        lbrace->parent = constInitVal;
        lbrace->depth = depth + 1;
        constInitVal->children.push_back(lbrace);
        nextItem();
        //
        if(strcmp(curToken->symbol, "RBRACE") != 0){
            //ConstExp
            child = ConstExp(depth + 1);
            child->parent = constInitVal;
            constInitVal->children.push_back(child);
            //{ ',' ConstExp }
            while(strcmp(curToken->symbol, "COMMA") == 0){
                //','
                Node *comma = new Node;
                comma->token = curToken;
                comma->parent = constInitVal;
                comma->depth = depth + 1;
                constInitVal->children.push_back(comma);
                nextItem();
                //ConstExp
                child = ConstExp(depth + 1);
                child->parent = constInitVal;
                constInitVal->children.push_back(child);
            }
        }
        //'}'
        Node *rbrace = new Node;
        rbrace->token = curToken;
        rbrace->parent = constInitVal;
        rbrace->depth = depth + 1;
        constInitVal->children.push_back(rbrace);
        nextItem();
    }

    return constInitVal;
}

// 变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // i
Node *VarDecl(int depth){
    Node *varDecl = new Node;
    strcpy(varDecl->GrammarItem, "VarDecl");
    varDecl->depth = depth;
    Node *child = NULL;
    //BType
    child = BType(depth + 1);
    child->parent = varDecl;
    varDecl->children.push_back(child);
    //VarDef
    child = VarDef(depth + 1);
    child->parent = varDecl;
    varDecl->children.push_back(child);
    //{ ',' VarDef }
    while(strcmp(curToken->symbol, "COMMA") == 0){
        //','
        Node *comma = new Node;
        comma->token = curToken;
        comma->parent = varDecl;
        comma->depth = depth + 1;
        varDecl->children.push_back(comma);
        nextItem();
        //VarDef
        child = VarDef(depth + 1);
        child->parent = varDecl;
        varDecl->children.push_back(child);
    }
    //';'
    if(strcmp(curToken->symbol, "SEMICN") == 0){
        Node *semicn = new Node;
        semicn->token = curToken;
        semicn->parent = varDecl;
        semicn->depth = depth + 1;
        varDecl->children.push_back(semicn);
        nextItem();
    }
    else{
        Token *token = new Token;
        strcpy(token->token, ";");
        strcpy(token->symbol, "SEMICN");
        token->lineNum = tokens[tokenPos - 1]->lineNum;
        Node *semicn = new Node;
        semicn->token = token;
        semicn->parent = varDecl;
        semicn->depth = depth + 1;
        varDecl->children.push_back(semicn);
        inputParserError(tokens[tokenPos - 1]->lineNum, 'i');
    }
    

    return varDecl;
}

// 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
Node *VarDef(int depth){
    Node *varDef = new Node;
    strcpy(varDef->GrammarItem, "VarDef");
    varDef->depth = depth;
    Node *child = NULL;
    //Ident
    child = Ident(depth + 1);
    child->parent = varDef;
    varDef->children.push_back(child);
    //[ '[' ConstExp ']' ]
    if(strcmp(curToken->symbol, "LBRACK") == 0){
        //'['
        Node *lbrack = new Node;
        lbrack->token = curToken;
        lbrack->parent = varDef;
        lbrack->depth = depth + 1;
        varDef->children.push_back(lbrack);
        nextItem();
        //ConstExp
        child = ConstExp(depth + 1);
        child->parent = varDef;
        varDef->children.push_back(child);
        //']'
        if(strcmp(curToken->symbol, "RBRACK") == 0){
            Node *rbrack = new Node;
            rbrack->token = curToken;
            rbrack->parent = varDef;
            rbrack->depth = depth + 1;
            varDef->children.push_back(rbrack);
            nextItem();
        }
        else{
            Token *token = new Token;
            strcpy(token->token, "]");
            strcpy(token->symbol, "RBRACK");
            token->lineNum = tokens[tokenPos - 1]->lineNum;
            Node *rbrack = new Node;
            rbrack->token = token;
            rbrack->parent = varDef;
            rbrack->depth = depth + 1;
            varDef->children.push_back(rbrack);
            inputParserError(tokens[tokenPos - 1]->lineNum, 'k');
        }
        
    }
    if(strcmp(curToken->symbol, "ASSIGN") == 0){ //'=' InitVal
        //'='
        Node *assign = new Node;
        assign->token = curToken;
        assign->parent = varDef;
        assign->depth = depth + 1;
        varDef->children.push_back(assign);
        nextItem();
        //InitVal
        child = InitVal(depth + 1);
        child->parent = varDef;
        varDef->children.push_back(child);
    }

    return varDef;
}

// 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst 
Node *InitVal(int depth){
    Node *initVal = new Node;
    strcpy(initVal->GrammarItem, "InitVal");
    initVal->depth = depth;
    Node *child = NULL;
    if(strcmp(curToken->symbol, "STRCON") == 0){ //StringConst
        child = StringConst(depth + 1);
        child->parent = initVal;
        initVal->children.push_back(child);
    }
    else if(strcmp(curToken->symbol, "LBRACE") == 0){ //'{' [ Exp { ',' Exp } ] '}'
        //'{'
        Node *lbrace = new Node;
        lbrace->token = curToken;
        lbrace->parent = initVal;
        lbrace->depth = depth + 1;
        initVal->children.push_back(lbrace);
        nextItem();
        if(strcmp(curToken->symbol, "RBRACE") != 0){ //[ Exp { ',' Exp } ]
            //EXP
            child = Exp(depth + 1);
            child->parent = initVal;
            initVal->children.push_back(child);
            //{ ',' Exp }
            while(strcmp(curToken->symbol, "COMMA") == 0){
                //','
                Node *comma = new Node;
                comma->token = curToken;
                comma->parent = initVal;
                comma->depth = depth + 1;
                initVal->children.push_back(comma);
                nextItem();
                //Exp
                child = Exp(depth + 1);
                child->parent = initVal;
                initVal->children.push_back(child);
            }
        }
        //'}'
        Node *rbrace = new Node;
        rbrace->token = curToken;
        rbrace->parent = initVal;
        rbrace->depth = depth + 1;
        initVal->children.push_back(rbrace);
        nextItem();
    }
    else{
        //EXP
        child = Exp(depth + 1);
        child->parent = initVal;
        initVal->children.push_back(child);
    }

    return initVal;
}

// 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
Node *FuncDef(int depth){
    Node *funcDef = new Node;
    strcpy(funcDef->GrammarItem, "FuncDef");
    funcDef->depth = depth;
    Node *child = NULL;
    //FuncType
    child = FuncType(depth + 1);
    child->parent = funcDef;
    funcDef->children.push_back(child);
    //Ident
    child = Ident(depth + 1);
    child->parent = funcDef;
    funcDef->children.push_back(child);
    //'('
    Node *lparent = new Node;
    lparent->token = curToken;
    lparent->parent = funcDef;
    lparent->depth = depth + 1;
    funcDef->children.push_back(lparent);
    nextItem();
    //[FuncFParams]
    if(strcmp(curToken->symbol, "INTTK") == 0 || strcmp(curToken->symbol, "CHARTK") == 0){
        //FuncFParams
        child = FuncFParams(depth + 1);
        child->parent = funcDef;
        funcDef->children.push_back(child);
    }
    //')'
    if(strcmp(curToken->symbol, "RPARENT") == 0){
        Node *rparent = new Node;
        rparent->token = curToken;
        rparent->parent = funcDef;
        rparent->depth = depth + 1;
        funcDef->children.push_back(rparent);
        nextItem();
    }
    else{
        Token *token = new Token;
        strcpy(token->token, ")");
        strcpy(token->symbol, "RPARENT");
        token->lineNum = tokens[tokenPos - 1]->lineNum;
        Node *rparent = new Node;
        rparent->token = token;
        rparent->parent = funcDef;
        rparent->depth = depth + 1;
        funcDef->children.push_back(rparent);
        inputParserError(tokens[tokenPos - 1]->lineNum, 'j');
    }
    //Block
    child = Block(depth + 1);
    child->parent = funcDef;
    funcDef->children.push_back(child);

    return funcDef;
}

// 主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block // j
Node *MainFuncDef(int depth){
    Node *mainFuncDef = new Node;
    strcpy(mainFuncDef->GrammarItem, "MainFuncDef");
    mainFuncDef->depth = depth;
    Node *child = NULL;
    //'int'
    Node *inttk = new Node;
    inttk->token = curToken;
    inttk->parent = mainFuncDef;
    inttk->depth = depth + 1;
    mainFuncDef->children.push_back(inttk);
    nextItem();
    //'main'
    Node *maintk = new Node;
    maintk->token = curToken;
    maintk->parent = mainFuncDef;
    maintk->depth = depth + 1;
    mainFuncDef->children.push_back(maintk);
    nextItem();
    //'('
    Node *lparent = new Node;
    lparent->token = curToken;
    lparent->parent = mainFuncDef;
    lparent->depth = depth + 1;
    mainFuncDef->children.push_back(lparent);
    nextItem();
    //')'
    if(strcmp(curToken->symbol, "RPARENT") == 0){
        Node *rparent = new Node;
        rparent->token = curToken;
        rparent->parent = mainFuncDef;
        rparent->depth = depth + 1;
        mainFuncDef->children.push_back(rparent);
        nextItem();
    }
    else{
        Token *token = new Token;
        strcpy(token->token, ")");
        strcpy(token->symbol, "RPARENT");
        token->lineNum = tokens[tokenPos - 1]->lineNum;
        Node *rparent = new Node;
        rparent->token = token;
        rparent->parent = mainFuncDef;
        rparent->depth = depth + 1;
        mainFuncDef->children.push_back(rparent);
        inputParserError(tokens[tokenPos - 1]->lineNum, 'j');
    }
    //Block
    child = Block(depth + 1);
    child->parent = mainFuncDef;
    mainFuncDef->children.push_back(child);

    return mainFuncDef;
}

// 函数类型 FuncType → 'void' | 'int' | 'char'
Node *FuncType(int depth){
    Node *funcType = new Node;
    strcpy(funcType->GrammarItem, "FuncType");
    funcType->depth = depth;
    Node *child = new Node;
    child->token = curToken;
    child->parent = funcType;
    child->depth = depth + 1;
    funcType->children.push_back(child);
    nextItem();

    return funcType;
}

// 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam } 
Node *FuncFParams(int depth){
    Node *funcFParams = new Node;
    strcpy(funcFParams->GrammarItem, "FuncFParams");
    funcFParams->depth = depth;
    Node *child = NULL;
    //FuncFParam
    child = FuncFParam(depth + 1);
    child->parent = funcFParams;
    funcFParams->children.push_back(child);
    //{ ',' FuncFParam }
    while(strcmp(curToken->symbol, "COMMA") == 0){
        //','
        Node *comma = new Node;
        comma->token = curToken;
        comma->parent = funcFParams;
        comma->depth = depth + 1;
        funcFParams->children.push_back(comma);
        nextItem();
        //FuncFParam
        child = FuncFParam(depth + 1);
        child->parent = funcFParams;
        funcFParams->children.push_back(child);
    }

    return funcFParams;
}

// 函数形参 FuncFParam → BType Ident ['[' ']'] // k
Node *FuncFParam(int depth){
    Node *funcFParam = new Node;
    strcpy(funcFParam->GrammarItem, "FuncFParam");
    funcFParam->depth = depth;
    Node *child = NULL;
    //BType
    child = BType(depth + 1);
    child->parent = funcFParam;
    funcFParam->children.push_back(child);
    //Ident
    child = Ident(depth + 1);
    child->parent = funcFParam;
    funcFParam->children.push_back(child);
    //['[' ']']
    if(strcmp(curToken->symbol, "LBRACK") == 0){
        //'['
        Node *lbrack = new Node;
        lbrack->token = curToken;
        lbrack->parent = funcFParam;
        lbrack->depth = depth + 1;
        funcFParam->children.push_back(lbrack);
        nextItem();
        //']'
        if(strcmp(curToken->symbol, "RBRACK") == 0){
            Node *rbrack = new Node;
            rbrack->token = curToken;
            rbrack->parent = funcFParam;
            rbrack->depth = depth + 1;
            funcFParam->children.push_back(rbrack);
            nextItem();
        }
        else{
            Token *token = new Token;
            strcpy(token->token, "]");
            strcpy(token->symbol, "RBRACK");
            token->lineNum = tokens[tokenPos - 1]->lineNum;
            Node *rbrack = new Node;
            rbrack->token = token;
            rbrack->parent = funcFParam;
            rbrack->depth = depth + 1;
            funcFParam->children.push_back(rbrack);
            inputParserError(tokens[tokenPos - 1]->lineNum, 'k');
        }
    }

    return funcFParam;
}

// 语句块 Block → '{' { BlockItem } '}' 
Node *Block(int depth){
    Node *block = new Node;
    strcpy(block->GrammarItem, "Block");
    block->depth = depth;
    Node *child = NULL;
    //'{'
    Node *lbrace = new Node;
    lbrace->token = curToken;
    lbrace->parent = block;
    lbrace->depth = depth + 1;
    block->children.push_back(lbrace);
    nextItem();
    //{ BlockItem }
    while(strcmp(curToken->symbol, "RBRACE") != 0){
        child = BlockItem(depth + 1);
        child->parent = block;
        block->children.push_back(child);
    }
    //'}'
    Node *rbrace = new Node;
    rbrace->token = curToken;
    rbrace->parent = block;
    rbrace->depth = depth + 1;
    block->children.push_back(rbrace);
    nextItem();

    return block;
}

// 语句块项 BlockItem → Decl | Stmt 
Node *BlockItem(int depth){
    Node *blockItem = new Node;
    strcpy(blockItem->GrammarItem, "BlockItem");
    blockItem->depth = depth;
    Node *child = NULL;
    if(strcmp(curToken->symbol, "CONSTTK") == 0 || strcmp(curToken->symbol, "INTTK") == 0 || strcmp(curToken->symbol, "CHARTK") == 0){ //Decl
        child = Decl(depth + 1);
    }
    else{ //Stmt
        child = Stmt(depth + 1);
    }
    child->parent = blockItem;
    blockItem->children.push_back(child);

    return blockItem;
}

int semicnFirst(){
//    int i = tokenPos;
//    while (strcmp(tokens[i]->symbol, "SEMICN") != 0 && strcmp(tokens[i]->symbol, "ASSIGN") != 0)
//        ++i;
//    if (strcmp(tokens[i]->symbol, "SEMICN") == 0)
//        return 1;
//    return 0;
    
    if(strcmp(tokens[tokenPos]->symbol, "IDENFR") == 0 && strcmp(tokens[tokenPos]->symbol, "LPARENT") == 0){
    	return 1;
	}
	if(strcmp(tokens[tokenPos]->symbol, "IDENFR") == 0){
		int i = tokenPos;
		Node *node = LVal(-999);
		if(strcmp(tokens[tokenPos]->symbol, "ASSIGN") == 0){
			tokenPos = i;
			curToken = tokens[tokenPos];
			return 0;
		}
		else{
			tokenPos = i;
			curToken = tokens[tokenPos];
			return 1;
		}
	}
	else{
		return 1;
	}
	
}
    
// 语句 Stmt → LVal '=' Exp ';' // i
// | [Exp] ';' // i
// | Block
// | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
// | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt 
// | 'break' ';' | 'continue' ';' // i
// | 'return' [Exp] ';' // i
// | LVal '=' 'getint''('')'';' // i j
// | LVal '=' 'getchar''('')'';' // i j
// | 'printf''('StringConst {','Exp}')'';' // i j
Node *Stmt(int depth){
    Node *stmt = new Node;
    strcpy(stmt->GrammarItem, "Stmt");
    stmt->depth = depth;
    Node *child = NULL;
    if(strcmp(curToken->symbol, "PRINTFTK") == 0){ //'printf''('StringConst {','Exp}')'';'
        //'printf'
        Node *printftk = new Node;
        printftk->token = curToken;
        printftk->parent = stmt;
        printftk->depth = depth + 1;
        stmt->children.push_back(printftk);
        nextItem();
        //'('
        Node *lparent = new Node;
        lparent->token = curToken;
        lparent->parent = stmt;
        lparent->depth = depth + 1;
        stmt->children.push_back(lparent);
        nextItem();
        //StringConst
        child = StringConst(depth + 1);
        child->parent = stmt;
        stmt->children.push_back(child);
        //{','Exp}
        while(strcmp(curToken->symbol, "COMMA") == 0){
            //','
            Node *comma = new Node;
            comma->token = curToken;
            comma->parent = stmt;
            comma->depth = depth + 1;
            stmt->children.push_back(comma);
            nextItem();
            //Exp
            child = Exp(depth + 1);
            child->parent = stmt;
            stmt->children.push_back(child);
        }
        //')'
        if(strcmp(curToken->symbol, "RPARENT") == 0){
            Node *rparent = new Node;
            rparent->token = curToken;
            rparent->parent = stmt;
            rparent->depth = depth + 1;
            stmt->children.push_back(rparent);
            nextItem();
        }
        else{
            Token *token = new Token;
            strcpy(token->token, ")");
            strcpy(token->symbol, "RPARNET");
            token->lineNum = tokens[tokenPos - 1]->lineNum;
            Node *rparent = new Node;
            rparent->token = token;
            rparent->parent = stmt;
            rparent->depth = depth + 1;
            stmt->children.push_back(rparent);
            inputParserError(tokens[tokenPos - 1]->lineNum, 'j');
        }
        //';'
        if(strcmp(curToken->symbol, "SEMICN") == 0){
            Node *semicn = new Node;
            semicn->token = curToken;
            semicn->parent = stmt;
            semicn->depth = depth + 1;
            stmt->children.push_back(semicn);
            nextItem();
        }
        else{
            Token *token = new Token;
            strcpy(token->token, ";");
            strcpy(token->symbol, "SEMICN");
            token->lineNum = tokens[tokenPos - 1]->lineNum;
            Node *semicn = new Node;
            semicn->token = token;
            semicn->parent = stmt;
            semicn->depth = depth + 1;
            stmt->children.push_back(semicn);
            inputParserError(tokens[tokenPos - 1]->lineNum, 'i');
        }
    }
    else if(strcmp(curToken->symbol, "RETURNTK") == 0){ //'return' [Exp] ';'
        //'return'
        Node *returntk = new Node;
        returntk->token = curToken;
        returntk->parent = stmt;
        returntk->depth = depth + 1;
        stmt->children.push_back(returntk);
        nextItem();
        if(strcmp(curToken->symbol, "IDENFR") == 0 || strcmp(curToken->symbol, "PLUS") == 0 || strcmp(curToken->symbol, "MINU") == 0 || strcmp(curToken->symbol, "NOT") == 0 || strcmp(curToken->symbol, "LPARENT") == 0 || strcmp(curToken->symbol, "INTCON") == 0 || strcmp(curToken->symbol, "CHRCON") == 0){ //[Exp]
            child = Exp(depth + 1);
            child->parent = stmt;
            stmt->children.push_back(child);
        }
        //';'
        if(strcmp(curToken->symbol, "SEMICN") == 0){
            Node *semicn = new Node;
            semicn->token = curToken;
            semicn->parent = stmt;
            semicn->depth = depth + 1;
            stmt->children.push_back(semicn);
            nextItem();
        }
        else{
            Token *token = new Token;
            strcpy(token->token, ";");
            strcpy(token->symbol, "SEMICN");
            token->lineNum = tokens[tokenPos - 1]->lineNum;
            Node *semicn = new Node;
            semicn->token = token;
            semicn->parent = stmt;
            semicn->depth = depth + 1;
            stmt->children.push_back(semicn);
            inputParserError(tokens[tokenPos - 1]->lineNum, 'i');
        }
    }
    else if(strcmp(curToken->symbol, "BREAKTK") == 0 || strcmp(curToken->symbol, "CONTINUETK") == 0){ //'break' ';' | 'continue' ';'
        Node *child = new Node;
        child->token = curToken;
        child->parent = stmt;
        child->depth = depth + 1;
        stmt->children.push_back(child);
        nextItem();
        //';'
        if(strcmp(curToken->symbol, "SEMICN") == 0){
            Node *semicn = new Node;
            semicn->token = curToken;
            semicn->parent = stmt;
            semicn->depth = depth + 1;
            stmt->children.push_back(semicn);
            nextItem();
        }
        else{
            Token *token = new Token;
            strcpy(token->token, ";");
            strcpy(token->symbol, "SEMICN");
            token->lineNum = tokens[tokenPos - 1]->lineNum;
            Node *semicn = new Node;
            semicn->token = token;
            semicn->parent = stmt;
            semicn->depth = depth + 1;
            stmt->children.push_back(semicn);
            inputParserError(tokens[tokenPos - 1]->lineNum, 'i');
        }
    }
    else if(strcmp(curToken->symbol, "FORTK") == 0){ //'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        //'for'
        Node *fortk = new Node;
        fortk->token = curToken;
        fortk->parent = stmt;
        fortk->depth = depth + 1;
        stmt->children.push_back(fortk);
        nextItem();
        //'('
        Node *lparent = new Node;
        lparent->token = curToken;
        lparent->parent = stmt;
        lparent->depth = depth + 1;
        stmt->children.push_back(lparent);
        nextItem();
        if(strcmp(curToken->symbol, "SEMICN") != 0){ //[ForStmt]
            child = ForStmt(depth + 1);
            child->parent = stmt;
            stmt->children.push_back(child);
        }
        //';'
        Node *semicn1 = new Node;
        semicn1->token = curToken;
        semicn1->parent = stmt;
        semicn1->depth = depth + 1;
        stmt->children.push_back(semicn1);
        nextItem();
        if(strcmp(curToken->symbol, "SEMICN") != 0){ //[Cond]
            child = Cond(depth + 1);
            child->parent = stmt;
            stmt->children.push_back(child);
        }
        //';'
        Node *semicn = new Node;
        semicn->token = curToken;
        semicn->parent = stmt;
        semicn->depth = depth + 1;
        stmt->children.push_back(semicn);
        nextItem();
        if(strcmp(curToken->symbol, "RPARENT") != 0){ //[ForStmt]
            child = ForStmt(depth + 1);
            child->parent = stmt;
            stmt->children.push_back(child);
        }
        //')'
        Node *rparent = new Node;
        rparent->token = curToken;
        rparent->parent = stmt;
        rparent->depth = depth + 1;
        stmt->children.push_back(rparent);
        nextItem();
        //Stmt
        child = Stmt(depth + 1);
        child->parent = stmt;
        stmt->children.push_back(child);
    }
    else if(strcmp(curToken->symbol, "IFTK") == 0){ //'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        //'if'
        Node *iftk = new Node;
        iftk->token = curToken;
        iftk->parent = stmt;
        iftk->depth = depth + 1;
        stmt->children.push_back(iftk);
        nextItem();
        //'('
        Node *lparent = new Node;
        lparent->token = curToken;
        lparent->parent = stmt;
        lparent->depth = depth + 1;
        stmt->children.push_back(lparent);
        nextItem();
        //Cond
        child = Cond(depth + 1);
        child->parent = stmt;
        stmt->children.push_back(child);
        //')'
        if(strcmp(curToken->symbol, "RPARENT") == 0){
            Node *rparent = new Node;
            rparent->token = curToken;
            rparent->parent = stmt;
            rparent->depth = depth + 1;
            stmt->children.push_back(rparent);
            nextItem();
        }
        else{
            Token *token = new Token;
            strcpy(token->token, ")");
            strcpy(token->symbol, "RPARNET");
            token->lineNum = tokens[tokenPos - 1]->lineNum;
            Node *rparent = new Node;
            rparent->token = token;
            rparent->parent = stmt;
            rparent->depth = depth + 1;
            stmt->children.push_back(rparent);
            inputParserError(tokens[tokenPos - 1]->lineNum, 'j');
        }
        //Stmt
        child = Stmt(depth + 1);
        child->parent = stmt;
        stmt->children.push_back(child);
        if(strcmp(curToken->symbol, "ELSETK") == 0){ //[ 'else' Stmt ]
            //'else'
            Node *elsetk = new Node;
            elsetk->token = curToken;
            elsetk->parent = stmt;
            elsetk->depth = depth + 1;
            stmt->children.push_back(elsetk);
            nextItem();
            //Stmt
            child = Stmt(depth + 1);
            child->parent = stmt;
            stmt->children.push_back(child);
        }
    }
    else if(strcmp(curToken->symbol, "LBRACE") == 0){ //Block
        //Block
        child = Block(depth + 1);
        child->parent = stmt;
        stmt->children.push_back(child);
    }
    else if(semicnFirst() == 1){ //[Exp] ';'
        if(strcmp(curToken->symbol, "SEMICN") != 0){ //[Exp]
            child = Exp(depth + 1);
            child->parent = stmt;
            stmt->children.push_back(child);
        }
        //';'
        if(strcmp(curToken->symbol, "SEMICN") == 0){
            Node *semicn = new Node;
            semicn->token = curToken;
            semicn->parent = stmt;
            semicn->depth = depth + 1;
            stmt->children.push_back(semicn);
            nextItem();
        }
        else{
            Token *token = new Token;
            strcpy(token->token, ";");
            strcpy(token->symbol, "SEMICN");
            token->lineNum = tokens[tokenPos - 1]->lineNum;
            Node *semicn = new Node;
            semicn->token = token;
            semicn->parent = stmt;
            semicn->depth = depth + 1;
            stmt->children.push_back(semicn);
            inputParserError(tokens[tokenPos - 1]->lineNum, 'i');
        }
    }
    else{ //LVal '=' Exp ';' | LVal '=' 'getint''('')'';' | LVal '=' 'getchar''('')'';'
        //LVal
        child = LVal(depth + 1);
        child->parent = stmt;
        stmt->children.push_back(child);
        //'='
        Node *assign = new Node;
        assign->token = curToken;
        assign->parent = stmt;
        assign->depth = depth + 1;
        stmt->children.push_back(assign);
        nextItem();
        if(strcmp(curToken->symbol, "GETINTTK") == 0){ //LVal '=' 'getint''('')'';'
            //'getint'
            Node *getinttk = new Node;
            getinttk->token = curToken;
            getinttk->parent = stmt;
            getinttk->depth = depth + 1;
            stmt->children.push_back(getinttk);
            nextItem();
            //'('
            Node *lparent = new Node;
            lparent->token = curToken;
            lparent->parent = stmt;
            lparent->depth = depth + 1;
            stmt->children.push_back(lparent);
            nextItem();
            //')'
            if(strcmp(curToken->symbol, "RPARENT") == 0){
                Node *rparent = new Node;
                rparent->token = curToken;
                rparent->parent = stmt;
                rparent->depth = depth + 1;
                stmt->children.push_back(rparent);
                nextItem();
            }
            else{
                Token *token = new Token;
                strcpy(token->token, ")");
                strcpy(token->symbol, "RPARNET");
                token->lineNum = tokens[tokenPos - 1]->lineNum;
                Node *rparent = new Node;
                rparent->token = token;
                rparent->parent = stmt;
                rparent->depth = depth + 1;
                stmt->children.push_back(rparent);
                inputParserError(tokens[tokenPos - 1]->lineNum, 'j');
            }
            //';'
            if(strcmp(curToken->symbol, "SEMICN") == 0){
                Node *semicn = new Node;
                semicn->token = curToken;
                semicn->parent = stmt;
                semicn->depth = depth + 1;
                stmt->children.push_back(semicn);
                nextItem();
            }
            else{
                Token *token = new Token;
                strcpy(token->token, ";");
                strcpy(token->symbol, "SEMICN");
                token->lineNum = tokens[tokenPos - 1]->lineNum;
                Node *semicn = new Node;
                semicn->token = token;
                semicn->parent = stmt;
                semicn->depth = depth + 1;
                stmt->children.push_back(semicn);
                inputParserError(tokens[tokenPos - 1]->lineNum, 'i');
            }
        }
        else if(strcmp(curToken->symbol, "GETCHARTK") == 0){ //LVal '=' 'getchar''('')'';'
            //'getchar'
            Node *getchartk = new Node;
            getchartk->token = curToken;
            getchartk->parent = stmt;
            getchartk->depth = depth + 1;
            stmt->children.push_back(getchartk);
            nextItem();
            //'('
            Node *lparent = new Node;
            lparent->token = curToken;
            lparent->parent = stmt;
            lparent->depth = depth + 1;
            stmt->children.push_back(lparent);
            nextItem();
            //')'
            if(strcmp(curToken->symbol, "RPARENT") == 0){
                Node *rparent = new Node;
                rparent->token = curToken;
                rparent->parent = stmt;
                rparent->depth = depth + 1;
                stmt->children.push_back(rparent);
                nextItem();
            }
            else{
                Token *token = new Token;
                strcpy(token->token, ")");
                strcpy(token->symbol, "RPARNET");
                token->lineNum = tokens[tokenPos - 1]->lineNum;
                Node *rparent = new Node;
                rparent->token = token;
                rparent->parent = stmt;
                rparent->depth = depth + 1;
                stmt->children.push_back(rparent);
                inputParserError(tokens[tokenPos - 1]->lineNum, 'j');
            }
            //';'
            if(strcmp(curToken->symbol, "SEMICN") == 0){
                Node *semicn = new Node;
                semicn->token = curToken;
                semicn->parent = stmt;
                semicn->depth = depth + 1;
                stmt->children.push_back(semicn);
                nextItem();
            }
            else{
                Token *token = new Token;
                strcpy(token->token, ";");
                strcpy(token->symbol, "SEMICN");
                token->lineNum = tokens[tokenPos - 1]->lineNum;
                Node *semicn = new Node;
                semicn->token = token;
                semicn->parent = stmt;
                semicn->depth = depth + 1;
                stmt->children.push_back(semicn);
                inputParserError(tokens[tokenPos - 1]->lineNum, 'i');
            }
        }
        else{ //LVal '=' Exp ';'
            //Exp
            child = Exp(depth + 1);
            child->parent = stmt;
            stmt->children.push_back(child);
            //';'
            if(strcmp(curToken->symbol, "SEMICN") == 0){
                Node *semicn = new Node;
                semicn->token = curToken;
                semicn->parent = stmt;
                semicn->depth = depth + 1;
                stmt->children.push_back(semicn);
                nextItem();
            }
            else{
                Token *token = new Token;
                strcpy(token->token, ";");
                strcpy(token->symbol, "SEMICN");
                token->lineNum = tokens[tokenPos - 1]->lineNum;
                Node *semicn = new Node;
                semicn->token = token;
                semicn->parent = stmt;
                semicn->depth = depth + 1;
                stmt->children.push_back(semicn);
                inputParserError(tokens[tokenPos - 1]->lineNum, 'i');
            }
        }
    }

    return stmt;
}

// 语句 ForStmt → LVal '=' Exp 
Node *ForStmt(int depth){
    Node *forStmt = new Node;
    strcpy(forStmt->GrammarItem, "ForStmt");
    forStmt->depth = depth;
    Node *child = NULL;
    //LVal
    child = LVal(depth + 1);
    child->parent = forStmt;
    forStmt->children.push_back(child);
    //'='
    Node *assign = new Node;
    assign->token = curToken;
    assign->parent = forStmt;
    assign->depth = depth + 1;
    forStmt->children.push_back(assign);
    nextItem();
    //Exp
    child = Exp(depth + 1);
    child->parent = forStmt;
    forStmt->children.push_back(child);

    return forStmt;
}

// 表达式 Exp → AddExp 
Node *Exp(int depth){
    Node *exp = new Node;
    strcpy(exp->GrammarItem, "Exp");
    exp->depth = depth;
    Node *child = NULL;
    //AddExp
    child = AddExp(depth + 1);
    child->parent = exp;
    exp->children.push_back(child);

    return exp;
}
 
// 条件表达式 Cond → LOrExp 
Node *Cond(int depth){
    Node *cond = new Node;
    strcpy(cond->GrammarItem, "Cond");
    cond->depth = depth;
    Node *child = NULL;
    //LOrExp
    child = LOrExp(depth + 1);
    child->parent = cond;
    cond->children.push_back(child);

    return cond;
}

// 左值表达式 LVal → Ident ['[' Exp ']'] // k
Node *LVal(int depth){
    Node *lVal = new Node;
    strcpy(lVal->GrammarItem, "LVal");
    lVal->depth = depth;
    Node *child = NULL;
    //Ident
    child = Ident(depth + 1);
    child->parent = lVal;
    lVal->children.push_back(child);
    if(strcmp(curToken->symbol, "LBRACK") == 0){ //['[' Exp ']']
        //'['
        Node *lbrack = new Node;
        lbrack->token = curToken;
        lbrack->parent = lVal;
        lbrack->depth = depth + 1;
        lVal->children.push_back(lbrack);
        nextItem();
        //Exp
        child = Exp(depth + 1);
        child->parent = lVal;
        lVal->children.push_back(child);
        //']'
        if(strcmp(curToken->symbol, "RBRACK") == 0){
            Node *rbrack = new Node;
            rbrack->token = curToken;
            rbrack->parent = lVal;
            rbrack->depth = depth + 1;
            lVal->children.push_back(rbrack);
            nextItem();
        }
        else{
            Token *token = new Token;
            strcpy(token->token, "]");
            strcpy(token->symbol, "RBRACK");
            token->lineNum = tokens[tokenPos - 1]->lineNum;
            Node *rbrack = new Node;
            rbrack->token = token;
            rbrack->parent = lVal;
            rbrack->depth = depth + 1;
            lVal->children.push_back(rbrack);
        	if(depth >= 0){
        		inputParserError(tokens[tokenPos - 1]->lineNum, 'k');
			}
        }
    }

    return lVal;
}

// 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
Node *PrimaryExp(int depth){
    Node *primaryExp = new Node;
    strcpy(primaryExp->GrammarItem, "PrimaryExp");
    primaryExp->depth = depth;
    Node *child = NULL;
    if(strcmp(curToken->symbol, "LPARENT") == 0){ //'(' Exp ')'
        //'('
        Node *lparent = new Node;
        lparent->token = curToken;
        lparent->parent = primaryExp;
        lparent->depth = depth + 1;
        primaryExp->children.push_back(lparent);
        nextItem();
        //Exp
        child = Exp(depth + 1);
        child->parent = primaryExp;
        primaryExp->children.push_back(child);
        //')'
        if(strcmp(curToken->symbol, "RPARENT") == 0){
            Node *rparent = new Node;
            rparent->token = curToken;
            rparent->parent = primaryExp;
            rparent->depth = depth + 1;
            primaryExp->children.push_back(rparent);
            nextItem();
        }
        else{
            Token *token = new Token;
            strcpy(token->token, ")");
            strcpy(token->symbol, "RPARNET");
            token->lineNum = tokens[tokenPos - 1]->lineNum;
            Node *rparent = new Node;
            rparent->token = token;
            rparent->parent = primaryExp;
            rparent->depth = depth + 1;
            primaryExp->children.push_back(rparent);
        	if(depth >= 0){
        		inputParserError(tokens[tokenPos - 1]->lineNum, 'j');
			}
        }
    }
    else if(strcmp(curToken->symbol, "IDENFR") == 0){ //LVal  (LVal → Ident {'[' Exp ']'})
        child = LVal(depth + 1);
        child->parent = primaryExp;
        primaryExp->children.push_back(child);
    }
    else if(strcmp(curToken->symbol, "INTCON") == 0){ //Number
        child = Number(depth + 1);
        child->parent = primaryExp;
        primaryExp->children.push_back(child);
    }
    else{ //Character
        child = Character(depth + 1);
        child->parent = primaryExp;
        primaryExp->children.push_back(child);
    }

    return primaryExp;
}

// 数值 Number → IntConst 
Node *Number(int depth){
    Node *number = new Node;
    strcpy(number->GrammarItem, "Number");
    number->depth = depth;
    Node *child = NULL;
    //IntConst
    child = IntConst(depth + 1);
    child->parent = number;
    number->children.push_back(child);

    return number;
}
    
// 字符 Character → CharConst 
Node *Character(int depth){
    Node *character = new Node;
    strcpy(character->GrammarItem, "Character");
    character->depth = depth;
    Node *child = NULL;
    //CharConst
    child = CharConst(depth + 1);
    child->parent = character;
    character->children.push_back(child);

    return character;
}

// 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
Node *UnaryExp(int depth){
    Node *unaryExp = new Node;
    strcpy(unaryExp->GrammarItem, "UnaryExp");
    unaryExp->depth = depth;
    Node *child = NULL;
    if(strcmp(curToken->symbol, "PLUS") == 0 || strcmp(curToken->symbol, "MINU") == 0 || strcmp(curToken->symbol, "NOT") == 0){ //UnaryOp UnaryExp
        //UnaryOp
        child = UnaryOp(depth + 1);
        child->parent = unaryExp;
        unaryExp->children.push_back(child);
        //UnaryExp
        child = UnaryExp(depth + 1);
        child->parent = unaryExp;
        unaryExp->children.push_back(child);
    }
    else if(strcmp(curToken->symbol, "IDENFR") == 0 && strcmp(tokens[tokenPos + 1]->symbol, "LPARENT") == 0){ //Ident '(' [FuncRParams] ')'
        //Ident
        child = Ident(depth + 1);
        child->parent = unaryExp;
        unaryExp->children.push_back(child);
        //'('
        Node *lparent = new Node;
        lparent->token = curToken;
        lparent->parent = unaryExp;
        lparent->depth = depth + 1;
        unaryExp->children.push_back(lparent);
        nextItem();
        if(strcmp(curToken->symbol, "IDENFR") == 0 || strcmp(curToken->symbol, "PLUS") == 0 || strcmp(curToken->symbol, "MINU") == 0 || strcmp(curToken->symbol, "NOT") == 0 || strcmp(curToken->symbol, "LPARENT") == 0 || strcmp(curToken->symbol, "INTCON") == 0 || strcmp(curToken->symbol, "CHRCON") == 0){ //[FuncRParams]
            child = FuncRParams(depth + 1);
            child->parent = unaryExp;
            unaryExp->children.push_back(child);
        }
        //')'
        if(strcmp(curToken->symbol, "RPARENT") == 0){
            Node *rparent = new Node;
            rparent->token = curToken;
            rparent->parent = unaryExp;
            rparent->depth = depth + 1;
            unaryExp->children.push_back(rparent);
            nextItem();
        }
        else{
            Token *token = new Token;
            strcpy(token->token, ")");
            strcpy(token->symbol, "RPARNET");
            token->lineNum = tokens[tokenPos - 1]->lineNum;
            Node *rparent = new Node;
            rparent->token = token;
            rparent->parent = unaryExp;
            rparent->depth = depth + 1;
            unaryExp->children.push_back(rparent);
        	if(depth >= 0){
        		inputParserError(tokens[tokenPos - 1]->lineNum, 'j');
			}
        }
    }
    else{ //PrimaryExp
        child = PrimaryExp(depth + 1);
        child->parent = unaryExp;
        unaryExp->children.push_back(child);
    }

    return unaryExp;
}

// 单目运算符 UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中 
Node *UnaryOp(int depth){
    Node *unaryOp = new Node;
    strcpy(unaryOp->GrammarItem, "UnaryOp");
    unaryOp->depth = depth;
    Node *child = new Node;
    child->token = curToken;
    child->parent = unaryOp;
    child->depth = depth + 1;
    unaryOp->children.push_back(child);
    nextItem();

    return unaryOp;
}

// 函数实参表 FuncRParams → Exp { ',' Exp } 
Node *FuncRParams(int depth){
    Node *funcRParams = new Node;
    strcpy(funcRParams->GrammarItem, "FuncRParams");
    funcRParams->depth = depth;
    Node *child = NULL;
    //Exp
    child = Exp(depth + 1);
    child->parent = funcRParams;
    funcRParams->children.push_back(child);
    //{ ',' Exp }
    while(strcmp(curToken->symbol, "COMMA") == 0){
        //','
        Node *comma = new Node;
        comma->token = curToken;
        comma->parent = funcRParams;
        comma->depth = depth + 1;
        funcRParams->children.push_back(comma);
        nextItem();
        //Exp
        child = Exp(depth + 1);
        child->parent = funcRParams;
        funcRParams->children.push_back(child);
    }

    return funcRParams;
}

// 乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp 
// 左递归改写 MulExp -> UnaryExp {('*' | '/' | '%') UnaryExp}
Node *MulExp(int depth){
    Node *mulExp = new Node;
    strcpy(mulExp->GrammarItem, "MulExp");
    mulExp->depth = depth;
    Node *child = NULL;
    //UnaryExp
    child = UnaryExp(depth + 1);
    child->parent = mulExp;
    mulExp->children.push_back(child);
    while(strcmp(curToken->symbol, "MULT") == 0 || strcmp(curToken->symbol, "DIV") == 0 || strcmp(curToken->symbol, "MOD") == 0){ //在发现右侧还有成分时，先将左侧向上打包一层
        Node *temp = new Node;
        strcpy(temp->GrammarItem, "MulExp");
        temp->depth = depth;
        mulExp->parent = temp;
        temp->children.push_back(mulExp);
        mulExp = temp;
        //('*' | '/' | '%')
        Node *child1 = new Node;
        child1->token = curToken;
        child1->parent = mulExp;
        child1->depth = depth + 1;
        mulExp->children.push_back(child1);
        nextItem();
        //UnaryExp
        child = UnaryExp(depth + 1);
        child->parent = mulExp;
        mulExp->children.push_back(child);
    }

    return mulExp;
}

// 加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp 
// 左递归改写 AddExp → MulExp {('+' | '−') MulExp}
Node *AddExp(int depth){
    Node *addExp = new Node;
    strcpy(addExp->GrammarItem, "AddExp");
    addExp->depth = depth;
    Node *child = NULL;
    //MulExp
    child = MulExp(depth + 1);
    child->parent = addExp;
    addExp->children.push_back(child);
    while(strcmp(curToken->symbol, "PLUS") == 0 || strcmp(curToken->symbol, "MINU") == 0){ //在发现右侧还有成分时，先将左侧向上打包一层
        Node *temp = new Node;
        strcpy(temp->GrammarItem, "AddExp");
        temp->depth = depth;
        addExp->parent = temp;
        temp->children.push_back(addExp);
        addExp = temp;
        //('+' | '−')
        Node *child1 = new Node;
        child1->token = curToken;
        child1->parent = addExp;
        child1->depth = depth + 1;
        addExp->children.push_back(child1);
        nextItem();
        //MulExp
        child = MulExp(depth + 1);
        child->parent = addExp;
        addExp->children.push_back(child);
    }

    return addExp;
}

// 关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp 
// 左递归改写 RelExp → AddExp {('<' | '>' | '<=' | '>=') AddExp}
Node *RelExp(int depth){
    Node *relExp = new Node;
    strcpy(relExp->GrammarItem, "RelExp");
    relExp->depth = depth;
    Node *child = NULL;
    //AddExp
    child = AddExp(depth + 1);
    child->parent = relExp;
    relExp->children.push_back(child);
    while(strcmp(curToken->symbol, "LEQ") == 0 || strcmp(curToken->symbol, "LSS") == 0 || strcmp(curToken->symbol, "GEQ") == 0 || strcmp(curToken->symbol, "GRE") == 0){ //在发现右侧还有成分时，先将左侧向上打包一层
        Node *temp = new Node;
        strcpy(temp->GrammarItem, "RelExp");
        temp->depth = depth;
        relExp->parent = temp;
        temp->children.push_back(relExp);
        relExp = temp;
        //('<' | '>' | '<=' | '>=')
        Node *child1 = new Node;
        child1->token = curToken;
        child1->parent = relExp;
        child1->depth = depth + 1;
        relExp->children.push_back(child1);
        nextItem();
        //AddExp
        child = AddExp(depth + 1);
        child->parent = relExp;
        relExp->children.push_back(child);
    }

    return relExp;
}

// 相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp 
// 左递归改写 EqExp → RelExp {('==' | '!=') RelExp}
Node *EqExp(int depth){
    Node *eqExp = new Node;
    strcpy(eqExp->GrammarItem, "EqExp");
    eqExp->depth = depth;
    Node *child = NULL;
    //RelExp
    child = RelExp(depth + 1);
    child->parent = eqExp;
    eqExp->children.push_back(child);
    while(strcmp(curToken->symbol, "EQL") == 0 || strcmp(curToken->symbol, "NEQ") == 0){ //在发现右侧还有成分时，先将左侧向上打包一层
        Node *temp = new Node;
        strcpy(temp->GrammarItem, "EqExp");
        temp->depth = depth;
        eqExp->parent = temp;
        temp->children.push_back(eqExp);
        eqExp = temp;
        //('==' | '!=')
        Node *child1 = new Node;
        child1->token = curToken;
        child1->parent = eqExp;
        child1->depth = depth + 1;
        eqExp->children.push_back(child1);
        nextItem();
        //RelExp
        child = RelExp(depth + 1);
        child->parent = eqExp;
        eqExp->children.push_back(child);
    }

    return eqExp;
}

// 逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
// 左递归改写 LAndExp → EqExp {'&&' EqExp}
Node *LAndExp(int depth){
    Node *lAndExp = new Node;
    strcpy(lAndExp->GrammarItem, "LAndExp");
    lAndExp->depth = depth;
    Node *child = NULL;
    //EqExp
    child = EqExp(depth + 1);
    child->parent = lAndExp;
    lAndExp->children.push_back(child);
    while(strcmp(curToken->symbol, "AND") == 0){ //在发现右侧还有成分时，先将左侧向上打包一层
        Node *temp = new Node;
        strcpy(temp->GrammarItem, "LAndExp");
        temp->depth = depth;
        lAndExp->parent = temp;
        temp->children.push_back(lAndExp);
        lAndExp = temp;
        //'&&'
        Node *child1 = new Node;
        child1->token = curToken;
        child1->parent = lAndExp;
        child1->depth = depth + 1;
        lAndExp->children.push_back(child1);
        nextItem();
        //EqExp
        child = EqExp(depth + 1);
        child->parent = lAndExp;
        lAndExp->children.push_back(child);
    }

    return lAndExp;
}

// 逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
// 左递归改写 LOrExp → LAndExp {'||' LAndExp}
Node *LOrExp(int depth){
    Node *lOrExp = new Node;
    strcpy(lOrExp->GrammarItem, "LOrExp");
    lOrExp->depth = depth;
    Node *child = NULL;
    //LAndExp
    child = LAndExp(depth + 1);
    child->parent = lOrExp;
    lOrExp->children.push_back(child);
    while(strcmp(curToken->symbol, "OR") == 0){ //在发现右侧还有成分时，先将左侧向上打包一层
        Node *temp = new Node;
        strcpy(temp->GrammarItem, "LOrExp");
        temp->depth = depth;
        lOrExp->parent = temp;
        temp->children.push_back(lOrExp);
        lOrExp = temp;
        //'||'
        Node *child1 = new Node;
        child1->token = curToken;
        child1->parent = lOrExp;
        child1->depth = depth + 1;
        lOrExp->children.push_back(child1);
        nextItem();
        //LAndExp
        child = LAndExp(depth + 1);
        child->parent = lOrExp;
        lOrExp->children.push_back(child);
    }

    return lOrExp;
}

// 常量表达式 ConstExp → AddExp 注：使用的 Ident 必须是常量 
Node *ConstExp(int depth){
    Node *constExp = new Node;
    strcpy(constExp->GrammarItem, "ConstExp");
    constExp->depth = depth;
    Node *child = NULL;
    //AddExp
    child = AddExp(depth + 1);
    child->parent = constExp;
    constExp->children.push_back(child);

    return constExp;
}





bool compareErrors(Error *a, Error *b) {
    return a->lineNum < b->lineNum; // 按 lineNum 升序排列
}
void printError(){
    //排序
    std::sort(errors.begin(), errors.end(), compareErrors);
    int size = errors.size();
    for(int i = 0; i < size; i++){
        fprintf(error, "%d %c\n", errors[i]->lineNum, errors[i]->type);
    }
}

int main() {
    input = fopen("testfile.txt", "r");
    output = fopen("parser.txt", "w");
    error = fopen("error.txt", "w");
    lexer();
    parse();

    printError();
    return 0;
}
