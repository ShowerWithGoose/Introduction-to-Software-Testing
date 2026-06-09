package frontend;
// 想用其他文件中的东西，就要import [src下的路径一直到该元素为止]
import frontend.Lexer.Token;
import frontend.nodes.ASTNode;


import java.io.IOException;
import java.util.ArrayList;

import static frontend.Lexer.tokens;

public class Parser {
    private int curPos = 0; // 处理到tokens的哪个位置
    private final int len = tokens.size(); // tokens列表的长度，用于判断是否分析结束 curPos == len
    private Token curtoken;
    private ASTNode tmp; // 用于构建树的一个结点变量
    private ASTNode newParent;

    public ASTNode Parser() throws IOException {
        getsym(0);
        ASTNode Root = CompUnit();
        return Root;
    }

    private ASTNode CompUnit(){ // CompUnit → {Decl} {FuncDef} MainFuncDef
        curtoken = tokens.get(curPos);
        ASTNode CompUnit = new ASTNode("CompUnit"); // 语法树根节点
        // 全局变量 Decl
        while(curPos < len && (getWord(0).equals("const") ||
                ((getWord(0).equals("int") || getWord(0).equals("char")) && getType(1).equals("IDENFR") && !getType(2).equals("LPARENT")))){
            // 识别到了Decl，就可以把Decl结点接在CompUnit下，再去Decl的子程序
            addNode(CompUnit,"Decl");
            Decl(tmp); // tmp为传过去的刚加入的结点
        }
        // 函数 FuncDef
        while(curPos < len && (getWord(0).equals("void") ||
                ((getWord(0).equals("int") || getWord(0).equals("char")) && getType(1).equals("IDENFR")))){
            addNode(CompUnit,"FuncDef");
            FuncDef(tmp);
        }
        // MainFuncDef
        addNode(CompUnit,"MainFuncDef");
        MainFuncDef(tmp);
        return CompUnit;
    }

    // parent就是文法的左部，文法右部的父节点
    private void Decl(ASTNode parent){ // Decl → ConstDecl | VarDecl
        if(getWord(0).equals("const")){
            addNode(parent,"ConstDecl");
            ConstDecl(tmp);
        }
        else{
            addNode(parent,"VarDecl");
            VarDecl(tmp);
        }
    }

    private void ConstDecl(ASTNode parent){ // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
        if(getWord(0).equals("const")){
            // 将const加入树
            addNode(parent,"const","CONSTTK");
            nextToken();
            // 这里也将BType加入了树，输出的时候不要输出即可
            addNode(parent,"BType");
            BType(tmp);
            addNode(parent,"ConstDef");
            ConstDef(tmp);
            while(curtoken.type.equals("COMMA")){
                addNode(parent,",","COMMA");
                nextToken();
                addNode(parent,"ConstDef");
                ConstDef(tmp);
            }
            if(curtoken.value.equals(";")){
                addNode(parent,curtoken.value,curtoken.type);
                nextToken();
            }
            else{
                addNode(parent,";","SEMICN",'i');
            }
        }
    }

    private void BType(ASTNode parent){ //BType → 'int' | 'char'
        if(curtoken.value.equals("int")) {
            addNode(parent,"int","INTTK");
        }
        else {
            addNode(parent,"char","CHARTK");
        }
        nextToken();
    }

    private void ConstDef(ASTNode parent){ //ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        addNode(parent,getsym(0).value,"IDENFR");
        nextToken();
        if(curtoken.value.equals("[")){
            addNode(parent,"[","LBRACK");
            nextToken();
            addNode(parent,"ConstExp");
            ConstExp(tmp);
            addNode(parent,"]","RBRACK");
            nextToken();
        }
        addNode(parent,"=","ASSIGN");
        nextToken();
        addNode(parent,"ConstInitVal");
        ConstInitVal(tmp);
    }

    private void ConstInitVal(ASTNode parent){// 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        // '{' [ ConstExp { ',' ConstExp } ] '}'
        if(curtoken.value.equals("{")){
            addNode(parent,"{","LBRACE");
            nextToken();
            if(!curtoken.value.equals("}")){ // 此处直接判断是不是}即可！用不着FIRST(ConstExp)
                addNode(parent,"ConstExp");
                ConstExp(tmp);
                while(curtoken.type.equals("COMMA")){
                    addNode(parent,curtoken.value,"COMMA");
                    nextToken();
                    addNode(parent,"ConstExp");
                    ConstExp(tmp);
                }
            }
            addNode(parent,"}","RBRACE");
            nextToken();
        }
        // StringConst
        else if(curtoken.type.equals("STRCON")){
            addNode(parent,curtoken.value,"STRCON");
            nextToken();
        }
        // ConstExp 这个难判断，直接用else避免判断FIRST(ConstExp)
        else{
            addNode(parent,"ConstExp");
            ConstExp(tmp);
        }
    }

    private void VarDecl(ASTNode parent){// 变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // i
        addNode(parent,"BType");
        BType(tmp);
        addNode(parent,"VarDef");
        VarDef(tmp);
        while(curtoken.type.equals("COMMA")){
            addNode(parent,curtoken.value,"COMMA");
            nextToken();
            addNode(parent,"VarDef");
            VarDef(tmp);
        }
        if(curtoken.value.equals(";")){
            addNode(parent,curtoken.value,curtoken.type);
            nextToken();
        }
        else{
            addNode(parent,";","SEMICN",'i');
        }
    }

    // 改写文法为 VarDef → Ident [ '[' ConstExp ']' ] [ '=' InitVal ]
    private void VarDef(ASTNode parent){// 变量定义 VarDef → Ident ['[' ConstExp ']'] | Ident ['[' ConstExp ']'] '=' InitVal // k
        addNode(parent,curtoken.value,"IDENFR");
        nextToken();
        if(curtoken.type.equals("LBRACK")){
            addNode(parent,curtoken.value,"LBRACK");
            nextToken();
            addNode(parent,"ConstExp");
            ConstExp(tmp);
            if(curtoken.value.equals("]")){
                addNode(parent,curtoken.value,"RBRACK");
                nextToken();
            }
            else addNode(parent,curtoken.value,"RBRACK",'k');
        }
        if(curtoken.type.equals("ASSIGN")){
            addNode(parent,curtoken.value,"ASSIGN");
            nextToken();
            addNode(parent,"InitVal");
            InitVal(tmp);
        }
    }

    private void InitVal(ASTNode parent){ // 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        if(curtoken.value.equals("{")){
            addNode(parent,"{","LBRACE");
            nextToken();
            if(!curtoken.value.equals("}")){ // 此处直接判断是不是'}'即可！用不着FIRST(Exp)
                addNode(parent,"Exp");
                Exp(tmp);
                while(curtoken.type.equals("COMMA")){
                    addNode(parent,curtoken.value,"COMMA");
                    nextToken();
                    addNode(parent,"Exp");
                    Exp(tmp);
                }
                addNode(parent,"}","RBRACE");
                nextToken();
            }
        }
        else if(curtoken.type.equals("STRCON")){
            addNode(parent,curtoken.value,"STRCON");
            nextToken();
        }
        else{
            addNode(parent,"Exp");
            Exp(tmp);
        }
    }

    private void FuncDef(ASTNode parent){ //函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
        addNode(parent,"FuncType");
        FuncType(tmp);
        addNode(parent,curtoken.value,"IDENFR");
        nextToken();
        addNode(parent, curtoken.value,"LPARENT");
        nextToken();
        if(isFuncFParams()){
            addNode(parent,"FuncFParams");
            FuncFParams(tmp);
        }
        // 对可能缺少右括号的处理
        if(curtoken.type.equals("RPARENT")){
            addNode(parent,curtoken.value,"RPARENT");
            nextToken();
        }
        else{// 补充缺少的错误结点！
            addNode(parent,")","RPARENT",'j');
        }
        addNode(parent,"Block");
        Block(tmp);
    }


    private void MainFuncDef(ASTNode parent){ //主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block // g j
        addNode(parent, curtoken.value,"INTTK");
        nextToken();
        addNode(parent, curtoken.value,"MAINTK");
        nextToken();
        addNode(parent, curtoken.value,"LPARENT");
        nextToken();
        if(curtoken.value.equals(")")){
            addNode(parent, curtoken.value,"RPARENT");
            nextToken();
        }
        else{
            addNode(parent, curtoken.value,"RPARENT",'j');
        }
        addNode(parent, "Block");
        //传入一个flag检测最终是否有return
        Block(tmp);
    }

    private void FuncType(ASTNode parent){ // FuncType → 'void' | 'int' | 'char'
        addNode(parent,curtoken.value,curtoken.type);
        nextToken();
    }

    private void FuncFParams(ASTNode parent) { // 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
        addNode(parent,"FuncFParam");
        FuncFParam(tmp);
        while(curtoken.value.equals(",")){
            addNode(parent,curtoken.value,"COMMA");
            nextToken();
            addNode(parent,"FuncFParam");
            FuncFParam(tmp);
        }
    }

    private void FuncFParam(ASTNode parent){//函数形参 FuncFParam → BType Ident ['[' ']'] // b k
        addNode(parent,"BType");
        BType(tmp);
        addNode(parent,curtoken.value,"IDENFR");
        nextToken();
        if(curtoken.value.equals("[")){
            addNode(parent,curtoken.value,"LBRACK");
            nextToken();
            if(curtoken.value.equals("]")){
                addNode(parent,curtoken.value,"RBRACK");
                nextToken();
            }
            else{
                addNode(parent,curtoken.value,"RBRACK",'k');
            }
        }
    }

    private void Block(ASTNode parent){ // 语句块 Block → '{' { BlockItem } '}'
        addNode(parent,curtoken.value,"LBRACE");
        nextToken();
        while(!curtoken.value.equals("}")){
            addNode(parent,"BlockItem");
            BlockItem(tmp);
        }
        addNode(parent,curtoken.value,"RBRACE");
        nextToken();
    }

    private void BlockItem(ASTNode parent){ // 语句块项 BlockItem → Decl | Stmt  2者的FIRST集无交叠，无需预读
        if(isDecl()){
            addNode(parent,"Decl");
            Decl(tmp);
        }
        else{
            addNode(parent,"Stmt");
            Stmt(tmp);
        }
    }

    private void Stmt(ASTNode parent){
        switch(curtoken.value){
            case "{": // Block
                addNode(parent,"Block");
                Block(tmp);
                break;
            case "if": //'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
                addNode(parent,curtoken.value,"IFTK");
                nextToken();
                addNode(parent,curtoken.value,curtoken.type);//(
                nextToken();
                addNode(parent,"Cond");
                Cond(tmp);
                if(curtoken.value.equals(")")){
                    addNode(parent,curtoken.value,curtoken.type);
                    nextToken();
                }
                else addNode(parent,")","RPARENT",'j');
                addNode(parent,"Stmt");
                Stmt(tmp);
                if(curtoken.value.equals("else")){
                    addNode(parent,curtoken.value,curtoken.type);
                    nextToken();
                    addNode(parent,"Stmt");
                    Stmt(tmp);
                }
                break;
            case "for": // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
               addNode(parent,curtoken.value,curtoken.type); // for
               nextToken();
               addNode(parent,curtoken.value,curtoken.type); // (
               nextToken();
               if(!curtoken.value.equals(";")){
                   addNode(parent,"ForStmt");
                   ForStmt(tmp);
               }
               addNode(parent,curtoken.value,curtoken.type); // ;
               nextToken();
               if(!curtoken.value.equals(";")){
                   addNode(parent,"Cond");
                   Cond(tmp);
                   //System.out.println(curtoken.value);
               }
               addNode(parent,curtoken.value,curtoken.type); // ;
               nextToken();
               //System.out.println(curtoken.value);
               if(!curtoken.value.equals(")")){
                   addNode(parent,"ForStmt");
                   ForStmt(tmp);
               }
               addNode(parent,curtoken.value,curtoken.type); // )
               nextToken();
               addNode(parent,"Stmt");
               Stmt(tmp);
               break;
            case "break": //  'break' ';' // i
                addNode(parent,curtoken.value,curtoken.type);
                nextToken();
                if(curtoken.value.equals(";")){
                    addNode(parent,";","SEMICN");
                    nextToken();
                }
                else addNode(parent,";","SEMICN",'i');
                break;
            case "continue": // 'continue' ';' // i
                addNode(parent,curtoken.value,curtoken.type);
                nextToken();
                if(curtoken.value.equals(";")){
                    addNode(parent,";","SEMICN");
                    nextToken();
                }
                else addNode(parent,";","SEMICN",'i');
                break;
            case "return": // 'return' [Exp] ';' // i
                addNode(parent,curtoken.value,curtoken.type);
                nextToken();
                if(is_Exp_()){
                    addNode(parent,"Exp");
                    Exp(tmp);
                }
                if(curtoken.value.equals(";")){
                    addNode(parent,curtoken.value,curtoken.type);
                    nextToken();
                }
                else addNode(parent,";","SEMICN",'i');
                break;
            case "printf": // 'printf''('StringConst {','Exp}')'';' // i j
                addNode(parent,curtoken.value,curtoken.type);
                nextToken();
                addNode(parent,curtoken.value,curtoken.type);
                nextToken();
                addNode(parent,curtoken.value,curtoken.type);
                nextToken();
                while(curtoken.value.equals(",")){
                    addNode(parent,curtoken.value,curtoken.type);
                    nextToken();
                    addNode(parent,"Exp");
                    Exp(tmp);
                }
                if(curtoken.value.equals(")")){
                    addNode(parent,curtoken.value,curtoken.type);
                    nextToken();
                }
                else addNode(parent,")","RPARENT",'j');
                if(curtoken.value.equals(";")){
                    addNode(parent,curtoken.value,curtoken.type);
                    nextToken();
                }
                else addNode(parent,";","SEMICN",'i');
                break;
            case ";":
                addNode(parent,curtoken.value,curtoken.type);
                nextToken();
                break;
            default: //难的4个
                int backPos = curPos; // 回溯位置
                // 假设走LVal
                addNode(parent,"LVal");
                LVal(tmp);
                if(!curtoken.value.equals("=")){
                    curPos = backPos; //单词流回溯
                    curtoken = tokens.get(curPos);//单词流回溯
                    parent.delete(); // 删LVal , 树结构回溯
                    addNode(parent,"Exp");
                    Exp(tmp);
                    if(curtoken.value.equals(";")){
                        addNode(parent,curtoken.value,curtoken.type);
                        nextToken();
                    }
                    else addNode(parent,";","SEMICN",'i');
                }
                else{
                    addNode(parent,curtoken.value,curtoken.type);
                    nextToken();
                    if(curtoken.value.equals("getint") || curtoken.value.equals("getchar")){
                        addNode(parent,curtoken.value,curtoken.type);
                        nextToken();
                        addNode(parent,curtoken.value,curtoken.type); // (
                        nextToken();
                        if(curtoken.value.equals(")")){
                            addNode(parent,curtoken.value,curtoken.type);
                            nextToken();
                        }
                        else{
                            addNode(parent,")","RPARENT",'j');
                        }
                        if(curtoken.value.equals(";")){
                            addNode(parent,curtoken.value,curtoken.type);
                            nextToken();
                        }
                        else{
                            addNode(parent,";","SEMICN",'i');
                        }
                    }
                    else{
                        addNode(parent,"Exp");
                        Exp(tmp);
                        if(curtoken.value.equals(";")){
                            addNode(parent,curtoken.value,curtoken.type);
                            nextToken();
                        }
                        else{
                            addNode(parent,";","SEMICN",'i');
                        }
                    }
                }
        }
    }


    private void ForStmt(ASTNode parent){ // ForStmt → LVal '=' Exp
        addNode(parent,"LVal");
        LVal(tmp);
        addNode(parent,"=","ASSIGN");
        nextToken();
        addNode(parent,"Exp");
        Exp(tmp);
    }

    private void Exp(ASTNode parent){ // Exp → AddExp
        addNode(parent,"AddExp");
        AddExp(tmp);
    }

    private void Cond(ASTNode parent){ // 条件表达式 Cond → LOrExp
        addNode(parent,"LOrExp");
        LOrExp(tmp);
    }

    private void LVal(ASTNode parent){ //左值表达式 LVal → Ident ['[' Exp ']'] // k
        addNode(parent, curtoken.value,"IDENFR");
        nextToken();
        if(curtoken.value.equals("[")){
            addNode(parent,"[","LBRACK");
            nextToken();
            addNode(parent,"Exp");
            Exp(tmp);
            if(curtoken.value.equals("]")){
                addNode(parent,"]","RBRACK");
                nextToken();
            }
            else{
                addNode(parent,"]","RBRACK",'k');
            }
        }
    }

    private void PrimaryExp(ASTNode parent){//  基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character // j
        if(curtoken.value.equals("(")){
            addNode(parent,"(","LPARENT");
            nextToken();
            addNode(parent,"Exp");
            Exp(tmp);
            if(curtoken.value.equals(")")){
                addNode(parent,")","RPARENT");
                nextToken();
            }
            else{
                addNode(parent,")","RPARENT",'j');
            }
        }
        else if(isLVal()){
            addNode(parent,"LVal");
            LVal(tmp);
        }
        else if(isNumber()){
            addNode(parent,"Number");
            Number_(tmp);
        }
        else if(isCharacter()){
            addNode(parent,"Character");
            Character_(tmp);
        }
    }

    private void Number_(ASTNode parent) {
        addNode(parent,curtoken.value,"INTCON");
        nextToken();
    }

    private void Character_(ASTNode parent) {
        addNode(parent,curtoken.value,"CHRCON");
        nextToken();
    }

    //需要预读，FIRST(Ident)与FIRST(PrimaryExp)都有IDENFR
    private void UnaryExp(ASTNode parent){ // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j

        if(isUnaryOp()) {
            addNode(parent,"UnaryOp");
            UnaryOp(tmp);
            addNode(parent,"UnaryExp");
            UnaryExp(tmp);
        }
        // Ident '(' [FuncRParams] ')'
        else if(isIdent() & getsym(1).value.equals("(")) { ////////存疑！！！万一PrimaryExp后的语法成分是(咋办
            addNode(parent,curtoken.value,curtoken.type);//ident
            nextToken();
            addNode(parent,curtoken.value,curtoken.type);//(
            nextToken();
            if(isFuncRParams()) {
                addNode(parent,"FuncRParams");
                FuncRParams(tmp);
            }
            if(curtoken.value.equals(")")){
                addNode(parent,curtoken.value,curtoken.type);
                nextToken();
            }
            else addNode(parent,")","RPARENT",'j');
        }
        else {
            addNode(parent,"PrimaryExp");
            PrimaryExp(tmp);
        }
    }

    private void FuncRParams(ASTNode parent) { // FuncRParams → Exp { ',' Exp }
        addNode(parent,"Exp");
        Exp(tmp);
        while(curtoken.value.equals(",")) {
            addNode(parent,curtoken.value,curtoken.type);
            nextToken();
            addNode(parent,"Exp");
            Exp(tmp);
        }
    }

    // 改写文法：MulExp → UnaryExp { ('*' | '/' | '%') UnaryExp }
    private void MulExp(ASTNode parent){
        //System.out.println(curtoken.value);
        addNode(parent,"UnaryExp");
        UnaryExp(tmp);
        //System.out.println(curtoken.value);
        while(curtoken.value.equals("*") || curtoken.value.equals("/") || curtoken.value.equals("%")){

            ASTNode newNode = new ASTNode("MulExp"); // 新建一个MulExp结点
            ASTNode tmpNode = parent.parent; // 记下来原本MulExp的父节点
            tmpNode.delete(); // 让原本的MulExp不挂在之前的父节点上
            newNode.addChild(parent); // 这两句：MulExp 插入 原本MulExp 与 原本MulEx父节点之间
            tmpNode.addChild(newNode);
            parent = newNode; // 下面的都放在新建的MulExp结点下方

            addNode(parent,curtoken.value,curtoken.type);
            nextToken();
            addNode(parent,"UnaryExp");
            UnaryExp(tmp);
        }
    }

    // 改写文法：AddExp → MulExp { ('+' | '−') MulExp }
    private void AddExp(ASTNode parent){
        addNode(parent,"MulExp");
        MulExp(tmp);
        while(curtoken.value.equals("+") || curtoken.value.equals("-")){

            ASTNode newNode = new ASTNode("AddExp");
            ASTNode tmpNode = parent.parent; // 记下来
            tmpNode.delete();
            newNode.addChild(parent);
            tmpNode.addChild(newNode);
            parent = newNode;

            addNode(parent,curtoken.value,curtoken.type);
            nextToken();
            addNode(parent,"MulExp");
            MulExp(tmp);
        }
    }

    // 改写文法：RelExp → AddExp { ('<' | '>' | '<=' | '>=') AddExp }
    private void RelExp(ASTNode parent){ // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        addNode(parent,"AddExp");
        AddExp(tmp);
        while(curtoken.value.equals("<") || curtoken.value.equals(">") || curtoken.value.equals("<=") || curtoken.value.equals(">=")){

            ASTNode newNode = new ASTNode("RelExp");
            ASTNode tmpNode = parent.parent; // 记下来
            tmpNode.delete();
            newNode.addChild(parent);
            tmpNode.addChild(newNode);
            parent = newNode;

            addNode(parent,curtoken.value,curtoken.type);
            nextToken();
            addNode(parent,"AddExp");
            AddExp(tmp);
        }
    }

    // 改写文法：EqExp → RelExp { ('==' | '!=') RelExp }
    private void EqExp(ASTNode parent){ // EqExp → RelExp | EqExp ('==' | '!=') RelExp
        addNode(parent,"RelExp");
        RelExp(tmp);
        while(curtoken.value.equals("==") || curtoken.value.equals("!=")){

            ASTNode newNode = new ASTNode("EqExp");
            ASTNode tmpNode = parent.parent; // 记下来
            tmpNode.delete();
            newNode.addChild(parent);
            tmpNode.addChild(newNode);
            parent = newNode;

            addNode(parent,curtoken.value,curtoken.type);
            nextToken();
            addNode(parent,"RelExp");
            RelExp(tmp);
        }
    }

    //改写文法：LAndExp → EqExp { '&&' EqExp }
    private void LAndExp(ASTNode parent){ // LAndExp → EqExp | LAndExp '&&' EqExp
        addNode(parent,"EqExp");
        EqExp(tmp);
        while(curtoken.type.equals("AND")){

            ASTNode newNode = new ASTNode("LAndExp");
            ASTNode tmpNode = parent.parent; // 记下来
            tmpNode.delete();
            newNode.addChild(parent);
            tmpNode.addChild(newNode);
            parent = newNode;

            // 词法分析的错误，只有一个&
            if(curtoken.value.equals("&")){
                addNode(parent,curtoken.value,"AND",'a');
                nextToken();
            }
            else{
                addNode(parent,curtoken.value,"AND");
                nextToken();
            }
            addNode(parent,"EqExp");
            EqExp(tmp);
        }
    }

    // 改写文法为：LOrExp →  LAndExp { '||' LAndExp }
    private void LOrExp(ASTNode parent){ // LOrExp → LAndExp | LOrExp '||' LAndExp
        addNode(parent,"LAndExp");
        LAndExp(tmp);

        while(curtoken.type.equals("OR")){

            ASTNode newNode = new ASTNode("LOrExp");
            ASTNode tmpNode = parent.parent; // 记下来
            tmpNode.delete();
            newNode.addChild(parent);
            tmpNode.addChild(newNode);
            parent = newNode;

            if(curtoken.value.equals("|")){
                addNode(parent,curtoken.value,"OR",'a');
                nextToken();
            }
            else{
                addNode(parent,curtoken.value,"OR");
                nextToken();
            }

            addNode(parent,"LAndExp");
            LAndExp(tmp);
        }
    }

    private void ConstExp(ASTNode parent){ // ConstExp → AddExp
        addNode(parent,"AddExp");
        AddExp(tmp);
    }

    private void UnaryOp(ASTNode parent) { //  UnaryOp → '+' | '−' | '!'
        addNode(parent,curtoken.value,curtoken.type);
        nextToken();
    }

    private boolean isDecl(){
        return curtoken.value.equals("int") | curtoken.value.equals("char") | curtoken.value.equals("const");
    }
    private boolean isIdent(){
        return curtoken.type.equals("IDENFR");
    }
    private boolean isFuncRParams(){
        return is_Exp_();
    }
    // ConstExp Exp AddExp MulExp UnaryExp 的First集都一样{ (,+,-,!,IDENFR,INTCON,CHRCON }，统一用is_Exp_来判断
    private boolean is_Exp_(){
        return curtoken.value.equals("(") | curtoken.value.equals("+") | curtoken.value.equals("-") | curtoken.value.equals("!") | curtoken.type.equals("IDENFR") | curtoken.type.equals("INTCON") | curtoken.type.equals("CHRCON");
    }
    private boolean isFuncFParams(){ // FuncFParams → FuncFParam { ',' FuncFParam }
        return isFuncFParam();
    }
    private boolean isFuncFParam(){ // FuncFParam → BType Ident ['[' ']']
        return isBType();
    }
    private boolean isBType(){
        return curtoken.value.equals("int") | curtoken.value.equals("char");
    }
    private boolean isUnaryOp(){ // UnaryOp → '+' | '−' | '!
        return curtoken.value.equals("+") | curtoken.value.equals("-") | curtoken.value.equals("!");
    }
    private boolean isLVal(){
        return curtoken.type.equals("IDENFR");
    }
    private boolean isNumber(){
        return curtoken.type.equals("INTCON");
    }
    private boolean isCharacter(){
        return curtoken.type.equals("CHRCON");
    }



    // 指向下一个token
    private void nextToken(){
        curPos++;
        if(curPos < len) curtoken = tokens.get(curPos);
    }

    // 得到token，支持预读off个单位。当前token：getsym(0) 预读一个:getsym(1)
    private Token getsym(int offset){
        // 赋给全局变量curToken
        return tokens.get(curPos + offset);
        // if(offset == 0) curPos++;
    }

    // 得到token的type，支持预读 例如INTTK
    private String getType(int offset){
        return getsym(offset).type;
    }
    // 得到token的value，例如 int
    private String getWord(int offset){
        return getsym(offset).value;
    }

    // 将当前确定的结点加入其对应父节点
    private void addNode(ASTNode parent,String VnName){ // 非终结符结点
        tmp = new ASTNode(VnName); // tmp为全局变量
        parent.addChild(tmp);
    }
    private void addNode(ASTNode parent,String VtWord,String VtType){ // 终结符结点
        tmp = new ASTNode(VtWord,VtType);
        parent.addChild(tmp);
    }
    private void addNode(ASTNode parent,String VtWord,String VtType,char errorType){ // 错误结点
        tmp = new ASTNode(VtWord,VtType,errorType,tokens.get(curPos-1).line);
        parent.addChild(tmp);
    }

}
