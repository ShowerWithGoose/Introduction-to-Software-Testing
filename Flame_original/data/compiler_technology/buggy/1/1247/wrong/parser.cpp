//#include<iostream>
//#define cout std::cout
//#define endl '\n'

#include "error.h"
#include "lexer.h"
#include "parser.h"

#include<cstring>
#include<string>
#include<vector>

#define index _index

#define string std::string
#define vector std::vector

static signed char tr[128],td[128];

static void init(){
    memset(tr,-1,sizeof(tr));
    tr['a']='\a',tr['b']='\b',tr['t']='\t',tr['n']='\n',tr['v']='\v',
    tr['f']='\f',tr['0']='\0';
    memset(td,-1,sizeof(td));
    td['\a']='a',td['\b']='b',td['\t']='t',td['\n']='n',td['\v']='v',
    td['\f']='f',td['\0']='0',td['"']='"',td['\'']='\'',td['\\']='\\';
}

static string strToRel(const string &str){
    string res;
    size_t siz=str.length()-1;
    for(size_t i=1;i<siz;i++){
        if(str[i]=='\\'){
            ast(++i<siz);
            ast(!(str[i]&0x80));
            res+=(tr[str[i]]==-1?str[i]:(char)tr[str[i]]);
        }
        else{
            ast(!(str[i]&0x80));
            res+=str[i];
        }
    }
    return res;
}

static string strToDis(const string &str){
    string res="\"";
    size_t siz=str.length();
    for(size_t i=0;i<siz;i++){
        if(td[str[i]]==-1) res+=str[i];
        else res+='\\',res+=td[str[i]];
    }
    res+='"';
    return res;
}

static char chToRel(const string &str){
    if(str[1]=='\\'){
        ast(str.length()==4);
        ast(!(str[2]&0x80));
        return (tr[str[2]]==-1?str[2]:(char)tr[str[2]]);
    }
    ast(str.length()==3);
    ast(!(str[1]&0x80));
    return str[1];
}

static string chToDis(char ch){
    string res="'";
    if(td[ch]==-1) res+=ch;
    else res+='\\',res+=td[ch];
    res+='\'';
    return res;
}

CompUnit root;

static FILE *wfp;

static void putName(const char *str){
    fputc('<',wfp);
    fputs(str,wfp);
    fputc('>',wfp);
    fputc('\n',wfp);
}

static void printCompUnit(const CompUnit &it);
static void printConstDecl(const ConstDecl &it);
static void printConstDef(const ConstDef &it);
static void printConstInitVal(const ConstInitVal &it);
static void printVarDecl(const VarDecl &it);
static void printVarDef(const VarDef &it);
static void printInitVal(const InitVal &it);
static void printFuncDef(const FuncDef &it);
static void printFuncFParams(const FuncFParams &it);
static void printFuncFParam(const FuncFParam &it);
static void printBlock(const Block &it);
static void printBlockItem(const BlockItem &it);
static void printStmt(const Stmt &it);
static void printForStmt(const ForStmt &it);
static void printExp(const Exp &it);
static void printCond(const Cond &it);
static void printLVal(const LVal &it);
static void printPrimaryExp(const PrimaryExp &it);
static void printUnaryExp(const UnaryExp &it);
static void printFuncRParams(const FuncRParams &it);
static void printMulExp(const MulExp &it);
static void printAddExp(const AddExp &it);
static void printRelExp(const RelExp &it);
static void printEqExp(const EqExp &it);
static void printLAndExp(const LAndExp &it);

static const int type_token[]={VOIDTK,INTTK,CHARTK};
static const int add_token[]={PLUS,MINU,NOT};
static const int mul_token[]={MULT,DIV,MOD};
static const int rel_token[]={LSS,GRE,LEQ,GEQ};
static const int eq_token[]={EQL,NEQ};

static void printCompUnit(const CompUnit &it){
    for(const BlockItem &decl:it.decls) printBlockItem(decl);
    for(const FuncDef &funcDef:it.funcDefs) printFuncDef(funcDef);
    printFuncDef(it.mainFuncDef);
    putName("CompUnit");
}

static void printConstDecl(const ConstDecl &it){
    printWord(CONSTTK,wfp);
    printWord(type_token[it.bType],wfp);
    bool fl=false;
    for(const ConstDef &constDef:it.constDefs){
        if(fl) printWord(COMMA,wfp);fl=true;
        printConstDef(constDef);
    }
    printWord(SEMICN,wfp);
    putName("ConstDecl");
}

static void printConstDef(const ConstDef &it){
    printWord(IDENFR,it.ident,wfp);
    if(it.constExp){
        printWord(LBRACK,wfp);
        printExp(*it.constExp);
        printWord(RBRACK,wfp);
    }
    printWord(ASSIGN,wfp);
    printConstInitVal(it.constInitVal);
    putName("ConstDef");
}

static void printConstInitVal(const ConstInitVal &it){
    if(it.type==INITVAL_MULTI_EXP){
        printWord(LBRACE,wfp);
        bool fl=false;
        for(const Exp &constExp:*it.constExps){
            if(fl) printWord(COMMA,wfp);fl=true;
            printExp(constExp);
        }
        printWord(RBRACE,wfp);
    }
    else printExp(*it.constExp);
    putName("ConstInitVal");
}

static void printVarDecl(const VarDecl &it){
    printWord(type_token[it.bType],wfp);
    bool fl=false;
    for(const VarDef &varDef:it.varDefs){
        if(fl) printWord(COMMA,wfp);fl=true;
        printVarDef(varDef);
    }
    printWord(SEMICN,wfp);
    putName("VarDecl");
}

static void printVarDef(const VarDef &it){
    printWord(IDENFR,it.ident,wfp);
    if(it.constExp){
        printWord(LBRACK,wfp);
        printExp(*it.constExp);
        printWord(RBRACK,wfp);
    }
    if(it.initVal){
        printWord(ASSIGN,wfp);
        printInitVal(*it.initVal);
    }
    putName("VarDef");
}

static void printInitVal(const InitVal &it){
    if(it.type==INITVAL_MULTI_EXP){
        printWord(LBRACE,wfp);
        bool fl=false;
        for(const Exp &exp:*it.exps){
            if(fl) printWord(COMMA,wfp);fl=true;
            printExp(exp);
        }
        printWord(RBRACE,wfp);
    }
    else printExp(*it.exp);
    putName("InitVal");
}

static void printFuncDef(const FuncDef &it){
    bool isMain=isWordType(it.ident,MAINTK);
    if(isMain){
        printWord(INTTK,wfp);
        printWord(MAINTK,wfp);
    }
    else{
        printWord(type_token[it.bType],wfp);
        putName("FuncType");
        printWord(IDENFR,it.ident,wfp);
    }
    printWord(LPARENT,wfp);
    if(it.funcFParams){
        printFuncFParams(*it.funcFParams);
    }
    printWord(RPARENT,wfp);
    printBlock(it.block);
    putName(&"MainFuncDef"[isMain?0:4]);
}

static void printFuncFParams(const FuncFParams &it){
    bool fl=false;
    for(const FuncFParam &funcFParam:it.funcFParams){
        if(fl) printWord(COMMA,wfp);fl=true;
        printFuncFParam(funcFParam);
    }
    putName("FuncFParams");
}

static void printFuncFParam(const FuncFParam &it){
    printWord(type_token[it.bType],wfp);
    printWord(IDENFR,it.ident,wfp);
    if(it.isArray){
        printWord(LBRACK,wfp);
        printWord(RBRACK,wfp);
    }
    putName("FuncFParam");
}

static void printBlock(const Block &it){
    printWord(LBRACE,wfp);
    for(const BlockItem &blockItem:it.blockItems){
        printBlockItem(blockItem);
    }
    printWord(RBRACE,wfp);
    putName("Block");
}

static void printBlockItem(const BlockItem &it){
    if(it.type==ITEM_CONST_DECL) printConstDecl(*it.constDecl);
    else if(it.type==ITEM_VAR_DECL) printVarDecl(*it.varDecl);
    else printStmt(*it.stmt);
}

static void printStmt(const Stmt &it){
    switch(it.type){
        case STMT_LVAL_EXP:
            printLVal(*it.t_lVal_exp.lVal);
            printWord(ASSIGN,wfp);
            printExp(*it.t_lVal_exp.exp);
            printWord(SEMICN,wfp);
            break;
        default:
            printWord(RETURNTK,wfp);
        case STMT_EXP:
            if(it.exp) printExp(*it.exp);
            printWord(SEMICN,wfp);
            break;
        case STMT_BLOCK:
            printBlock(*it.block);
            break;
        case STMT_IF:
            printWord(IFTK,wfp);
            printWord(LPARENT,wfp);
            printCond(*it.t_if.cond);
            printWord(RPARENT,wfp);
            printStmt(*it.t_if.stmt1);
            if(it.t_if.stmt2){
                printWord(ELSETK,wfp);
                printStmt(*it.t_if.stmt2);
            }
            break;
        case STMT_FOR:
            printWord(FORTK,wfp);
            printWord(LPARENT,wfp);
            if(it.t_for.forStmt1) printForStmt(*it.t_for.forStmt1);
            printWord(SEMICN,wfp);
            if(it.t_for.cond) printCond(*it.t_for.cond);
            printWord(SEMICN,wfp);
            if(it.t_for.forStmt2) printForStmt(*it.t_for.forStmt2);
            printWord(RPARENT,wfp);
            printStmt(*it.t_for.stmt);
            break;
        case STMT_BREAK:
            printWord(BREAKTK,wfp);
            printWord(SEMICN,wfp);
            break;
        case STMT_CONTINUE:
            printWord(CONTINUETK,wfp);
            printWord(SEMICN,wfp);
            //break;
    }
    putName("Stmt");
}

static void printForStmt(const ForStmt &it){
    printLVal(it.lVal);
    printWord(ASSIGN,wfp);
    printExp(it.exp);
    putName("ForStmt");
}

static void printExp(const Exp &it){
    if(it.type==EXP_STRINGCONST){
        printWord(STRCON,strToDis(*it.stringConst),wfp);
    }
    else{
        AddExp *addExp=it.addExp;
        while(true){
            if(addExp->mulExps.size()!=1) break;
            MulExp &mulExp=addExp->mulExps.front().second;
            if(mulExp.unaryExps.size()!=1) break;
            UnaryExp &unaryExp=mulExp.unaryExps.front().second;
            if(unaryExp.type!=UNEXP_FUNC||!unaryExp.unaryOps.empty()) break;
            string *ident=unaryExp.ident;
            int code;
            if(isWordType(*ident,GETINTTK)) code=GETINTTK;
            else if(isWordType(*ident,GETCHARTK)) code=GETCHARTK;
            else if(isWordType(*ident,PRINTFTK)) code=PRINTFTK;
            else break;
            printWord(code,wfp);
            printWord(LPARENT,wfp);
            FuncRParams *funcRParams=unaryExp.funcRParams;
            if(funcRParams){
                bool fl=false;
                for(const Exp &exp:funcRParams->exps){
                    if(fl) printWord(COMMA,wfp);fl=true;
                    printExp(exp);
                }
            }
            printWord(RPARENT,wfp);
            return;
        }
        printAddExp(*addExp);
        putName(&"ConstExp"[it.type==EXP_NORMAL?5:0]);
    }
    // Unreachable
}

static void printCond(const Cond &it){
    bool fl=false;
    for(const LAndExp &lAndExp:it.lAndExps){
        if(fl) printWord(OR,wfp);fl=true;
        printLAndExp(lAndExp);
    }
    putName("LOrExp");
    putName("Cond");
}

static void printLVal(const LVal &it){
    printWord(IDENFR,it.ident,wfp);
    if(it.exp){
        printWord(LBRACK,wfp);
        printExp(*it.exp);
        printWord(RBRACK,wfp);
    }
    putName("LVal");
}

static void printPrimaryExp(const PrimaryExp &it){
    switch(it.type){
        case PEXP_EXP:
            printWord(LPARENT,wfp);
            printExp(*it.exp);
            printWord(RPARENT,wfp);
            break;
        case PEXP_LVAL:
            printLVal(*it.lVal);
            break;
        case PEXP_INT:
            printWord(INTCON,std::to_string(it.num),wfp);
            putName("Number");
            break;
        case PEXP_CHAR:
            printWord(CHRCON,chToDis(it.ch),wfp);
            putName("Character");
            //break;
    }
    putName("PrimaryExp");
}

static void printUnaryExp(const UnaryExp &it){
    for(int unaryOp:it.unaryOps){
        printWord(add_token[unaryOp],wfp);
        putName("UnaryOp");
    }
    if(it.type==UNEXP_PEXP){
        printPrimaryExp(*it.primaryExp);
    }
    else{
        printWord(IDENFR,*it.ident,wfp);
        printWord(LPARENT,wfp);
        if(it.funcRParams) printFuncRParams(*it.funcRParams);
        printWord(RPARENT,wfp);
    }
    putName("UnaryExp");
}

static void printFuncRParams(const FuncRParams &it){
    bool fl=false;
    for(const Exp &exp:it.exps){
        if(fl) printWord(COMMA,wfp);fl=true;
        printExp(exp);
    }
    putName("FuncRParams");
}

static void printMulExp(const MulExp &it){
    bool fl=false;
    for(const auto &p:it.unaryExps){
        if(fl) printWord(mul_token[p.first],wfp);fl=true;
        printUnaryExp(p.second);
    }
    putName("MulExp");
}

static void printAddExp(const AddExp &it){
    bool fl=false;
    for(const auto &p:it.mulExps){
        if(fl) printWord(add_token[p.first],wfp);fl=true;
        printMulExp(p.second);
    }
    putName("AddExp");
}

static void printRelExp(const RelExp &it){
    bool fl=false;
    for(const auto &p:it.addExps){
        if(fl) printWord(rel_token[p.first],wfp);fl=true;
        printAddExp(p.second);
    }
    putName("RelExp");
}

static void printEqExp(const EqExp &it){
    bool fl=false;
    for(const auto &p:it.relExps){
        if(fl) printWord(eq_token[p.first],wfp);fl=true;
        printRelExp(p.second);
    }
    putName("EqExp");
}

static void printLAndExp(const LAndExp &it){
    bool fl=false;
    for(const EqExp &eqExp:it.eqExps){
        if(fl) printWord(AND,wfp);fl=true;
        printEqExp(eqExp);
    }
    putName("LAndExp");
}

bool printRoot(const char *fn){
    wfp=fopen(fn,"w");
    if(wfp){
        printCompUnit(root);
        fclose(wfp);
        return true;
    }
    return false;
}

static size_t index,size;

#define move1() (++index<size)
#define move(p) ((index+=p)<size)
#define getType0() (words[index].code)
#define getType(p) (index+p<size?words[index+p].code:0)
#define getLine() (words[index].line)
#define getLastLine() (words[index-1].line)
#define getContent() (words[index].content)

#define isExp() (getType0()==PLUS||getType0()==MINU||getType0()==LPARENT||getType0()==IDENFR||getType0()==INTCON||getType0()==CHRCON||getType0()==STRCON)

static void parseCompUnit(CompUnit &it);
static void parseConstDecl(ConstDecl &it);
static void parseConstDef(ConstDef &it);
static void parseConstInitVal(ConstInitVal &it);
static void parseVarDecl(VarDecl &it);
static void parseVarDef(VarDef &it);
static void parseInitVal(InitVal &it);
static void parseFuncDef(FuncDef &it);
static void parseFuncFParams(FuncFParams &it);
static void parseFuncFParam(FuncFParam &it);
static void parseBlock(Block &it);
static void parseBlockItem(BlockItem &it);
static void parseStmt(Stmt &it);
static void parseForStmt(ForStmt &it);
static void parseExp(Exp &it,int type);
static void parseCond(Cond &it);
static void parseLVal(LVal &it);
static void parsePrimaryExp(PrimaryExp &it);
static void parseUnaryExp(UnaryExp &it);
static void parseFuncRParams(FuncRParams &it);
static void parseMulExp(MulExp &it);
static void parseAddExp(AddExp &it);
static void parseRelExp(RelExp &it);
static void parseEqExp(EqExp &it);
static void parseLAndExp(LAndExp &it);

static void parseCompUnit(CompUnit &it){
    bool fl=false;
    while(index<size){
        if(getType(2)==LPARENT){
            if(isWordType(words[index+1].content,MAINTK)){
                fl=true;
                parseFuncDef(it.mainFuncDef);
            }
            else{
                it.funcDefs.emplace_back();
                parseFuncDef(it.funcDefs.back());
            }
        }
        else{
            it.decls.emplace_back();
            parseBlockItem(it.decls.back());
        }
    }
    ast(fl);
}

// ID 0
static void parseConstDecl(ConstDecl &it){
    ast(move1());
    if(getType0()==INTTK) it.bType=TYPE_INT;
    else if(getType0()==CHARTK) it.bType=TYPE_CHAR;
    else panic();
    do{
        ast(move1());
        it.constDefs.emplace_back();
        parseConstDef(it.constDefs.back());
    }while(getType0()==COMMA);
    if(getType0()==SEMICN) ast(move1());
    else errors.push_back({getLastLine(),'i'});
}

static void parseConstDef(ConstDef &it){
    ast(getType0()==IDENFR);
    it.line=getLine(),it.ident=getContent();
    ast(move1());
    if(getType0()==LBRACK){
        ast(move1());
        it.constExp=new Exp();
        parseExp(*it.constExp,EXP_CONST);
        if(getType0()==RBRACK) ast(move1());
        else errors.push_back({getLastLine(),'k'});
    }
    ast(getType0()==ASSIGN);
    ast(move1());
    parseConstInitVal(it.constInitVal);
}

static void parseConstInitVal(ConstInitVal &it){
    if(getType0()==LBRACE){
        it.type=INITVAL_MULTI_EXP;
        it.constExps=new vector<Exp>();
        do{
            ast(move1());
            it.constExps->emplace_back();
            parseExp(it.constExps->back(),EXP_CONST);
        }while(getType0()==COMMA);
        ast(getType0()==RBRACE);
        ast(move1());
    }
    else{
        it.constExp=new Exp();
        parseExp(*it.constExp,EXP_CONST);
        it.type=(it.constExp->type==EXP_STRINGCONST?INITVAL_STRINGCONST:INITVAL_EXP);
    }
}

// ID 0
static void parseVarDecl(VarDecl &it){
    it.bType=(getType0()==INTTK?TYPE_INT:TYPE_CHAR);
    do{
        ast(move1());
        it.varDefs.emplace_back();
        parseVarDef(it.varDefs.back());
    }while(getType0()==COMMA);
    if(getType0()==SEMICN) ast(move1());
    else errors.push_back({getLastLine(),'i'});
}

static void parseVarDef(VarDef &it){
    ast(getType0()==IDENFR);
    it.line=getLine(),it.ident=getContent();
    ast(move1());
    if(getType0()==LBRACK){
        ast(move1());
        it.constExp=new Exp();
        parseExp(*it.constExp,EXP_CONST);
        if(getType0()==RBRACK) ast(move1());
        else errors.push_back({getLastLine(),'k'});
    }
    if(getType0()==ASSIGN){
        ast(move1());
        it.initVal=new InitVal();
        parseInitVal(*it.initVal);
    }
}

static void parseInitVal(InitVal &it){
    if(getType0()==LBRACE){
        it.type=INITVAL_MULTI_EXP;
        it.exps=new vector<Exp>();
        do{
            ast(move1());
            it.exps->emplace_back();
            parseExp(it.exps->back(),EXP_NORMAL);
        }while(getType0()==COMMA);
        ast(getType0()==RBRACE);
        ast(move1());
    }
    else{
        it.exp=new Exp();
        parseExp(*it.exp,EXP_NORMAL);
        it.type=(it.exp->type==EXP_STRINGCONST?INITVAL_STRINGCONST:INITVAL_EXP);
    }
}

// ID 2
static void parseFuncDef(FuncDef &it){
    if(getType0()==VOIDTK) it.bType=TYPE_VOID;
    else if(getType0()==INTTK) it.bType=TYPE_INT;
    else if(getType0()==CHARTK) it.bType=TYPE_CHAR;
    else panic();
    ast(move1());ast(getType0()==IDENFR);
    it.bLine=getLine(),it.ident=getContent();
    move(2);
    if(getType0()==INTTK||getType0()==CHARTK){
        it.funcFParams=new FuncFParams();
        parseFuncFParams(*it.funcFParams);
    }
    if(getType0()==RPARENT) ast(move1());
    else errors.push_back({getLastLine(),'j'});
    parseBlock(it.block);
    it.gLine=getLastLine();
}

// ID 0
static void parseFuncFParams(FuncFParams &it){
    bool fl=false;
    do{
        if(fl) ast(move1());fl=true;
        it.funcFParams.emplace_back();
        parseFuncFParam(it.funcFParams.back());
    }while(getType0()==COMMA);
}

static void parseFuncFParam(FuncFParam &it){
    if(getType0()==INTTK) it.bType=TYPE_INT;
    else if(getType0()==CHARTK) it.bType=TYPE_CHAR;
    else panic();
    ast(move1());ast(getType0()==IDENFR);
    it.line=getLine(),it.ident=getContent();
    ast(move1());
    if(getType0()==LBRACK){
        it.isArray=true;
        ast(move1());
        if(getType0()==RBRACK) ast(move1());
        else errors.push_back({getLastLine(),'k'});
    }
}

// LAST
static void parseBlock(Block &it){
    ast(getType0()==LBRACE);
    ast(move1());
    while(getType0()!=RBRACE){
        it.blockItems.emplace_back();
        parseBlockItem(it.blockItems.back());
    }
    move1();
}

static void parseBlockItem(BlockItem &it){
    if(getType0()==CONSTTK){
        it.type=ITEM_CONST_DECL;
        it.constDecl=new ConstDecl();
        parseConstDecl(*it.constDecl);
    }
    else if(getType0()==INTTK||getType0()==CHARTK){
        it.type=ITEM_VAR_DECL;
        it.varDecl=new VarDecl();
        parseVarDecl(*it.varDecl);
    }
    else{
        it.type=ITEM_STMT;
        it.stmt=new Stmt();
        parseStmt(*it.stmt);
    }
}

static void parseStmt(Stmt &it){
    it.line=getLine();
    switch(getType0()){
        case SEMICN:
            it.type=STMT_EXP;
            ast(move1());
            break;
        case LBRACE:
            it.type=STMT_BLOCK;
            it.block=new Block();
            parseBlock(*it.block);
            ast(index<size);
            break;
        case IFTK:
            it.type=STMT_IF;
            ast(move1());
            ast(getType0()==LPARENT);
            ast(move1());
            it.t_if.cond=new Cond();
            parseCond(*it.t_if.cond);
            if(getType0()==RPARENT) ast(move1());
            else errors.push_back({getLastLine(),'j'});
            it.t_if.stmt1=new Stmt();
            parseStmt(*it.t_if.stmt1);
            if(getType0()==ELSETK){
                ast(move1());
                it.t_if.stmt2=new Stmt();
                parseStmt(*it.t_if.stmt2);
            }
            break;
        case FORTK:
            it.type=STMT_FOR;
            ast(move1());
            ast(getType0()==LPARENT);
            ast(move1());
            if(getType0()!=SEMICN){
                it.t_for.forStmt1=new ForStmt();
                parseForStmt(*it.t_for.forStmt1);
                ast(getType0()==SEMICN);
            }
            ast(move1());
            if(getType0()!=SEMICN){
                it.t_for.cond=new Cond();
                parseCond(*it.t_for.cond);
                ast(getType0()==SEMICN);
            }
            ast(move1());
            if(getType0()!=RPARENT){
                it.t_for.forStmt2=new ForStmt();
                parseForStmt(*it.t_for.forStmt2);
                ast(getType0()==RPARENT);
            }
            ast(move1());
            it.t_for.stmt=new Stmt();
            parseStmt(*it.t_for.stmt);
            break;
        case BREAKTK:
        case CONTINUETK:
            it.type=(getType0()==BREAKTK?STMT_BREAK:STMT_CONTINUE);
            ast(move1());
            if(getType0()==SEMICN) ast(move1());
            else errors.push_back({getLastLine(),'i'});
            break;
        case RETURNTK:
            it.type=STMT_RETURN;
            ast(move1());
            if(isExp()){
                it.exp=new Exp();
                parseExp(*it.exp,EXP_NORMAL);
            }
            if(getType0()==SEMICN) ast(move1());
            else errors.push_back({getLastLine(),'i'});
            break;
        default:
            Exp *exp=new Exp();
            parseExp(*exp,EXP_NORMAL);
            if(getType0()==ASSIGN){
                ast(exp->type==EXP_NORMAL);
                AddExp *addExp=exp->addExp;
                ast(addExp->mulExps.size()==1);
                MulExp &mulExp=addExp->mulExps.front().second;
                ast(mulExp.unaryExps.size()==1);
                UnaryExp &unaryExp=mulExp.unaryExps.front().second;
                ast(unaryExp.type==UNEXP_PEXP&&unaryExp.unaryOps.empty());
                PrimaryExp *primaryExp=unaryExp.primaryExp;
                ast(primaryExp->type==PEXP_LVAL);
                LVal *lVal=primaryExp->lVal;
                delete primaryExp;
                delete addExp;
                delete exp;
                it.type=STMT_LVAL_EXP,it.t_lVal_exp.lVal=lVal;
                ast(move1());
                it.t_lVal_exp.exp=new Exp();
                parseExp(*it.t_lVal_exp.exp,EXP_NORMAL);
            }
            else it.type=STMT_EXP,it.exp=exp;
            if(getType0()==SEMICN) ast(move1());
            else errors.push_back({getLastLine(),'i'});
            //break;
    }
}

static void parseForStmt(ForStmt &it){
    it.line=getLine();
    parseLVal(it.lVal);
    ast(getType0()==ASSIGN);
    ast(move1());
    parseExp(it.exp,EXP_NORMAL);
}

static void parseExp(Exp &it,int type){
    if(getType0()==STRCON){
        it.type=EXP_STRINGCONST;
        it.stringConst=new string(strToRel(getContent()));
        ast(move1());
    }
    else{
        it.type=type;
        it.addExp=new AddExp();
        parseAddExp(*it.addExp);
    }
}

static void parseCond(Cond &it){
    bool fl=false;
    do{
        if(fl) ast(move1());fl=true;
        it.lAndExps.emplace_back();
        parseLAndExp(it.lAndExps.back());
    }while(getType0()==OR);
}

static void parseLVal(LVal &it){
    ast(getType0()==IDENFR);
    it.line=getLine(),it.ident=getContent();
    ast(move1());
    if(getType0()==LBRACK){
        ast(move1());
        it.exp=new Exp();
        parseExp(*it.exp,EXP_NORMAL);
        if(getType0()==RBRACK) ast(move1());
        else errors.push_back({getLastLine(),'k'});
    }
}

static void parsePrimaryExp(PrimaryExp &it){
    if(getType0()==LPARENT){
        it.type=PEXP_EXP;
        ast(move1());
        it.exp=new Exp();
        parseExp(*it.exp,EXP_NORMAL);
        if(getType0()==RPARENT) ast(move1());
        else errors.push_back({getLastLine(),'j'});
    }
    else if(getType0()==INTCON){
        it.type=PEXP_INT;
        it.num=std::stoi(getContent());
        ast(move1());
    }
    else if(getType0()==CHRCON){
        it.type=PEXP_CHAR;
        it.ch=chToRel(getContent());
        ast(move1());
    }
    else{
        it.type=PEXP_LVAL;
        it.lVal=new LVal();
        parseLVal(*it.lVal);
    }
}

static void parseUnaryExp(UnaryExp &it){
    while(true){
        switch(getType0()){
            case PLUS:
                it.unaryOps.push_back(ADDOP_ADD);
                break;
            case MINU:
                it.unaryOps.push_back(ADDOP_SUB);
                break;
            case NOT:
                it.unaryOps.push_back(ADDOP_NOT);
                break;
            default:
                goto l_parseUnaryExp;
        }
        ast(move1());
    }
    l_parseUnaryExp:
    if(getType0()==IDENFR&&getType(1)==LPARENT){
        it.type=UNEXP_FUNC;
        it.line=getLine(),it.ident=new string(getContent());
        ast(move(2));
        if(isExp()){
            it.funcRParams=new FuncRParams();
            parseFuncRParams(*it.funcRParams);
        }
        if(getType0()==RPARENT) ast(move1());
        else errors.push_back({getLastLine(),'j'});
    }
    else{
        it.type=UNEXP_PEXP;
        it.primaryExp=new PrimaryExp();
        parsePrimaryExp(*it.primaryExp);
    }
}

static void parseFuncRParams(FuncRParams &it){
    bool fl=false;
    do{
        if(fl) ast(move1());fl=true;
        it.exps.emplace_back();
        parseExp(it.exps.back(),EXP_NORMAL);
    }while(getType0()==COMMA);
}

static void parseMulExp(MulExp &it){
    int op=-1;
    while(true){
        it.unaryExps.emplace_back();
        it.unaryExps.back().first=op;
        parseUnaryExp(it.unaryExps.back().second);
        switch(getType0()){
            case MULT:
                op=MULOP_MUL;
                break;
            case DIV:
                op=MULOP_DIV;
                break;
            case MOD:
                op=MULOP_MOD;
                break;
            default:
                return;
        }
        ast(move1());
    }
    // Unreachable
}

static void parseAddExp(AddExp &it){
    int op=-1;
    while(true){
        it.mulExps.emplace_back();
        it.mulExps.back().first=op;
        parseMulExp(it.mulExps.back().second);
        switch(getType0()){
            case PLUS:
                op=ADDOP_ADD;
                break;
            case MINU:
                op=ADDOP_SUB;
                break;
            default:
                return;
        }
        ast(move1());
    }
    // Unreachable
}

static void parseRelExp(RelExp &it){
    int op=-1;
    while(true){
        it.addExps.emplace_back();
        it.addExps.back().first=op;
        parseAddExp(it.addExps.back().second);
        switch(getType0()){
            case LSS:
                op=RELOP_LSS;
                break;
            case GRE:
                op=RELOP_GRE;
                break;
            case LEQ:
                op=RELOP_LEQ;
                break;
            case GEQ:
                op=RELOP_GEQ;
                break;
            default:
                return;
        }
        ast(move1());
    }
    // Unreachable
}

static void parseEqExp(EqExp &it){
    int op=-1;
    while(true){
        it.relExps.emplace_back();
        it.relExps.back().first=op;
        parseRelExp(it.relExps.back().second);
        switch(getType0()){
            case EQL:
                op=EQOP_EQL;
                break;
            case NEQ:
                op=EQOP_NEQ;
                break;
            default:
                return;
        }
        ast(move1());
    }
    // Unreachable
}

static void parseLAndExp(LAndExp &it){
    bool fl=false;
    do{
        if(fl) ast(move1());fl=true;
        it.eqExps.emplace_back();
        parseEqExp(it.eqExps.back());
    }while(getType0()==AND);
}

void parseWords(){
    ast(index==0);size=words.size();
    init();parseCompUnit(root);
}
