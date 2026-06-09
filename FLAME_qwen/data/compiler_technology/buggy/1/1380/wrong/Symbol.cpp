#include <bits/stdc++.h>
#include "utils.h"
#include "type.h"
#include "parser.h"
#include "symbol.h"
using namespace std;

extern NODE node[100000];

SymbolTable symbolTable[10086];
int validStack[10086],validCnt=0,usedId=0;   //usedId:使用过的最大编号


Symbol::Symbol(int d, const string& n, const string& t,int isF):depth(d), name(n), type(t), isFunc(isF) {
}

WordSymbol::WordSymbol(int d, const std::string& n, const std::string& t, int c, int dim)
    : Symbol(d, n, t,0), con(c), dimension(dim) {
}

FuncSymbol::FuncSymbol(int d, const string& n, const string& t):Symbol(d, n, t,1) {
}

void print_symbol(){
    for(int i=1;i<=usedId;i++){
        for(int j=0;j<symbolTable[i].symbol.size();j++){
            write("symbol.txt",to_string(i)+" "+symbolTable[i].symbol[j]->name+" "+symbolTable[i].symbol[j]->type+"\n");
        }
    }
}

Symbol* contains(int curId,string name){
    if(curId==-1){   //forall
        for(int i=validCnt;i>0;i--){
            curId = validStack[i];
            for(int j=0;j<symbolTable[curId].symbol.size();j++){
                if(symbolTable[curId].symbol[j]->name==name)return symbolTable[curId].symbol[j];
            }
        }
        return NULL;
    }
    for(int i=0;i<symbolTable[curId].symbol.size();i++){
        if(symbolTable[curId].symbol[i]->name==name)return symbolTable[curId].symbol[i];
    }
    return NULL;
}

//编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef 
void CompUnitError(){
    //++depthCnt;
    NODE curNode = node[1];   //default 1 is CompUnit

    validStack[++validCnt]=++usedId;
    for(int i=0;i<curNode.son.size();i++){
        NODE sonNode = node[curNode.son[i]];
        if(sonNode.endToken.sym=="<ConstDecl>"){
            ConstDeclError(sonNode);
        }else if (sonNode.endToken.sym=="<VarDecl>"){
            VarDeclError(sonNode);
        }else if (sonNode.endToken.sym=="<FuncDef>"){
            FuncDefError(sonNode);
        }else{
            MainFuncDefError(sonNode);
        }
    }
    --validCnt;
}
void ConstDeclError(NODE curNode){
    string type = node[curNode.son[1]].endToken.sym;
    for(int i=2;i<curNode.son.size();i++){
        NODE sonNode = node[curNode.son[i]];
        if(sonNode.endToken.sym=="<ConstDef>"){
            ConstDefError(sonNode,type);
        }
    }
}
// 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
void ConstDefError(NODE curNode,string type){
    NODE sonNode = node[curNode.son[1]];
    int curId = validStack[validCnt];
    if(contains(curId,node[curNode.son[0]].endToken.ori)!=NULL){
        error(node[curNode.son[0]].endToken.line,"b");
    }

    if(sonNode.endToken.sym=="LBRACK"){ //Array
        if(type=="INTTK"){
            symbolTable[curId].symbol.push_back(new WordSymbol(curId,node[curNode.son[0]].endToken.ori,"ConstIntArray",1,1));
        }else{   //CHARTK
            symbolTable[curId].symbol.push_back(new WordSymbol(curId,node[curNode.son[0]].endToken.ori,"ConstCharArray",1,1));
        }
    }else{   //var
        if(type=="INTTK"){
            symbolTable[curId].symbol.push_back(new WordSymbol(curId,node[curNode.son[0]].endToken.ori,"ConstInt",1,0));
        }else{   //CHARTK
            symbolTable[curId].symbol.push_back(new WordSymbol(curId,node[curNode.son[0]].endToken.ori,"ConstChar",1,0));
        }
    }
    ConstInitValError(node[curNode.son.back()]);
}
void ConstInitValError(NODE curNode){
    for(int i=0;i<curNode.son.size();i++){
        NODE sonNode = node[curNode.son[i]];
        if(sonNode.endToken.sym=="<ConstExp>")ConstExpError(sonNode);
    }
}
//VarDecl → BType VarDef { ',' VarDef } ';' // i
void VarDeclError(NODE curNode){
    string type = node[curNode.son[0]].endToken.sym;
    for(int i=1;i<curNode.son.size();i++){
        NODE sonNode = node[curNode.son[i]];
        if(sonNode.endToken.sym=="<VarDef>"){
            VarDefError(sonNode,type);
        }
    }
}
// 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
void VarDefError(NODE curNode,string type){
    NODE sonNode = node[curNode.son[1]];
    int curId = validStack[validCnt];

    if(contains(curId,node[curNode.son[0]].endToken.ori)!=NULL){
        error(node[curNode.son[0]].endToken.line,"b");
    }
    if(sonNode.endToken.sym=="LBRACK"){ //Array
        if(type=="INTTK"){
            symbolTable[curId].symbol.push_back(new WordSymbol(curId,node[curNode.son[0]].endToken.ori,"IntArray",0,1));
        }else{   //CHARTK
            symbolTable[curId].symbol.push_back(new WordSymbol(curId,node[curNode.son[0]].endToken.ori,"CharArray",0,1));
        }
    }else{   //var
        if(type=="INTTK"){
            symbolTable[curId].symbol.push_back(new WordSymbol(curId,node[curNode.son[0]].endToken.ori,"Int",0,0));
        }else{   //CHARTK
            symbolTable[curId].symbol.push_back(new WordSymbol(curId,node[curNode.son[0]].endToken.ori,"Char",0,0));
        }
    }
    for(int i=0;i<curNode.son.size();i++){
        NODE sonNode = node[curNode.son[i]];
        if(sonNode.endToken.sym=="<ConstExp>")ConstExpError(sonNode);
        if(sonNode.endToken.sym=="<InitVal>")InitValError(sonNode);
    }
}
//变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst 
void InitValError(NODE curNode){
    for(int i=0;i<curNode.son.size();i++){
        NODE sonNode = node[curNode.son[i]];
        if(sonNode.endToken.sym=="<Exp>"){
            ExpError(sonNode);
        }
    }
}
//函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // b g
//函数形参表 FuncFParams → FuncFParam { ',' FuncFParam } 
void FuncDefError(NODE curNode){
    NODE sonNode = node[curNode.son[0]];
    int curId = validStack[validCnt];

    if(contains(curId,node[curNode.son[1]].endToken.ori)!=NULL){
        error(node[curNode.son[1]].endToken.line,"b");
    }

    if(node[sonNode.son[0]].endToken.sym=="VOIDTK"){
        symbolTable[curId].symbol.push_back(new FuncSymbol(curId,node[curNode.son[1]].endToken.ori,"VoidFunc"));
    }else if (node[sonNode.son[0]].endToken.sym=="INTTK"){
        symbolTable[curId].symbol.push_back(new FuncSymbol(curId,node[curNode.son[1]].endToken.ori,"IntFunc"));
    }else{   //CHARTK
        symbolTable[curId].symbol.push_back(new FuncSymbol(curId,node[curNode.son[1]].endToken.ori,"CharFunc"));
    }
    
    sonNode = node[curNode.son[3]];  //FuncFParams
    FuncSymbol* curSymbol = static_cast<FuncSymbol*>(symbolTable[curId].symbol.back());

    if(sonNode.endToken.sym!="RPARENT"){  //add param
        for(int i=0;i<sonNode.son.size();i++){
            if(node[sonNode.son[i]].endToken.sym=="<FuncFParam>"){
                FuncFParamError(node[sonNode.son[i]],curSymbol);
            }
        }
    }
    sonNode = node[curNode.son.back()];
    BlockError(sonNode,node[node[curNode.son[0]].son[0]].endToken.sym=="VOIDTK");

    if(node[node[curNode.son[0]].son[0]].endToken.sym=="VOIDTK")return ;
    int RbraceLine = node[sonNode.son[sonNode.son.size()-1]].endToken.line;
    if(sonNode.son.size()<2){error(RbraceLine,"g");return ;}
    NODE lst = node[sonNode.son[sonNode.son.size()-2]];
    if(lst.endToken.sym!="<Stmt>"){error(RbraceLine,"g");return ;}
    if(node[lst.son[0]].endToken.sym!="RETURNTK"){error(RbraceLine,"g");return ;}
    if(lst.son.size()!=3)error(RbraceLine,"g");
}
//函数形参 FuncFParam → BType Ident ['[' ']'] // k
void FuncFParamError(NODE curNode, FuncSymbol* curSymbol){
    NODE sonNode = node[curNode.son[0]];
    string type = sonNode.endToken.sym;
    if(curNode.son.size()>=3)sonNode = node[curNode.son[2]];
    int curId = usedId+1;

    if(contains(curId,node[curNode.son[1]].endToken.ori)!=NULL){
        error(node[curNode.son[1]].endToken.line,"b");
    }

    WordSymbol* wordSymbol;

    if(sonNode.endToken.sym=="LBRACK"){ //Array
        if(type=="INTTK"){
            wordSymbol=new WordSymbol(curId,node[curNode.son[1]].endToken.ori,"IntArray",0,1);
            
        }else{   //CHARTK
            wordSymbol=new WordSymbol(curId,node[curNode.son[1]].endToken.ori,"CharArray",0,1);
        }
    }else{   //var
        if(type=="INTTK"){
            wordSymbol=new WordSymbol(curId,node[curNode.son[1]].endToken.ori,"Int",0,0);
        }else{   //CHARTK
            wordSymbol=new WordSymbol(curId,node[curNode.son[1]].endToken.ori,"Char",0,0);
        }
    }
    curSymbol->params.push_back(wordSymbol);   //putin function param
    symbolTable[curId].symbol.push_back(wordSymbol);    //also put in curId table
    //cout<<curId<<endl;
}
//主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block // j
void MainFuncDefError(NODE curNode){
    NODE sonNode = node[curNode.son[4]];
    BlockError(sonNode,0);

    int RbraceLine = node[sonNode.son[sonNode.son.size()-1]].endToken.line;
    if(sonNode.son.size()<2){error(RbraceLine,"g");return ;}
    NODE lst = node[sonNode.son[sonNode.son.size()-2]];
    if(lst.endToken.sym!="<Stmt>"){error(RbraceLine,"g");return ;}
    if(node[lst.son[0]].endToken.sym!="RETURNTK"){error(RbraceLine,"g");return ;}
    if(lst.son.size()!=3)error(RbraceLine,"g");
}
void BlockError(NODE curNode,int checkReturn){
    validStack[++validCnt]=++usedId;
    cout<<"he\n";
    for(int i=0;i<curNode.son.size();i++){
        NODE sonNode = node[curNode.son[i]];
        if(sonNode.endToken.sym=="<ConstDecl>"){
            ConstDeclError(sonNode);
        }else if (sonNode.endToken.sym=="<VarDecl>"){
            VarDeclError(sonNode);
        }else if (sonNode.endToken.sym=="<Stmt>"){
            StmtError(sonNode,checkReturn);
        }
    }

    --validCnt;
}
int loop=0;
void StmtError(NODE curNode,int checkReturn){   //void func don't allow return value
    NODE sonNode = node[curNode.son[0]];
    if(sonNode.endToken.sym=="FORTK")loop++;
    for(int i=0;i<curNode.son.size();i++){
        sonNode = node[curNode.son[i]];
        if(sonNode.endToken.sym=="<Block>"){
            BlockError(sonNode,checkReturn);
        }else if(sonNode.endToken.sym=="<Stmt>"){
            StmtError(sonNode,checkReturn);
        }else if (sonNode.endToken.sym=="<LVal>"){
            LValError(sonNode,1);
        }else if(sonNode.endToken.sym=="<Exp>"){
            ExpError(sonNode);
        }else if(sonNode.endToken.sym=="<ForStmt>"){
            ForStmtError(sonNode);
        }else if(sonNode.endToken.sym=="FORTK"){
            //loop++;
            //StmtError(node[curNode.son.back()],checkReturn);
            //loop--;
        }else if(sonNode.endToken.sym=="BREAKTK" || sonNode.endToken.sym=="CONTINUETK"){
            if(loop==0)error(sonNode.endToken.line,"m");
        }else if(sonNode.endToken.sym=="PRINTFTK"){
            int modcnt=0,expcnt=0;
            string strcon = node[curNode.son[2]].endToken.ori;
            int idx=0;
            while((idx = strcon.find("%c",idx))!=string::npos){idx++;modcnt++;}
            idx=0;
             while((idx = strcon.find("%d",idx))!=string::npos){idx++;modcnt++;}
            //for(int j=0;j<strcon.length();j++)if(strcon[j]=='%')modcnt++;


            for(int j=0;j<curNode.son.size();j++){
                if(node[curNode.son[j]].endToken.sym=="<Exp>")expcnt++;
            }
            if(modcnt!=expcnt)error(sonNode.endToken.line,"l");
        }else if (sonNode.endToken.sym=="RETURNTK" && checkReturn){
            if(node[curNode.son[i+1]].endToken.sym!="SEMICN")error(sonNode.endToken.line,"f");
        }
    }
    sonNode = node[curNode.son[0]];
    if(sonNode.endToken.sym=="FORTK")loop--;
}
//语句 ForStmt → LVal '=' Exp // h
void ForStmtError(NODE curNode){
    NODE sonNode = node[curNode.son[0]];
    LValError(sonNode,1);
    sonNode = node[curNode.son[2]];
    ExpError(sonNode);
}
//表达式 Exp → AddExp 
int ExpError(NODE curNode){
    NODE sonNode = node[curNode.son[0]];
    return AddExpError(sonNode);
}
//左值表达式 LVal → Ident ['[' Exp ']'] // c
int LValError(NODE curNode,int checkAssign){    //const? int1/char0 array?  421
    NODE sonNode = node[curNode.son[0]];
    Symbol* target = contains(-1,sonNode.endToken.ori);
    if(target==NULL){
        error(sonNode.endToken.line,"c");
        return 0;
    }
    WordSymbol* targetSymbol = static_cast<WordSymbol*>(target);

    if(checkAssign){
        if(targetSymbol->con)error(sonNode.endToken.line,"h");
    }
    
    int ret=0;
    if(targetSymbol->type.find("Int")!=string::npos)ret=2;
    if(targetSymbol->con)ret+=4;
    if(targetSymbol->dimension)ret++;


    if(curNode.son.size()>1){
        sonNode = node[curNode.son[2]];
        ExpError(sonNode);
        ret&=0;
    }
    return ret;
}
//基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character
int PrimaryExpError(NODE curNode){
    NODE sonNode = node[curNode.son[0]];
    if(sonNode.endToken.sym=="LPARENT"){
        return ExpError(node[curNode.son[1]]);
    }else if (sonNode.endToken.sym=="<LVal>"){
        return LValError(sonNode,0);
    }
    return 0;
}
//一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // c d e
int UnaryExpError(NODE curNode){
    NODE sonNode = node[curNode.son[0]];
    //cout<<"UnaryExpError:"<<sonNode.endToken.sym<<endl;
    if(sonNode.endToken.sym=="<PrimaryExp>"){
        return PrimaryExpError(sonNode);
    }else if(sonNode.endToken.sym=="IDENFR"){   //函数调用
        Symbol* target = contains(-1,sonNode.endToken.ori);
        if(target==NULL){
            error(sonNode.endToken.line,"c");
            return 0;
        }
        //find the function defination
        FuncSymbol* targetSymbol = static_cast<FuncSymbol*>(target);
        //cout<<targetSymbol->params.size()<<endl;
        if(node[curNode.son[2]].endToken.sym=="<FuncRParams>")FuncRParamsError(node[curNode.son[2]], targetSymbol,sonNode.endToken.line);
        
        return 0;
    }else{
        return UnaryExpError(node[curNode.son[1]]);
    }
}
//函数实参表 FuncRParams → Exp { ',' Exp } 
void FuncRParamsError(NODE curNode, FuncSymbol* funcsymbol,int line){
    int ret=0;
    for(int i=0;i<curNode.son.size();i++){
        NODE sonNode = node[curNode.son[i]];
        if(sonNode.endToken.sym=="<Exp>"){
            ret++;
            //ExpError(sonNode);
        }
    }
    if(ret!=funcsymbol->params.size()){   
        error(line,"d");
        return ;
    }
    ret=0;
    for(int i=0;i<curNode.son.size();i++){
        NODE sonNode = node[curNode.son[i]];
        if(sonNode.endToken.sym=="<Exp>"){
            int typ = ExpError(sonNode);
            if(funcsymbol->params[ret]->dimension==1){   //array
                if((typ&1)==0){error(line,"e");return ;}
                else{
                    if(funcsymbol->params[ret]->type.find("Int")!=string::npos){   //int
                        if((typ&2)==0){error(line,"e");return ;}
                    }else {   //char
                        if(typ&2){error(line,"e");return ;}
                    }
                }
            }else{   //var
                if(typ&1){error(line,"e");return ;}
            }
            ret++;
        }
    }
}
//乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp 
int MulExpError(NODE curNode){
    NODE sonNode = node[curNode.son[0]];
    if(sonNode.endToken.sym=="<MulExp>"){
        MulExpError(sonNode);
        UnaryExpError(node[curNode.son[2]]);
        return 0;
    }else{
        return UnaryExpError(sonNode);
    }
}
//加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp 
int AddExpError(NODE curNode){
    NODE sonNode = node[curNode.son[0]];
    if(sonNode.endToken.sym=="<AddExp>"){
        AddExpError(sonNode);
        MulExpError(node[curNode.son[2]]);
        return 0;
    }else{
        return MulExpError(sonNode);
    }
}
// 常量表达式 ConstExp → AddExp
void ConstExpError(NODE curNode){
    NODE sonNode = node[curNode.son[0]];
    AddExpError(sonNode);
}
/*
int main(){

    string x = "abcdef";
    if(x.find("bcd")!= string::npos)cout<<"yes";
    else cout<<"no";
}*/