#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "wordanalyze.h"
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

FILE *getWrongfile;
FILE *outfile;
Token *tokens;
int tokenIndex = 0;
int totalindex;
int printflag=0;
int wrongprintflag = 0;
int First_num = 7;
char First[7][10]={"LPARENT","IDENFR","INTCON","CHRCON",
                         "PLUS","MINU","NOT"};



//// 将词法分析的结果存储
//void getToken(FILE * file){
//    while(fscanf(file, "%d %s", &tokens[tokenIndex].line, tokens[tokenIndex].type) == 2){
//        if(strcmp(tokens[tokenIndex].type, "STRCON") == 0){
//            tokens[tokenIndex].value[0]='"';
//            tokens[tokenIndex].value[1]='\0';
//            char buffer[20];
//            if(fscanf(file, " \"%[^\"]\"", buffer)!=1){
//                printf("get strcon wrong\n");
//            }
//            strcat(tokens[tokenIndex].value, buffer);
//            strcat(tokens[tokenIndex].value, "\"");
//        }
//        else {
//            if(fscanf(file, "%s", tokens[tokenIndex].value)!=1){
//                printf("get value wrong\n");
//            }
//        }
//        tokenIndex++;
//    }
//    totalindex = tokenIndex;
//    tokenIndex=0;
//}


void printToken(Token * token){
    if(printflag) fprintf(outfile,"\n");
    else printflag =1;
    fprintf(outfile,"%s %s",token->type,token->value);
}

// 获取下一个词法单元
Token nextToken() {
    if(tokenIndex>=totalindex) printf("wrong!");
    printToken(&tokens[tokenIndex]);
    return tokens[tokenIndex++];
}
//不打印词法单元
Token no_nextToken(){
    if(tokenIndex>=totalindex) printf("wrong!");
    return tokens[tokenIndex++];
}
void errorprint(int line, char wrong){
    if(wrongprintflag) fprintf(getWrongfile,"\n");
    else wrongprintflag = 1;
    fprintf(getWrongfile,"%d %c",line,wrong);
}
int typeequal(Token * token,char s[]){
    if(strcmp(token->type,s)==0) return 1;
    return 0;
}

int steq(Token *token,char s[]){
    if(strcmp(token->value,s)==0) return 1;
    return 0;
}
// 解析程序
CompUnit * parseProgram() {
    CompUnit *compUnit = malloc(sizeof(CompUnit));
    compUnit->mainFuncDef = malloc(sizeof(MainFuncDef));
    compUnit->decl_count=0;
    compUnit->decls = malloc(100 * sizeof (Decl*));
    compUnit->func_count = 0;
    compUnit->funcs = malloc(100 * sizeof(FuncDef *));
    while (true) {
        Token t = no_nextToken();
        if(tokenIndex>=totalindex) break;
        if (typeequal(&t, "CONSTTK")) {
            printToken(&t);
            compUnit->decls[compUnit->decl_count++] = parseConstDecl();// 处理常量声明
        } else if (typeequal(&t, "INTTK")&&(typeequal(&tokens[tokenIndex], "MAINTK"))) {
            printToken(&t);
            nextToken();
            compUnit->mainFuncDef = parseMainFuncDef(); // 处理主函数定义
        } else if (steq(&t, "void")) {
            tokenIndex--;
            compUnit->funcs[compUnit->func_count++]=parseFuncDef();//处理函数定义
        } else if (typeequal(&t, "INTTK") || typeequal(&t, "CHARTK")) {
            tokenIndex--;
            if(steq(&tokens[tokenIndex + 2], "(")){
                compUnit->funcs[compUnit->func_count++]=parseFuncDef();//处理函数定义
            }
            else{
                compUnit->decls[compUnit->decl_count++] = parseVarDecl(); // 处理变量声明
            }
        }
//        else {
//            // 处理语句
//            Stmt *stmt = parseStmt();
//            if (stmt) {
//                compUnit->stmts[compUnit->stmt_count++] = stmt;
//            }
//        }
    }
    fprintf(outfile,"\n");
    fprintf(outfile,"<CompUnit>");
    return compUnit; // 返回语法树根节点
}

// 解析常量声明
Decl * parseConstDecl() {
    // 常量声明：const BType ConstDef { ',' ConstDef } ';'
    Decl *decl = malloc(sizeof(Decl));
    decl->type = CONSTDECL;
    decl->data.const_decl.const_count = 0;
    decl->data.const_decl.const_defs = malloc(100 * sizeof(ConstDef *));

    Token btypeToken = nextToken(); // 基本类型
//    printToken(&btypeToken);
    strcpy(decl->data.const_decl.btype, btypeToken.value);
    int isstring = 0;
    if(steq(&btypeToken,"char")) isstring = 1;
    Token nexttoken;
    int errorline;
    decl->data.const_decl.const_defs[decl->data.const_decl.const_count++] = parseConstDef(isstring);
    errorline = decl->data.const_decl.const_defs[decl->data.const_decl.const_count-1]->node.lineno;
    nexttoken = no_nextToken();
    while (typeequal(&nexttoken,"COMMA")){
        printToken(&nexttoken);
        decl->data.const_decl.const_defs[decl->data.const_decl.const_count++] = parseConstDef(isstring);
        errorline = decl->data.const_decl.const_defs[decl->data.const_decl.const_count-1]->node.lineno;
        nexttoken = no_nextToken(); // 处理可能的 ','
    }

//    Token semicolonToken = nextToken(); // ';'
    if (!typeequal(&nexttoken,"SEMICN")) {
        tokenIndex--;
        errorprint(errorline,'i');
    }
    else{
        printToken(&nexttoken);
    }
    fprintf(outfile,"\n");
    fprintf(outfile,"<ConstDecl>");
    return decl; // 返回常量声明节点
}

ConstDef *parseConstDef(int isstring){
    Token nexttToken;
    ConstDef *constDef = malloc(sizeof(ConstDef));
    Token identToken = nextToken(); // 标识符
    constDef->node.lineno = identToken.line;
//    printToken(&identToken);
    strcpy(constDef->ident, identToken.value);

    nexttToken = nextToken(); // 可能是 '[' 或 '='
    if (typeequal(&nexttToken,"LBRACK")) {
        // 处理数组维度
//        printToken(&nexttToken);
        constDef->exp = malloc(sizeof(Exp*));
        constDef->exp = parseExp(1); // 假设parseConstExp()函数解析维度
        constDef->isarray = 1;
        nexttToken = nextToken(); // 处理 ']'
        if(!steq(&nexttToken,"]")){
            errorprint(constDef->exp->node.lineno,'k');
        }
        else    nextToken();
    }
    if(constDef->isarray==1&&isstring==1){
        constDef->init_val = parseInitVal(1,1);
    }
    else{
        constDef->init_val = parseInitVal(0,1);
    }// 解析初始化值
    fprintf(outfile,"\n");
    fprintf(outfile,"<ConstDef>");
    return constDef;
}
InitVal *parseInitVal(int isstring,int isconst) {
    // 常量初值：ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}'
    InitVal *initVal = malloc(sizeof(InitVal));
    Token t = no_nextToken();
    initVal->isstring = 0;
    if(isstring&&!steq(&t,"{")){
        printToken(&t);
        initVal->string[0]='\0';
        strcpy(initVal->string,t.value);
        initVal->isstring = 1;
        fprintf(outfile,"\n");
        if(isconst) fprintf(outfile,"<ConstInitVal>");
        else fprintf(outfile,"<InitVal>");
        return initVal; // 返回初始化值节点
    }
    if (steq(&t,"{")) {
        // 处理数组初始化
        printToken(&t);
        initVal->exp_num = 0;
        initVal->exps = malloc(100*sizeof(Exp*)); // 假设是常量表达式节点

        while (true) {
            Token nexttToken = no_nextToken(); // 处理 ',' 或 '}'
            if (steq(&nexttToken,"}") ){
                printToken(&nexttToken);
                break; // 结束数组初始化
            }
            if (steq(&nexttToken,",") ){
                printToken(&nexttToken);
                continue; // 继续数组初始化
            }
            tokenIndex--;
            initVal-> exps[initVal->exp_num++] = parseExp(isconst); // 解析表达式
        }
    } else {
        // 常量表达式
        tokenIndex--;
        initVal->exp_num = 0;
        initVal->exps = malloc(10*sizeof(Exp*)); // 假设是常量表达式节点
        initVal-> exps[initVal->exp_num++] = parseExp(isconst);// 解析常量表达式
    }
    fprintf(outfile,"\n");
    if(isconst) fprintf(outfile,"<ConstInitVal>");
    else fprintf(outfile,"<InitVal>");
    return initVal; // 返回初始化值节点
}


// 解析变量声明
Decl *parseVarDecl() {
    // 变量声明：BType VarDef { ',' VarDef } ';'
    Decl *decl = malloc(sizeof(Decl));
    decl->type = VARDECL;
    decl->data.var_decl.var_count = 0;
    decl->data.var_decl.var_defs = malloc(100 * sizeof(VarDef *));

    Token btypeToken = nextToken(); // 基本类型
//    printToken(&btypeToken);
    strcpy(decl->data.var_decl.btype, btypeToken.value);
    int isstring = 0;
    if(steq(&btypeToken,"char")) isstring = 1;
    Token nexttoken;
    int errorline;
    decl->data.var_decl.var_defs[decl->data.var_decl.var_count++] = parseVarDef(isstring);
    errorline = decl->data.var_decl.var_defs[decl->data.var_decl.var_count-1]->node.lineno;
    nexttoken = no_nextToken();
    while (typeequal(&nexttoken,"COMMA")){
        printToken(&nexttoken);
        decl->data.var_decl.var_defs[decl->data.var_decl.var_count++] = parseVarDef(isstring);
        errorline = decl->data.var_decl.var_defs[decl->data.var_decl.var_count-1]->node.lineno;
        nexttoken = no_nextToken();
    }

    if (!typeequal(&nexttoken,"SEMICN")) {
        tokenIndex--;
        errorprint(errorline,'i');
    }
    else{
        printToken(&nexttoken);
    }
    fprintf(outfile,"\n");
    fprintf(outfile,"<VarDecl>");
    return decl; // 返回常量声明节点
}

VarDef  *parseVarDef(int isstring){//会产生多读入一个逗号的情况
    Token nexttToken;
    VarDef *varDef = malloc(sizeof(VarDef));
    Token identToken = nextToken(); // 标识符
//    printToken(&identToken);
    varDef->node.lineno = identToken.line;
    strcpy(varDef->ident, identToken.value);
    varDef->have_init = 0;
    varDef->isarray = 0;
    nexttToken = no_nextToken(); // 可能是 '[' 或 '='或';'或','
    if(steq)
    if(steq(&nexttToken,";")|| steq(&nexttToken,",")){
        tokenIndex--;
        fprintf(outfile,"\n");
        fprintf(outfile,"<VarDef>");
        return varDef;
    }
    if(!steq(&nexttToken,";")&& !steq(&nexttToken,"=")&& !steq(&nexttToken,"[")){
        tokenIndex--;
        fprintf(outfile,"\n");
        fprintf(outfile,"<VarDef>");
        return varDef;
    }
    if(steq(&nexttToken,"=")){
        tokenIndex--;
    }
    if (typeequal(&nexttToken,"LBRACK")) {
        // 处理数组维度
        printToken(&nexttToken);
        varDef->isarray = 1;
        varDef->exp = malloc(sizeof(Exp*));
        varDef->exp = parseExp(1);
        nexttToken = no_nextToken(); // 处理 ']'
        if(!steq(&nexttToken,"]")){
            tokenIndex--;
            errorprint(varDef->exp->node.lineno,'k');
        }
        else{
            printToken(&nexttToken);
        }
    }
    nexttToken = no_nextToken();
    if(steq(&nexttToken,"=")){
        printToken(&nexttToken);
        varDef->have_init = 1;
        if(varDef->isarray==1&&isstring==1){
            varDef->init_val = parseInitVal(1,0); // 解析初始化值
        }
        else varDef->init_val = parseInitVal(0,0); // 解析初始化值
    }
    else{
        tokenIndex--;
    }
    fprintf(outfile,"\n");
    fprintf(outfile,"<VarDef>");
    return varDef;
}

// 解析函数定义
FuncDef *parseFuncDef() {
    // 函数定义：FuncType Ident '(' [FuncFParams] ')' Block
    FuncDef *funcDef = malloc(sizeof(FuncDef));
    funcDef->params = malloc(10*sizeof(FuncFParam*));
    funcDef->param_num = 0;
    Token ftypeToken = nextToken(); // 函数类型
    strcpy(funcDef->ftype, ftypeToken.value);
    fprintf(outfile,"\n");
    fprintf(outfile,"<FuncType>");
    Token identToken = nextToken(); // 函数名
    strcpy(funcDef->ident, identToken.value);

    int line;
    line =nextToken().line; // '('

    Token rparen = no_nextToken();
    while(true){
        if(steq(&rparen,")")){
            break;
        }
        if(steq(&rparen,",")){
            printToken(&rparen);
            rparen = no_nextToken();
            continue;
        }
        else if(steq(&rparen,"int")|| steq(&rparen,"char")){
            tokenIndex--;
            line = rparen.line;
            funcDef->params[funcDef->param_num++]=parseFuncParam();
        }
        else{
            tokenIndex--;
            errorprint(line,'j');
            break;
        }
        rparen = no_nextToken();
    }
    if(funcDef->param_num!=0){
        fprintf(outfile,"\n");
        fprintf(outfile,"<FuncFParams>");
    }
    printToken(&rparen);
    nextToken();//预先读入'{'
    funcDef->block = parseBlock();
    fprintf(outfile,"\n");
    fprintf(outfile,"<FuncDef>");
    return funcDef;
}

FuncFParam *parseFuncParam() {
    FuncFParam *funcFParam = malloc(sizeof(FuncFParam));
    funcFParam->isarray = 0;
    Token token = nextToken();
    funcFParam->btype[0] = '\0';
    strcpy(funcFParam->btype ,token.value);
    token = nextToken();
    funcFParam->ident[0] = '\0';
    strcpy(funcFParam->ident ,token.value);
    Token left_token = no_nextToken();
    if(steq(&left_token,"[")){
        printToken(&left_token);
        funcFParam->isarray = 1;
        token = no_nextToken();
        if(!steq(&token,"]")){
            tokenIndex--;
            errorprint(left_token.line,'k');
        }
        else{
            printToken(&token);
        }
    }
    else{
        tokenIndex--;
    }
    fprintf(outfile,"\n");
    fprintf(outfile,"<FuncFParam>");
    return funcFParam;
}
// 解析主函数定义
MainFuncDef *parseMainFuncDef() {
    MainFuncDef *mainFuncDef = malloc(sizeof(MainFuncDef));

    int line = nextToken().line; // '('
    Token rparen = no_nextToken(); // ')'
    if (!steq(&rparen,")")) {
        tokenIndex--;
        errorprint(line,'j');
    }
    else {
        printToken(&rparen);
    }
    nextToken(); //预先读入'{'
    mainFuncDef->block = parseBlock(); // 处理主函数体
    fprintf(outfile,"\n");
    fprintf(outfile,"<MainFuncDef>");
    return mainFuncDef;
}

// 解析语句块
Block *parseBlock() {
    // 语句块： '{' { BlockItem } '}'
    //'{'此时已经读入
    Block *block = malloc(sizeof(Block));
    block->blockItems = malloc(100*sizeof(BlockItem*));
    block->blockitem_num = 0;
//        stmt->data.item_num = 0;
//        t = nextToken();
//        while(!steq(&t,"}")){
//            stmt->data.blockitems[stmt->data.item_num++]=parseBlock();
//            t = nextToken();
//        }
    while (true) {
        Token nexttoken = no_nextToken();
        if (steq(&nexttoken, "}")) {
            printToken(&nexttoken);
            break; // 结束块
        } else if(steq(&nexttoken,"const")){
            printToken(&nexttoken);
            block->blockItems[block->blockitem_num] = malloc(sizeof(BlockItem));
            block->blockItems[block->blockitem_num]->type = DECL;
            block->blockItems[block->blockitem_num++]->data.decl = parseConstDecl();
        }else if(steq(&nexttoken,"int")|| steq(&nexttoken,"char")){
            tokenIndex--;
            block->blockItems[block->blockitem_num] = malloc(sizeof(BlockItem));
            block->blockItems[block->blockitem_num]->type = DECL;
            block->blockItems[block->blockitem_num++]->data.decl = parseVarDecl();
        }else{
            tokenIndex--;
            block->blockItems[block->blockitem_num] = malloc(sizeof(BlockItem));
            block->blockItems[block->blockitem_num]->type = STMT;
            block->blockItems[block->blockitem_num]->data.stmt = parseStmt();
        }
    }
    fprintf(outfile,"\n");
    fprintf(outfile,"<Block>");
    return block;
}

Stmt *parseStmt() {
    Token t = no_nextToken();
    Stmt *stmt = malloc(sizeof(Stmt));
    stmt->node.lineno = t.line; // 记录行号

    if (typeequal(&t, "IDENFR")) {
        tokenIndex--;
        int aaa = t.line;
        int in = tokenIndex;
        int flag = 0;
        while(tokens[in].line==aaa){
            if(strcmp(tokens[in].value,"=")==0){
                flag = 1;
                break;
            }
            in++;
        }
        if(flag==0){
            stmt->type = EXP;
            stmt->data.exp = parseExp(0);
        }
        else {
            LVal *lVal = parseLVal();
            Token assign = no_nextToken(); // '='
            printToken(&assign);
            assign = no_nextToken();
            if (steq(&assign, "getint")) {
                printToken(&assign);
                stmt->type = GET;
                stmt->data.getStmt = malloc(sizeof(GetStmt));
                stmt->data.getStmt->lVal = lVal;
                stmt->data.getStmt->type = GETINT;
                assign = nextToken();
                assign = no_nextToken();
                if (!steq(&assign, ")")) {
                    errorprint(lVal->node.lineno, 'j');
                    tokenIndex--;
                } else {
                    printToken(&assign);
                }
            }
            else if(steq(&assign,"getchar")){
                printToken(&assign);
                stmt->type=GET;
                stmt->data.getStmt = malloc(sizeof(GetStmt));
                stmt->data.getStmt->lVal = lVal;
                stmt->data.getStmt->type=GETCHAR;
                assign = nextToken();
                assign = no_nextToken();
                if(!steq(&assign,")")){
                    errorprint(lVal->node.lineno,'j');
                    tokenIndex--;
                }
                else{
                    printToken(&assign);
                }
            }
            else{
                tokenIndex--;
                stmt->type = ASSIGN;
                stmt->data.assign_stmt = malloc(sizeof(AssignStmt));
                stmt->data.assign_stmt->exp = parseExp(0); // 解析表达式
            }
        }
    }else if(steq(&t,"{")) {
        printToken(&t);
        stmt->type = BLOCK;
        stmt->data.block = malloc(sizeof(Block));
        stmt->data.block = parseBlock();
    }else if (typeequal(&t, "IFTK")) {
        printToken(&t);
        stmt->type = IF;
        stmt->node.lineno = t.line;
        stmt->data.if_stmt = malloc(sizeof(IfStmt));
        stmt->data.if_stmt = parseIfStmt(); // 处理if语句
    }  else if (typeequal(&t, "FORTK")) {
        printToken(&t);
        stmt->type = FOR;
        stmt->node.lineno = t.line;
        stmt->data.for_stmt = malloc(sizeof(ForStmt));
        stmt->data.for_stmt = parseForStmt(); // 处理for语句
    } else if (steq(&t, "break")) {
        printToken(&t);
        stmt->node.lineno = t.line;
        stmt->type = BREAK;
        // 处理break语句
    } else if (steq(&t, "continue")) {
        printToken(&t);
        stmt->node.lineno = t.line;
        stmt->type = CONTINUE;
        // 处理continue语句
    } else if (typeequal(&t, "RETURNTK")) {
        printToken(&t);
        stmt->type = RETURN;
        stmt->node.lineno = t.line;
        stmt->data.return_stmt = malloc(sizeof(ReturnStmt));
        stmt->data.return_stmt->node.lineno = t.line;
        stmt->data.return_stmt = parseReturnStmt();
    } else if (typeequal(&t, "PRINTFTK")) {
        printToken(&t);
        stmt->type = PRINT;
        stmt->node.lineno = t.line;
        stmt->data.printf_stmt = malloc(sizeof(PrintfStmt));
        stmt->data.printf_stmt = parsePrintfStmt(); // 处理printf语句
    }else{
        if(!steq(&t,";")){
            tokenIndex--;
            stmt->type = EXP;
            stmt->data.exp = parseExp(0);
        }
        else tokenIndex--;
    }
    if(stmt->type!=BLOCK&&stmt->type!=IF&&stmt->type!=FOR){
        t = no_nextToken();
        if(!steq(&t,";")){
            tokenIndex--;
            errorprint(stmt->node.lineno,'i');
        }
        else printToken(&t);
    }

    fprintf(outfile,"\n");
    fprintf(outfile,"<Stmt>");
    return stmt; // 返回解析后的语句节点
}
IfStmt *parseIfStmt() {
    IfStmt *if_stmt = malloc(sizeof(IfStmt));
    Token t = nextToken(); // '('
    if_stmt->node.lineno = t.line; // 记录行号

    if_stmt->condition = parseLOrExp(); // 解析条件
    fprintf(outfile,"\n");
    fprintf(outfile,"<Cond>");
    Token rparen = no_nextToken(); // ')'
    if (!steq(&rparen, ")")) {
        errorprint(t.line,'j');
        tokenIndex--;
    }
    else{
        printToken(&rparen);
    }
    if_stmt->then_stmt = parseStmt(); // 解析then语句
    Token next = no_nextToken();
    if (typeequal(&next, "ELSETK")) {
        printToken(&next);
        if_stmt->have_else = 1;
        if_stmt->else_stmt = parseStmt(); // 解析else语句
    } else {
        if_stmt->have_else = 0;
        tokenIndex--;
        if_stmt->else_stmt = NULL; // 如果没有else
    }

    return if_stmt; // 返回if语句节点
}
ForStmt *parseForStmt() {
    ForStmt *for_stmt = malloc(sizeof(ForStmt));


    Token t = nextToken(); // '('
    for_stmt->node.lineno = t.line; // 记录行号

    t = no_nextToken();
    if(!steq(&t,";")){
        tokenIndex--;
        for_stmt->forStmt1 = parsegetForStmt(); // 解析循环控制变量
        nextToken();//';'
        for_stmt->have_forStmt1 = 1;
    }
    else {
        for_stmt->have_forStmt1 = 0;
        printToken(&t);
    }
    t = no_nextToken();
    if(!steq(&t,";")){
        tokenIndex--;
        for_stmt->cond = parseLOrExp(); // 解析循环控制变量
        fprintf(outfile,"\n");
        fprintf(outfile,"<Cond>");
        nextToken();//';'
        for_stmt->have_cond = 1;
    }
    else {
        printToken(&t);
        for_stmt->have_cond = 0;
    }


    t = no_nextToken();
    if(!steq(&t,")")){
        tokenIndex--;
        for_stmt->forStmt2 = parsegetForStmt(); // 解析循环控制变量
        nextToken();//')'
        for_stmt->have_forStmt2 = 1;
    }
    else {
        printToken(&t);
        for_stmt->have_forStmt2 = 0;
    }

    for_stmt->stmt = parseStmt(); // 解析循环体
    return for_stmt; // 返回for语句节点
}

For_stmt *parsegetForStmt() {
    For_stmt *result = malloc(sizeof(For_stmt));
    result->lVal = parseLVal();
    nextToken();//'='
    result->exp = parseExp(0);
    fprintf(outfile,"\n");
    fprintf(outfile,"<ForStmt>");
    return result;
}

Exp * parseExp(int isconst) {
    Exp *exp = parseAddExp();
    fprintf(outfile,"\n");
    if(isconst){
        fprintf(outfile,"<ConstExp>");
    }
    else fprintf(outfile,"<Exp>");
    return exp; // 解析加减表达式
}

Exp *parseAddExp() {
    Exp *lhs = parseMulExp(); // 解析乘除模表达式
    while (true) {
        Token t = no_nextToken();
        fprintf(outfile,"\n");
        fprintf(outfile,"<AddExp>");
        if (steq(&t, "+") || steq(&t, "-")) {
            printToken(&t);
            Exp *addExp = malloc(sizeof(Exp));
            addExp->node.lineno = t.line;
            addExp->type = BINARY;
            addExp->data.binaryExp.type = ADD;
            strcpy(addExp->data.binaryExp.data.op,t.value);
            addExp->data.binaryExp.data.lhs = lhs;
            addExp->data.binaryExp.data.rhs = parseMulExp(); // 解析右操作数
            lhs = addExp; // 将结果作为新的左操作数
        } else {
            tokenIndex--; // 非加减操作符，回退
            break;
        }
    }
    return lhs;
}


Exp *parseMulExp() {
    Exp *lhs = parseUnaryExp(); // 解析左操作数
    while (true) {
        Token t = no_nextToken();
        fprintf(outfile,"\n");
        fprintf(outfile,"<MulExp>");
        if (steq(&t, "*") || steq(&t, "/") || steq(&t, "%")) {
            printToken(&t);
            Exp *mulExp = malloc(sizeof(Exp));
            mulExp->node.lineno = t.line;
            mulExp->type = BINARY;
            mulExp->data.binaryExp.type = MUL;
            mulExp->data.binaryExp.data.lhs = lhs;
            strcpy(mulExp->data.binaryExp.data.op,t.value);
            mulExp->data.binaryExp.data.rhs = parseUnaryExp(); // 解析右操作数
            lhs = mulExp; // 将结果作为新的左操作数
        } else {
            tokenIndex--; // 如果不是乘除模运算符，将token放回
            break;
        }
    }
    return lhs;
}

Exp * parseUnaryExp() {
    Token t = no_nextToken();
    Exp *exp = malloc(sizeof(Exp));
    UnaryExp unaryExp;
    exp->type = UNARY;
    exp->node.lineno = t.line;

    if (typeequal(&t, "IDENFR")) {
        if (steq(&tokens[tokenIndex], "(")) {
            printToken(&t);
            nextToken();//读取打印'('
            unaryExp.kind = FUNC_CALL;
            strcpy(unaryExp.data.func_call.ident, t.value); // 函数名

            // 解析函数参数
            unaryExp.data.func_call.param_count = 0;
            unaryExp.data.func_call.func_params = malloc(10 * sizeof(Exp *)); // 假设最多10个参数
            Token paramToken = no_nextToken();
            int errorline = paramToken.line;
            int flag = 0;
            int flag1= 0;
            while(true){
                flag = 0;
                if(steq(&paramToken,",")){
                    printToken(&paramToken);
                    paramToken = no_nextToken();
                    continue;
                }
                if(steq(&paramToken,")")){
//                    printToken(&paramToken);
                    break;
                }
                flag1 =1;
                for(int i=0;i<First_num;i++){
                    if(strcmp(paramToken.type,First[i])==0){
                        flag =1;
                        break;
                    }
                }
                if(flag){
                    tokenIndex--;
                    unaryExp.data.func_call.func_params[unaryExp.data.func_call.param_count++] = parseExp(0);
                    errorline = unaryExp.data.func_call.func_params[unaryExp.data.func_call.param_count-1]->node.lineno;
                    paramToken = no_nextToken();
                }
                else break;
            }
            if(!steq(&paramToken,")")){
                tokenIndex--;
                errorprint(errorline,'j');
            }
            if(flag1){
                fprintf(outfile,"\n");
                fprintf(outfile,"<FuncRParams>");
            }
            if(steq(&paramToken,")")){
                printToken(&paramToken);
            }
        } else {
            tokenIndex--; // 回退Token，处理为左值
            unaryExp.kind = PRIMARY;
            unaryExp.data.primary = parsePrimaryExp();
        }
    } else if (typeequal(&t, "PLUS") || typeequal(&t, "MINU")|| steq(&t,"!")) {
        printToken(&t);
        unaryExp.kind = OP;
        unaryExp.data.unary_op.op = t.value[0]; // 存储运算符
        fprintf(outfile,"\n");
        fprintf(outfile,"<UnaryOp>");
        unaryExp.data.unary_op.unary_exp = parseUnaryExp(); // 递归解析
    } else {
        tokenIndex--;
        unaryExp.kind = PRIMARY;
        unaryExp.data.primary = parsePrimaryExp();
    }
    exp->data.unaryExp = unaryExp;
    fprintf(outfile,"\n");
    fprintf(outfile,"<UnaryExp>");
    return exp;
}


Exp *parsePrimaryExp() {
    Token t = no_nextToken();
    Exp *exp = malloc(sizeof(Exp));
    exp->node.lineno = t.line;
    exp->type = PRI;
    PrimaryExp *primaryExp = malloc(sizeof(PrimaryExp));
    primaryExp->node.lineno = t.line;

    if (steq(&t, "(")) {
        printToken(&t);
        primaryExp->kind = PARENTHESIS;
        primaryExp->data.exp = parseExp(0); // 解析括号中的表达式

        Token closing = nextToken();
        if (!steq(&closing, ")")) {
            tokenIndex--;
            errorprint(primaryExp->data.exp->node.lineno,'j');
            exp->data.primaryExp = *primaryExp;
            fprintf(outfile,"\n");
            fprintf(outfile,"<PrimaryExp>");
            return exp;
        }
    } else if (typeequal(&t, "IDENFR")) {
        tokenIndex--;
        primaryExp->kind = LVAL;
        primaryExp->data.lval = parseLVal(); // 解析左值表达式
    } else if (typeequal(&t, "INTCON")) {
        printToken(&t);
        primaryExp->kind = NUMBER;
        primaryExp->data.number.value = atoi(t.value);
        fprintf(outfile,"\n");
        fprintf(outfile,"<Number>");
    } else if (typeequal(&t, "CHRCON")) {
        printToken(&t);
        primaryExp->kind = CHAR;
        primaryExp->data.character.value = t.value[1]; // 假设值是字符
        fprintf(outfile,"\n");
        fprintf(outfile,"<Character>");
    }
    exp->data.primaryExp = *primaryExp;
    fprintf(outfile,"\n");
    fprintf(outfile,"<PrimaryExp>");
    return exp;
}
LVal *parseLVal() {
    Token t = nextToken();

    LVal *lval = malloc(sizeof(LVal));
    lval->node.lineno = t.line;
    lval->isarray = 0;
    strcpy(lval->ident, t.value); // 存储标识符

    Token next = no_nextToken();
    if (steq(&next, "[")) {
        printToken(&next);
        lval->isarray = 1;
        lval->exp = parseExp(0); // 解析数组索引
        Token closing = no_nextToken();
        if (!steq(&closing, "]")) {
            errorprint(lval->exp->node.lineno,'k');
            tokenIndex--;
        }
        else printToken(&closing);
    } else {
        tokenIndex--;
        lval->exp = NULL; // 非数组情况
    }
    fprintf(outfile,"\n");
    fprintf(outfile,"<LVal>");
    return lval;
}
Exp *parseRelExp() {
    Exp *lhs = parseAddExp(); // 解析左操作数（加减表达式）

    while (true) {
        Token t = no_nextToken(); // 获取下一个符号
        fprintf(outfile,"\n");
        fprintf(outfile,"<RelExp>");
        if (steq(&t, "<") || steq(&t, ">") || steq(&t, "<=") || steq(&t, ">=")) {
            printToken(&t);
            Exp *relExp = malloc(sizeof(Exp));
            relExp->node.lineno = t.line;
            relExp->type = BINARY; 
            relExp->data.binaryExp.type = REL;// 设置为关系表达式类型
            relExp->data.binaryExp.data.lhs = lhs; // 左操作数

            // 解析右操作数（加减表达式）
            relExp->data.binaryExp.data.rhs = parseAddExp();
            strcpy(relExp->data.binaryExp.data.op, t.value); // 设置运算符

            lhs = relExp; // 关系表达式成为新的左操作数
        } else {
            tokenIndex--; // 不是关系运算符，回退Token
            break;
        }
    }
    return lhs;
}
Exp *parseEqExp(){
    Exp *lhs = parseRelExp(); // 解析左操作数（关系表达式）

    while (true) {
        Token t = no_nextToken(); // 获取下一个符号
        fprintf(outfile,"\n");
        fprintf(outfile,"<EqExp>");
        if (steq(&t, "==") || steq(&t, "!=")) {
            printToken(&t);
            Exp *eqExp = malloc(sizeof(Exp));
            eqExp->node.lineno = t.line;
            eqExp->type = BINARY;
            eqExp->data.binaryExp.type = EQ;// 设置为关系表达式类型
            eqExp->data.binaryExp.data.lhs = lhs; // 左操作数

            // 解析右操作数（关系表达式）
            eqExp->data.binaryExp.data.rhs = parseRelExp();
            strcpy(eqExp->data.binaryExp.data.op, t.value); // 设置运算符

            lhs = eqExp; // 关系表达式成为新的左操作数
        } else {
            tokenIndex--; // 不是关系运算符，回退Token
            break;
        }
    }
    return lhs;
}
Exp *parseLAndExp(){
    Exp *lhs = parseEqExp(); // 解析左操作数（相等性表达式）

    while (true) {
        Token t = no_nextToken(); // 获取下一个符号
        fprintf(outfile,"\n");
        fprintf(outfile,"<LAndExp>");
        if (steq(&t, "&&")||steq(&t, "&")) {
            if(steq(&t, "&")){
                strcpy(t.value,"&");
                errorprint(t.line,'a');
            }
            printToken(&t);
            Exp *landExp = malloc(sizeof(Exp));
            landExp->node.lineno = t.line;
            landExp->type = BINARY;
            landExp->data.binaryExp.type = LAND;// 设置为逻辑与表达式类型
            landExp->data.binaryExp.data.lhs = lhs; // 左操作数

            // 解析右操作数（关系表达式）
            landExp->data.binaryExp.data.rhs = parseEqExp();
            strcpy(landExp->data.binaryExp.data.op, t.value); // 设置运算符

            lhs = landExp; // 关系表达式成为新的左操作数
        } else {
            tokenIndex--; // 不是关系运算符，回退Token
            break;
        }
    }
    return lhs;
}
Exp *parseLOrExp(){
    Exp *lhs = parseLAndExp(); // 解析左操作数（逻辑与表达式）

    while (true) {
        Token t = no_nextToken(); // 获取下一个符号
        fprintf(outfile,"\n");
        fprintf(outfile,"<LOrExp>");
        if (steq(&t, "||")||steq(&t,"|")) {
            if(steq(&t,"|")){
                strcpy(t.value,"|");
                errorprint(t.line,'a');
            }
            printToken(&t);
            Exp *lorExp = malloc(sizeof(Exp));
            lorExp->node.lineno = t.line;
            lorExp->type = BINARY;
            lorExp->data.binaryExp.type = LOR;// 设置为逻辑与表达式类型
            lorExp->data.binaryExp.data.lhs = lhs; // 左操作数

            // 解析右操作数（逻辑与表达式）
            lorExp->data.binaryExp.data.rhs = parseLAndExp();
            strcpy(lorExp->data.binaryExp.data.op, t.value); // 设置运算符

            lhs = lorExp; // 关系表达式成为新的左操作数
        } else {
            tokenIndex--; // 不是关系运算符，回退Token
            break;
        }
    }
    return lhs;
}

PrintfStmt *parsePrintfStmt() {
    PrintfStmt *printf_stmt = malloc(sizeof(PrintfStmt));

    Token t = nextToken(); // '('
    printf_stmt->node.lineno = t.line;
    Token strToken = nextToken(); // 字符串常量

    strcpy(printf_stmt->string_const, strToken.value);

    // 解析后续的表达式参数
    printf_stmt->arg_count = 0;
    printf_stmt->args = malloc(10 * sizeof(Exp *)); // 假设最多10个参数

    while (true) {
        Token nexttoken = no_nextToken(); // 处理 ',' 或 ')'
        if (steq(&nexttoken, ")")) {
            printToken(&nexttoken);
            break; // 结束printf参数
        }
        if (steq(&nexttoken, ",")) {
            printToken(&nexttoken);
            printf_stmt->args[printf_stmt->arg_count++] = parseExp(0); // 解析参数
        }
        else if(steq(&nexttoken,";")){
            tokenIndex--;
            errorprint(t.line,'j');
            break;
        }
    }
    return printf_stmt; // 返回printf语句节点
}

ReturnStmt *parseReturnStmt(){
    Token t = no_nextToken();
    ReturnStmt *returnStmt = malloc(sizeof(ReturnStmt));
    for(int i=0;i< First_num;i++){
        if(typeequal(&t,First[i])){
            tokenIndex--;
            returnStmt->have_exp = 1;
            returnStmt->exp = parseExp(0);
            return returnStmt;
        }
    }
    tokenIndex--;
    returnStmt->have_exp = 0;
    return  returnStmt;
}
int main() {
    tokens = malloc(10000 * sizeof(Token));
    tokens = wordanalyze();
    totalindex = gettokennum();
//    FILE *getTokenfile = fopen("lexer.txt", "r");
    getWrongfile = fopen("error.txt","w");
    outfile = fopen("parser.txt","w");
//    if(getTokenfile == NULL){
//        fprintf(outfile,"lexer文件不存在");
//    }
//    getToken(getTokenfile);
    parseProgram();

//    fclose(getTokenfile);
    fclose(getWrongfile);
    fclose(outfile);
    return 0;
}
