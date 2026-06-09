#include<bits/stdc++.h>
using namespace std;

void check();//本地检查文件输出
int j,flag;
unordered_set<int> ErrorA;
/*词法*/
unordered_map<string,string> Word2Type;
vector<pair<string,string>> word;// 存储分解后的所有单词及类型
vector<int>lineNumber;//存储单词对应的行号
vector<pair<int,char>> err;//存储错误的行号以及类别（字母）
unordered_set<char> sym={'!','&','|','+','-','*','/','%','<','>','=',' ',',',';','(',')','[',']','{','}'};
bool isAnnot = 0; //是否处于多行注释状态（单行注释直接跳过该行）
int nowLineNum = 0;//目前行号
string token;//单个单词

void init_Word2Type();//初始化单词对应类别码
void Read(string buf);//读取一行
string getLexType(string word);//获得读取的单词类型
void pushWord();//单词入栈
bool isNum(string token);
bool isIdent(string token);

/*文法*/
vector<string> res;
string now;//目前的单词
string preRead;//预读
string prePreRead;
int Index = 0;

void next();
void Grammer();
void ConstDecl();
void ConstDef();
void ConstInitVal();
void VarDecl();
void VarDef();
void InitVal();
void FuncDef();
void MainFuncDef();
void FuncFParams();
void FuncFParam();
void Block();
void BlockItem();
void Stmt();
void ForStmt();
void Exp();
void Cond();
void LVal();
void PrimaryExp();
void UnaryExp();
void FuncRParams();
void MulExp();
void AddExp();
void RelExp();
void EqExp();
void LAndExp();
void LOrExp();
void ConstExp();

bool isBType();
bool isFuncType();
bool isIdent1();
bool isConst();
bool isUnaryOp();// + - !
bool isMulOp();// * / %
bool isAddOp();// + -
bool isRelOp();// < > <= >=
bool isEqOp();// == !=
bool isLAndOp();// &&
bool isLOrOp();// ||
int main() {
    init_Word2Type();
    ifstream input;
    input.open("testfile.txt",ios::in);

    if(!input.is_open()) cout<<"打开文件失败"<<"\n";
    else{
        string buf;
        while(getline(input,buf)){
            nowLineNum++;
            Read(buf);
        }
        input.close();
    }
    Grammer();
    if(err.empty()){
        ofstream output("parser.txt");
        for(auto e : res) output<<e<<"\n";
        output.close();
    }
    else{
        ofstream output("error.txt");
        for(auto e : err) output<<e.first<<" "<<e.second<<"\n";
    }
    //check();
    return 0;
}
void check() {
    ifstream lexerFile("parser.txt");
    ifstream ansFile("ans.txt");
    if (!lexerFile.is_open() || !ansFile.is_open()) {
        cerr << "无法打开文件。" << endl;
    }
    string lexerLine, ansLine;
    int lineNumber = 1;
    bool foundDifference = false;
    ofstream output("E.txt");
    while (getline(lexerFile, lexerLine) && getline(ansFile, ansLine)) {
        if (lexerLine != ansLine) {
            output <<  lineNumber << endl;
            output << "parser.txt: " << lexerLine << " length:" << lexerLine.length() << endl;
            //for(auto e : lexerLine) cout<<(int)e<<" ";cout<<"\n";
            output << "ans.txt: " << ansLine << " length:" << ansLine.length() << endl;
            //for(auto e : ansLine) cout<<(int)e<<" ";cout<<"\n";
            foundDifference = true;
        }
        lineNumber++;
    }
    if (!foundDifference) {
        cout << "666" << endl;
    }
    lexerFile.close();
    ansFile.close();
}
void init_Word2Type(){
    vector<string>key={"main","const","int","char","break","continue","if","else","!","&&","||","for","getint","getchar","printf","return","+","-","void","*","/","%","<","<=",">",">=","==","!=","=",";",",","(",")","[","]","{","}"};
    vector<string>value={"MAINTK","CONSTTK","INTTK","CHARTK","BREAKTK","CONTINUETK","IFTK","ELSETK","NOT","AND","OR","FORTK","GETINTTK","GETCHARTK","PRINTFTK","RETURNTK","PLUS","MINU","VOIDTK","MULT","DIV","MOD","LSS","LEQ","GRE","GEQ","EQL","NEQ","ASSIGN","SEMICN","COMMA","LPARENT","RPARENT","LBRACK","RBRACK","LBRACE","RBRACE"};
    while(!key.empty()){
        Word2Type.emplace(key.back(),value.back());
        key.pop_back();
        value.pop_back();
    }
}
void Read(string buf){
    int l = buf.length();
    for(int i=0;i<l;i++){
        if(isAnnot){
            if(buf[i]!='*') continue;
            else if(i+1<=l-1&&buf[i+1]=='/'){
                i++;
                isAnnot = 0;
                continue;
            }
            else continue;         
        }
        if(buf[i]=='"'){
            token+='"';
            while(buf[++i]!='"'){
                token+=buf[i];
            }
            token+='"';
            pushWord();
        }
        else if(buf[i]=='\''){
            token+='\'';     
            if(buf[i+3]=='\''){
                token+=buf[i+1];
                token+=buf[i+2];
                token+='\'';
                i+=3;
            }
            else if(buf[i+2]=='\''){
                token+=buf[i+1];
                token+='\'';
                i+=2;
            }
            pushWord();
        }
        else if(sym.find(buf[i])!=sym.end()){
            pushWord();
            if(buf[i]!=' ') token+=buf[i];
            
            if(buf[i]=='&'||buf[i]=='|') {
                if(buf[i+1]!=buf[i]){
                    token+=buf[i];
                    //err.push_back({nowLineNum,'a'});
                    pushWord();
                    ErrorA.emplace(word.size() - 1);
                }
                else {
                    token+=buf[++i];
                    pushWord();
                }
            }
            else if(buf[i]=='!'||buf[i]=='<'||buf[i]=='='||buf[i]=='>'){
                if(buf[i+1]=='=') token+=buf[++i];
                pushWord();
            }
            else if(buf[i]=='/'&&buf[i+1]=='*'){
                isAnnot = 1;
                token = "";
            }
            else if(buf[i]=='/'&&buf[i+1]=='/'){
                token = "";
                break;
            }
            else if(buf[i]!=' ') pushWord();
        }
        else if(buf[i]>=32&&buf[i]<=126) token+=buf[i];
    }
    pushWord();
}
string getLexType(string word){
    auto it = Word2Type.find(word);
    if(it!=Word2Type.end()) return it->second;
    else if(isNum(word)) return "INTCON";
    else if(word[0]=='"') return "STRCON";
    else if(word[0]=='\'') return "CHRCON";
    else if(isIdent(word)) return "IDENFR";
    else return "123";
}
void pushWord(){
    if(token == "") return;
    word.push_back({getLexType(token),token});
    lineNumber.push_back(nowLineNum);
    token = "";
}
bool isNum(string token){
    int l = token.length();
    for(int i=0;i<l;i++){
        if(!isdigit(token[i])) return 0;
        }
    return 1;
}
bool isIdent(string token){
    int l = token.length();
    if(token[0]!='_'&&!isalpha(token[0])) return 0;
    for(int i=1;i<l;i++){
        char ch = token[i];
        if((!isalpha(ch))&&(!isdigit(ch))&&(ch!='_')) return 0;
    }
    return 1;
}

void Grammer(){
    now = word[0].first;//目前的单词
    preRead = word[1].first;//预读
    prePreRead = word[2].first;
    word.resize(word.size() + 2);
    int t = word.size() - 2;
    while(Index < t){
        //cout<<Index+1<<" "<<now<<"\n";
        if(isConst()) ConstDecl();
        else if(now == "CHARTK"){
            if((word[Index+1].first)=="IDENFR"){
                if(prePreRead  == "ASSIGN" || prePreRead == "SEMICN" || prePreRead == "COMMA"|| prePreRead == "LBRACK") VarDecl();
                else if(prePreRead == "LPARENT") FuncDef();
                else{
                    next();
                    next();
                    err.push_back({lineNumber[Index-1],'i'});
                }
            }
        } 
        else if(now == "INTTK"){
            if(preRead == "MAINTK"){
                MainFuncDef();
            }
            else if((word[Index+1].first)=="IDENFR"){
                if(prePreRead  == "ASSIGN" || prePreRead == "SEMICN" || prePreRead == "COMMA" || prePreRead == "LBRACK") VarDecl();
                else if(prePreRead  == "LPARENT") FuncDef();
                else{
                    next();
                    next();
                    err.push_back({lineNumber[Index-1],'i'});
                }
            }
        }
        else if(now == "VOIDTK"){
            FuncDef();
        }
        else if(now == "IFTK" || now == "FORTK" || now == "BREAKTK" || now == "RETURNTK") Stmt();
    }
    res.push_back("<CompUnit>");
}
void next(){
    if(ErrorA.find(Index)!=ErrorA.end()) err.push_back({lineNumber[Index],'a'});
    else res.push_back(word[Index].first + " " + word[Index].second);
    //cout<<Index+1<<" "<<word[Index].second<<"\n";
    Index++;
    now = preRead;
    preRead = prePreRead;
    prePreRead = word[Index+2].first;
}
bool isBType(){
    if(now == "INTTK" || now == "CHARTK") return 1;
    return 0;
}
bool isIdent1(){
    if(now == "IDENFR") return 1;
    return 0;
}
bool isConst(){
    return (now == "CONSTTK");
}
bool isFuncType(){
    if(now == "VOIDTK" || now == "INTTK" || now == "CHARTK") return 1;
    return 0; 
}
bool isUnaryOp(){// + - !
    if(now == "PLUS"|| now == "MINU" || now == "NOT") return 1;
    return 0;
}
bool isMulOp(){// * / %
    if(now == "MULT" || now == "DIV" || now == "MOD"){
        res.push_back("<MulExp>");
        return 1;
    }
    return 0;
}
bool isAddOp(){// + -
    if(now == "PLUS" || now == "MINU" ){
        res.push_back("<AddExp>");
        return 1;
    }
    return 0;
}
bool isRelOp(){// < > <= >=
    if(now == "LSS" || now == "GRE" || now == "LEQ" || now == "GEQ"){
        res.push_back("<RelExp>");
        return 1;
    }
    return 0;
}
bool isEqOp(){// == !=
    if(now == "EQL" || now == "NEQ" ){
        res.push_back("<EqExp>");
        return 1;
    }
    return 0;
}
bool isLAndOp(){// &&
    if(now == "AND" ){
        res.push_back("<LAndExp>");
        return 1;
    }
    return 0;
}
bool isLOrOp(){// ||
    if(now == "OR"){
        res.push_back("<LOrExp>");
        return 1;
    }
    return 0;
}
void Decl(){
    if(isConst()) ConstDecl();
    else if(isBType()) VarDecl();
}
void ConstDecl(){
    if(isConst()){
        next();
        if(isBType()){
            next();
            ConstDef();
            while (now == "COMMA"){
                next();
                ConstDef();
            }
            if(now == "SEMICN") next();
            else{
                err.push_back({lineNumber[Index-1],'i'});//0
            }
        }
    }
    res.push_back("<ConstDecl>");
}
void ConstDef(){
    if(isIdent1()){
        next();
        if(now == "LBRACK"){
            next();
            if(now != "RBRACK"){
                ConstExp();
            }
            if(now == "RBRACK") next();
            else err.push_back({lineNumber[Index-1],'k'});//0
        }
        if(now == "ASSIGN"){
            next();
            ConstInitVal();
        }
    }
    res.push_back("<ConstDef>");
}
void ConstInitVal(){
    if(now == "LBRACE"){
        next();
        if(now != "RBRACE"){
            ConstExp();
            while(now == "COMMA"){
                next();
                ConstExp();
            }
        }
        if(now == "RBRACE") next();
    }
    else if(now != "STRCON") ConstExp();
    else next();
    res.push_back("<ConstInitVal>");
}
void VarDecl(){
    if(isBType()){
        next();
        VarDef();
        while(now == "COMMA"){
            next();
            VarDef();
        }
        if(now == "SEMICN") next();
        else err.push_back({lineNumber[Index-1],'i'});//testcase 16
    }
    res.push_back("<VarDecl>");
}
void VarDef(){
    if(isIdent1()){
        next();
        if(now == "LBRACK"){
            next();
            ConstExp();
            if(now == "RBRACK") next();
            else err.push_back({lineNumber[Index-1],'k'});//testcase 19
        }
        if(now == "ASSIGN"){
            next();
            InitVal();
        }
    }
    res.push_back("<VarDef>");
}
void InitVal(){
    if(now == "LBRACE"){
        next();
        if(now != "RBRACE"){
            Exp();
            while(now == "COMMA"){
                next();
                Exp();
            }
        }
        if(now == "RBRACE") next();
    }
    else if(now == "STRCON") next();
    else Exp();
    res.push_back("<InitVal>");
}
void FuncDef(){
    if(isFuncType()){
        next();
        res.push_back("<FuncType>");
        if(isIdent1()){
            next();
            if(now == "LPARENT"){
                next();
                if(now != "RPARENT"){
                    FuncFParams();
                }
                if(now == "RPARENT"){
                    next();
                    Block();
                }
                else if(now == "LBRACE"){
                    err.push_back({lineNumber[Index-1],'j'});//testcase 17
                    Block();
                }
            }
        }
    }
    res.push_back("<FuncDef>");
}
void MainFuncDef(){
    if(now == "INTTK"){
        next();
        if(now == "MAINTK"){
            next();
            if(now == "LPARENT"){
                next();
                if(now == "RPARENT"){
                    next();
                    Block();
                }
                else{
                    err.push_back({lineNumber[Index-1],'j'});//testcase 17
                    Block();
                }
            }
        }
    }
    res.push_back("<MainFuncDef>");
}
void FuncFParams(){
    FuncFParam();
    while(now == "COMMA"){
        next();
        FuncFParam();
    }
    res.push_back("<FuncFParams>");
}
void FuncFParam(){
    if(isBType()){
        next();
        if(isIdent1()){
            next();
            if(now == "LBRACK"){
                next();
                if(now == "RBRACK") next();
                else err.push_back({lineNumber[Index-1],'k'});//testcase 19
            }
        }
    }
    res.push_back("<FuncFParam>");
}
void Block(){
    if(now == "LBRACE"){
        next();
        while(now != "RBRACE"){
            BlockItem();
        }
        if(now == "RBRACE") next();
    }
    res.push_back("<Block>");
}
void BlockItem(){
    if(isBType() || isConst()) Decl();
    else Stmt();
}
void Stmt(){
    if(now == "IFTK"){
        next();
        if(now == "LPARENT"){
            next();
            Cond();
            if(now == "RPARENT"){
                next();
                Stmt();
                if(now == "ELSETK"){
                    next();
                    Stmt();
                }
            }
            else{
                err.push_back({lineNumber[Index-1],'j'});//testcase 18
                Stmt();
                if(now == "ELSETK"){
                    next();
                    Stmt();
                }
            }
        }
    }
    else if(now == "FORTK"){
        next();
        if(now == "LPARENT"){
            next();
            if(now != "SEMICN"){
                ForStmt();
            }
            if(now == "SEMICN"){
                next();
                if(now != "SEMICN"){
                    Cond();
                }
                if(now == "SEMICN"){
                    next();
                    if(now != "RPARENT"){
                        ForStmt();
                    }
                    if(now == "RPARENT"){
                        next();
                        Stmt();
                    }
                }
            }
        }
    }
    else if(now == "BREAKTK" || now == "CONTINUETK"){
        next();
        if(now == "SEMICN") next();
        else err.push_back({lineNumber[Index-1],'i'});//0
    }
    else if(now == "RETURNTK"){
        next();
        if(now != "SEMICN"){
            Exp();
        }
        if(now == "SEMICN") next();
        else err.push_back({lineNumber[Index-1],'i'});//testcase 16
    }
    else if(now == "PRINTFTK"){
        next();
        if(now == "LPARENT"){
            next();
            if(now == "STRCON"){
                next();
                while(now == "COMMA"){
                    next();
                    Exp();
                }
                if(now == "RPARENT"){
                    next();
                    if(now == "SEMICN") next();
                    else err.push_back({lineNumber[Index-1],'i'});//testcase 16
                }
                else {
                    err.push_back({lineNumber[Index-1],'j'});//testcase 20
                    if(now == "SEMICN") next();
                    else err.push_back({lineNumber[Index-1],'i'});//0
                }
            }
        }
    }
    else if(now == "LBRACE") Block();
    else if(now == "SEMICN") next();
    else{//预读到 ;之前的=
        j = Index;
        flag = 0;
        while(word[j].first != "SEMICN"){
            if(word[j].first == "ASSIGN"){
                flag = 1;
                break;
            }
            j++;
        }
        if(!flag){
            Exp();
            if(now == "SEMICN") next();
            else err.push_back({lineNumber[Index-1],'i'});
        }
        else if(word[j+1].first == "GETINTTK" || word[j+1].first == "GETCHARTK"){
            LVal();
            if(now == "ASSIGN"){
                next();
                next();
                if(now == "LPARENT"){
                    next();
                    if(now == "RPARENT"){
                        next();
                        if(now == "SEMICN") next();
                        else{
                            err.push_back({lineNumber[Index-1],'i'});
                        }
                    }
                    else{
                        err.push_back({lineNumber[Index-1],'j'});
                        if(now == "SEMICN") next();
                        else{
                            err.push_back({lineNumber[Index-1],'i'});
                        }
                    }
                }
            }
        }
        else{
            LVal();
            if(now == "ASSIGN"){
                next();
                Exp();
                if(now == "SEMICN") next();
                else err.push_back({lineNumber[Index-1],'i'});
            }
        }
    }
    res.push_back("<Stmt>");
}
void ForStmt(){
    LVal();
    if(now == "ASSIGN"){
        next();
        Exp();
    }
    res.push_back("<ForStmt>");
}
void Exp(){
    AddExp();
    res.push_back("<Exp>");
}
void Cond(){
    LOrExp();
    res.push_back("<Cond>");
}
void LVal(){
    if(isIdent1()){
        next();
        if(now == "LBRACK"){
            next();
            Exp();
            if(now == "RBRACK") next();
            else err.push_back({lineNumber[Index-1],'k'});
        }
    }
    res.push_back("<LVal>");
}
void PrimaryExp(){
    if(now == "LPARENT"){
        next();
        Exp();
        if(now == "RPARENT") next();
        else err.push_back({lineNumber[Index-1],'j'});
    }
    else if(isIdent1()) LVal();
    else if(now == "INTCON"){
        next();
        res.push_back("<Number>");
    }
    else if(now == "CHRCON"){
        next();
        res.push_back("<Character>");
    }
    res.push_back("<PrimaryExp>");
}
void UnaryExp(){
    if(isIdent1()&&preRead == "LPARENT"){
        next();
        next();
        if(now != "RPARENT") FuncRParams();
        if(now == "RPARENT") {
            next();
        }
        else err.push_back({lineNumber[Index-1],'j'});
    }
    else if(isUnaryOp()){
        next();
        res.push_back("<UnaryOp>");
        UnaryExp();
    }
    else PrimaryExp();
    res.push_back("<UnaryExp>");
}
void FuncRParams(){
    Exp();
    while(now == "COMMA"){
        next();
        Exp();
    }
    res.push_back("<FuncRParams>");
}
void MulExp(){
    UnaryExp();
    while(isMulOp()){
        next();
        UnaryExp();
    }
    res.push_back("<MulExp>");
}
void AddExp(){
    MulExp();
    while(isAddOp()){
        next();
        MulExp();
    }
    res.push_back("<AddExp>");
}
void RelExp(){
    AddExp();
    while(isRelOp()){
        next();
        AddExp();
    }
    res.push_back("<RelExp>");
}
void EqExp(){
    RelExp();
    while(isEqOp()){
        next();
        RelExp();
    }
    res.push_back("<EqExp>");
}
void LAndExp(){
    EqExp();
    while(isLAndOp()){
        next();
        EqExp();
    }
    res.push_back("<LAndExp>");
}
void LOrExp(){
    LAndExp();
    while(isLOrOp()){
        next();
        LAndExp();
    }
    res.push_back("<LOrExp>");
}
void ConstExp(){
    AddExp();
    res.push_back("<ConstExp>");
}