package frontend.Parser;

import frontend.Error.Error;
import frontend.Error.ErrorList;
import frontend.Lexer.Lexer;
import frontend.Lexer.Token;
import frontend.Lexer.TokenList;
import frontend.Lexer.TokenType;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/12 12:37
 */
public class Parser {
    private ArrayList<Token> tokenList = new ArrayList<>();
    private ArrayList<String> parserList = new ArrayList<>();
    private ArrayList<Error> errorList = new ArrayList<>();

    private Token curToken;
    private NonTerminalNode compUnit;
    private int index;
    private String curFuncType;

    public void print(){
        String parserFilePath = "parser.txt";
        String errorFilePath = "error.txt";

        if(this.errorList.isEmpty()){
            try (FileWriter fileWriter = new FileWriter(parserFilePath);
                 PrintWriter printWriter = new PrintWriter(fileWriter)) {
                for (String line : this.parserList) {
                    printWriter.println(line); // 将每行内容写入文件
                }
                System.out.println("内容已成功写入到 " + parserFilePath);
            } catch (IOException e) {
                System.err.println("写入文件时出错: " + e.getMessage());
            }
        }
        else{
            ErrorList.addErrorList(this.errorList);
            try (FileWriter fileWriter = new FileWriter(errorFilePath);
                 PrintWriter printWriter = new PrintWriter(fileWriter)) {
                for (Error error: ErrorList.errorList) {
                    printWriter.println(error.getLineNum() + " " + error.getType()); // 将每行内容写入文件
                }
                System.out.println("内容已成功写入到 " + errorFilePath);
            } catch (IOException e) {
                System.err.println("写入文件时出错: " + e.getMessage());
            }
        }
    }

    public void print_tree_to_file(){
        String parserFilePath = "parser.txt";
        String errorFilePath = "error.txt";

        if(this.errorList.isEmpty()){
            try (FileWriter fileWriter = new FileWriter(parserFilePath);
                 PrintWriter printWriter = new PrintWriter(fileWriter)) {
                this.compUnit.print_tree_to_file(printWriter);
                System.out.println("内容已成功写入到 " + parserFilePath);
            } catch (IOException e) {
                System.err.println("写入文件时出错: " + e.getMessage());
            }
        }
        else{
            ErrorList.addErrorList(this.errorList);
            try (FileWriter fileWriter = new FileWriter(errorFilePath);
                 PrintWriter printWriter = new PrintWriter(fileWriter)) {
                for (Error error: ErrorList.errorList) {
                    printWriter.println(error.getLineNum() + " " + error.getType()); // 将每行内容写入文件
                }
                System.out.println("内容已成功写入到 " + errorFilePath);
            } catch (IOException e) {
                System.err.println("写入文件时出错: " + e.getMessage());
            }
        }
    }

    public Parser(ArrayList<Token> tokenList){
        this.compUnit = new NonTerminalNode("CompUnit");
        this.tokenList = tokenList;
        this.index = 0;
        this.curFuncType = null;
    }

    public void doParser(){
        CompUnit();
    }

    public void print_to_Sym(){
        this.compUnit.print_tree();
    }

    private void addTokenToParseListByIndex(int index){
        Token token = readTokenByIndex(index);
        this.parserList.add(token.getType() + " " + token.getValue());
    }

    private void addTokenToParseListByToken(Token token){
        this.parserList.add(token.getType() + " " + token.getValue());
    }

    private Token getToken(){
        Token token = tokenList.get(index);
        index++;
        return token;
    }

    private Token readTokenByIndex(int index){
        return tokenList.get(index);
    }


    /// 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
    public void CompUnit(){
        this.curToken = getToken();

        while(this.curToken.getType().equals(TokenType.tokenMap.get("const"))
                || ( (this.curToken.getType().equals(TokenType.tokenMap.get("int")) || this.curToken.getType().equals(TokenType.tokenMap.get("char")))
                    && readTokenByIndex(this.index).getType().equals(TokenType.tokenMap.get("ident"))  //////////??
                    && !readTokenByIndex(this.index + 1).getType().equals(TokenType.tokenMap.get("(")) )
        ){
            this.index--;
            NonTerminalNode decl = new NonTerminalNode("Decl");
            Decl(decl);
            this.compUnit.addNode(decl);

            this.curToken = getToken();
        }

        while(( this.curToken.getType().equals(TokenType.tokenMap.get("int")) || this.curToken.getType().equals(TokenType.tokenMap.get("void")) || this.curToken.getType().equals(TokenType.tokenMap.get("char")) )
                && readTokenByIndex(this.index + 1).getType().equals(TokenType.tokenMap.get("("))
                && !readTokenByIndex(this.index).getType().equals(TokenType.tokenMap.get("main"))
        ){
            this.index--;
            NonTerminalNode funcDef = new NonTerminalNode("FuncDef");
            FuncDef(funcDef);
            this.compUnit.addNode(funcDef);

            this.curToken = getToken();
        }

        if( this.curToken.getType().equals(TokenType.tokenMap.get("int"))
                && readTokenByIndex(this.index).getType().equals(TokenType.tokenMap.get("main"))
                && readTokenByIndex(this.index + 1).getType().equals(TokenType.tokenMap.get("("))
        ){
            this.index--;
            NonTerminalNode mainFuncDef = new NonTerminalNode("MainFuncDef");
            MainFuncDef(mainFuncDef);
            this.compUnit.addNode(mainFuncDef);
        }

        this.parserList.add("<CompUnit>");
    }

    private void Decl(NonTerminalNode curNode){
        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("const"))){
            this.index--;
            NonTerminalNode constDecl = new NonTerminalNode("ConstDecl");
            ConstDecl(constDecl);
            curNode.addNode(constDecl);
        }
        else{
            this.index--;
            NonTerminalNode varDecl = new NonTerminalNode("VarDecl");
            VarDecl(varDecl);
            curNode.addNode(varDecl);
        }
    }

    // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    private void ConstDecl(NonTerminalNode curNode){
        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);

        NonTerminalNode bType = new NonTerminalNode("BType");
        BType(bType);
        curNode.addNode(bType);

//        this.curToken = getToken();
        NonTerminalNode constDef = new NonTerminalNode("ConstDef");
        ConstDef(constDef);
        curNode.addNode(constDef);

        this.curToken = getToken();
        while(curToken.getType().equals(TokenType.tokenMap.get(","))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode constDef1 = new NonTerminalNode("ConstDef");
            ConstDef(constDef1);
            curNode.addNode(constDef1);

            this.curToken = getToken();
        }

        if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);
        }else{
            this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "i"));
//            this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
            this.index--;
        }

        this.parserList.add("<ConstDecl>");

    }

    private void BType(NonTerminalNode curNode){
        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);
    }

    /// ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
    private void ConstDef(NonTerminalNode curNode){
        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);
        ////////叶节点了


        this.curToken = getToken();
        ////////////// ?
        while(this.curToken.getType().equals(TokenType.tokenMap.get("["))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode constExp = new NonTerminalNode("ConstExp");
            ConstExp(constExp);
            curNode.addNode(constExp);

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get("]"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "k"));
//                this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "k");////////////可优化 -2???
                this.index--;
            }

            this.curToken = getToken();

            break;///////////////// ?
        }

        if(this.curToken.getType().equals(TokenType.tokenMap.get("="))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);
        }

        NonTerminalNode constInitVal = new NonTerminalNode("ConstInitVal");
        ConstInitVal(constInitVal);
        curNode.addNode(constInitVal);

        this.parserList.add("<ConstDef>");
    }

    /// ConstExp → AddExp 注：使用的 Ident 必须是常量
    private void ConstExp(NonTerminalNode curNode){
        NonTerminalNode addExp = new NonTerminalNode("AddExp");
        AddExp(addExp);
        curNode.addNode(addExp);

        this.parserList.add("<ConstExp>");
    }

    ///  ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private void ConstInitVal(NonTerminalNode curNode){
        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("{"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            this.curToken = getToken();

            if(this.curToken.getType().equals(TokenType.tokenMap.get("}"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.index--;

                NonTerminalNode constExp = new NonTerminalNode("ConstExp");
                ConstExp(constExp);
                curNode.addNode(constExp);

                this.curToken = getToken();
                while(this.curToken.getType().equals(TokenType.tokenMap.get(","))){
                    curNode.addNode(this.curToken);
                    addTokenToParseListByToken(this.curToken);

                    NonTerminalNode constExp1 = new NonTerminalNode("ConstExp");
                    ConstExp(constExp1);
                    curNode.addNode(constExp1);

                    this.curToken = getToken();
                }

                if(this.curToken.getType().equals(TokenType.tokenMap.get("}"))){
                    curNode.addNode(this.curToken);
                    addTokenToParseListByToken(this.curToken);
                }else{
                    this.index--;  //////////////////??
                }
            }
        }
        else if(this.curToken.getType().equals(TokenType.tokenMap.get("string const"))){
//            NonTerminalNode stringConst = new NonTerminalNode("StringConst");
//            StringConst(stringConst);
//            curNode.addNode(stringConst);
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);
        }
        else{
            this.index--;
            NonTerminalNode constExp = new NonTerminalNode("ConstExp");
            ConstExp(constExp);
            curNode.addNode(constExp);
        }//////////////////StringConst


        this.parserList.add("<ConstInitVal>");
    }

//    private void StringConst(NonTerminalNode curNode){
//        curNode.addNode(this.curToken); /// 叶子
//        addTokenToParseListByToken(this.curToken);
//    }

    /// VarDecl → BType VarDef { ',' VarDef } ';' // i
    private void VarDecl(NonTerminalNode curNode){
        NonTerminalNode bType = new NonTerminalNode("BType");
        BType(bType);
        curNode.addNode(bType);
//        System.out.println(this.curToken.getValue());

        NonTerminalNode varDef = new NonTerminalNode("VarDef");
        VarDef(varDef);
        curNode.addNode(varDef);

        this.curToken = getToken();
//        System.out.println(this.curToken.getValue());
        while(this.curToken.getType().equals(TokenType.tokenMap.get(","))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode varDef1 = new NonTerminalNode("VarDef");
            VarDef(varDef1);
            curNode.addNode(varDef1);

            this.curToken = getToken();
        }

        if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);
        }else{
            this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "i"));
//            this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
            this.index--;
        }

        this.parserList.add("<VarDecl>");
    }

    /// VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
    private void VarDef(NonTerminalNode curNode){
        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);

        this.curToken = getToken();
        if(this.curToken.getType().equals(TokenType.tokenMap.get("["))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode constExp = new NonTerminalNode("ConstExp");
            ConstExp(constExp);
            curNode.addNode(constExp);

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get("]"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "k"));
//                this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "k");////////////可优化 -2???
                this.index--;
            }

            this.curToken = getToken();
        }

        if(this.curToken.getType().equals(TokenType.tokenMap.get("="))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode initVal = new NonTerminalNode("InitVal");
            InitVal(initVal);
            curNode.addNode(initVal);
        }else{
            this.index--;
        }

        this.parserList.add("<VarDef>");
    }

    ///  InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private void InitVal(NonTerminalNode curNode){
//        Token thisToken = readTokenByIndex(this.index);
        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("{"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get("}"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.index--;

                NonTerminalNode exp = new NonTerminalNode("Exp");
                Exp(exp);
                curNode.addNode(exp);

                this.curToken = getToken();
                while(this.curToken.getType().equals(TokenType.tokenMap.get(","))){
                    curNode.addNode(this.curToken);
                    addTokenToParseListByToken(this.curToken);

                    NonTerminalNode exp1 = new NonTerminalNode("Exp");
                    Exp(exp1);
                    curNode.addNode(exp1);

                    this.curToken = getToken();
                }

                if(this.curToken.getType().equals(TokenType.tokenMap.get("}"))){
                    curNode.addNode(this.curToken);
                    addTokenToParseListByToken(this.curToken);
                }else{
                    ///目前不会发生？？？
                    this.index--;
                }
            }
        }
        else if(this.curToken.getType().equals(TokenType.tokenMap.get("string const"))){
//            NonTerminalNode stringConst = new NonTerminalNode("StringConst");
//            StringConst(stringConst);
//            curNode.addNode(stringConst);
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);
        }
        else{
            this.index--;

            NonTerminalNode exp = new NonTerminalNode("Exp");
            Exp(exp);
            curNode.addNode(exp);
        }

        this.parserList.add("<InitVal>");
    }

    /// Exp → AddExp
    private void Exp(NonTerminalNode curNode){
        NonTerminalNode addExp = new NonTerminalNode("AddExp");
        AddExp(addExp);
        curNode.addNode(addExp);

        this.parserList.add("<Exp>");
    }


    /// FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
    private void FuncDef(NonTerminalNode curNode){
        NonTerminalNode funcType = new NonTerminalNode("FuncType");
        this.curToken = getToken();
        funcType.addNode(this.curToken);
        curNode.addNode(funcType);
        addTokenToParseListByToken(this.curToken);

        this.parserList.add("<FuncType>");

        if(this.curToken.getType().equals(TokenType.tokenMap.get("int"))){
            this.curFuncType = "int";
        }else if(this.curToken.getType().equals(TokenType.tokenMap.get("char"))){
            this.curFuncType = "char";
        }else if(this.curToken.getType().equals(TokenType.tokenMap.get("void"))){
            this.curFuncType = "void";
        }

        /////优化？？

        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);
        //// 叶节点了


        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);

        this.curToken = getToken();
        if(!this.curToken.getType().equals(TokenType.tokenMap.get(")"))
            && !this.curToken.getType().equals(TokenType.tokenMap.get("{"))) {
            this.index--;

            NonTerminalNode funcFParams = new NonTerminalNode("FuncFParams");
            FuncFParams(funcFParams);
            curNode.addNode(funcFParams);

            this.curToken = getToken();
        }

        if(this.curToken.getType().equals(TokenType.tokenMap.get(")"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);
        }else{
            this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "j"));
//            this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "j");////////////可优化 -2???
            this.index--;
        }

        NonTerminalNode block = new NonTerminalNode("Block");
        Block(block);
        curNode.addNode(block);

        this.curFuncType = null;
        this.parserList.add("<FuncDef>");
    }

    /// FuncFParams → FuncFParam { ',' FuncFParam }
    private void FuncFParams(NonTerminalNode curNode){
        NonTerminalNode funcFParam = new NonTerminalNode("FuncFParam");
        FuncFParam(funcFParam);
        curNode.addNode(funcFParam);

        this.curToken = getToken();
        while(this.curToken.getType().equals(TokenType.tokenMap.get(","))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode funcFParam1 = new NonTerminalNode("FuncFParam");
            FuncFParam(funcFParam1);
            curNode.addNode(funcFParam1);

            this.curToken = getToken();
        }

        this.index--;
        this.parserList.add("<FuncFParams>");
    }


    /// FuncFParam → BType Ident ['[' ']'] // k
    private void FuncFParam(NonTerminalNode curNode){
        NonTerminalNode bType = new NonTerminalNode("BType");
        BType(bType);
        curNode.addNode(bType);

        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);

        this.curToken = getToken();
        if(this.curToken.getType().equals(TokenType.tokenMap.get("["))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get("]"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "k"));
//                this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "k");////////////可优化 -2???
                this.index--;
            }
        }else{
            this.index--;
        }

        this.parserList.add("<FuncFParam>");
    }

    /// MainFuncDef → 'int' 'main' '(' ')' Block // j
    private void MainFuncDef(NonTerminalNode curNode){
        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);
        this.curFuncType = "int";

        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);

        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);

        this.curToken = getToken();
        if(this.curToken.getType().equals(TokenType.tokenMap.get(")"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);
        }else{
            this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "j"));
//            this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "j");////////////可优化 -2???
            this.index--;
        }

        NonTerminalNode block = new NonTerminalNode("Block");
        Block(block);
        curNode.addNode(block);

        this.parserList.add("<MainFuncDef>");
        this.curFuncType = null;
    }


    /// Block → '{' { BlockItem } '}'
    private void Block(NonTerminalNode curNode){
        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);

        this.curToken = getToken();
        while(!this.curToken.getType().equals(TokenType.tokenMap.get("}"))){
            this.index--;

            NonTerminalNode blockItem = new NonTerminalNode("BlockItem");
            BlockItem(blockItem);
            curNode.addNode(blockItem);

            this.curToken = getToken();
        }

        if(this.curToken.getType().equals(TokenType.tokenMap.get("}"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);
        }

        this.parserList.add("<Block>");
    }

    /// BlockItem → Decl | Stmt
    private void BlockItem(NonTerminalNode curNode){
        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("const"))
                || ( (this.curToken.getType().equals(TokenType.tokenMap.get("int")) || this.curToken.getType().equals(TokenType.tokenMap.get("char")))
                && readTokenByIndex(this.index).getType().equals(TokenType.tokenMap.get("ident"))  //////////??
                && !readTokenByIndex(this.index + 1).getType().equals(TokenType.tokenMap.get("(")) )
        ) {
            this.index--;
            NonTerminalNode decl = new NonTerminalNode("Decl");
            Decl(decl);
            curNode.addNode(decl);
        }
//        if(this.curToken.getType().equals(TokenType.tokenMap.get("const"))){
//            this.index--;
//            NonTerminalNode constDecl = new NonTerminalNode("ConstDecl");
//            ConstDecl(constDecl);
//            curNode.addNode(constDecl);
//        }
//        else if((this.curToken.getType().equals(TokenType.tokenMap.get("int")) || this.curToken.getType().equals(TokenType.tokenMap.get("char")))
//                && readTokenByIndex(this.index).getType().equals(TokenType.tokenMap.get("ident"))  //////////??
//                && !readTokenByIndex(this.index + 1).getType().equals(TokenType.tokenMap.get("(")) ){
//            this.index--;
//
//            NonTerminalNode varDecl = new NonTerminalNode("VarDecl");
//            VarDecl(varDecl);
//            curNode.addNode(varDecl);
//
////            System.out.println("BlockItem_Decl");
//        }
        else{
            this.index--;

            NonTerminalNode stmt = new NonTerminalNode("Stmt");
            Stmt(stmt);
            curNode.addNode(stmt);
        }
    }


    /// 条件表达式 Cond → LOrExp
    private void Cond(NonTerminalNode curNode){
        NonTerminalNode lOrExp = new NonTerminalNode("LOrExp");
        LOrExp(lOrExp);
        curNode.addNode(lOrExp);

        this.parserList.add("<Cond>");
    }


    /// 逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
    /// 即 LOrExp -> LAndExp {'||' LAndExp}
    private void LOrExp(NonTerminalNode curNode){
        NonTerminalNode lAndExp = new NonTerminalNode("LAndExp");
        LAndExp(lAndExp);
        curNode.addNode(lAndExp);


        this.parserList.add("<LOrExp>"); /////////////why这里

        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("||"))){
            NonTerminalNode lOrExp = new NonTerminalNode("LOrExp");
            curNode.removeNode();
            lOrExp.addNode(lAndExp);
            curNode.addNode(lOrExp);
        }

        while(this.curToken.getType().equals(TokenType.tokenMap.get("||"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode lAndExp1 = new NonTerminalNode("LAndExp");
            LAndExp(lAndExp1);
            curNode.addNode(lAndExp1);

            this.parserList.add("<LOrExp>"); /////////////why这里

            this.curToken = getToken();
        }

        this.index--;
    }


    /// 逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
    /// 即 LAndExp -> EqExp {'&&' EqExp}
    private void LAndExp(NonTerminalNode curNode){
        NonTerminalNode eqExp = new NonTerminalNode("EqExp");
        EqExp(eqExp);
        curNode.addNode(eqExp);

        this.parserList.add("<LAndExp>"); /////////////why这里

        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("&&"))){
            NonTerminalNode lAndExp = new NonTerminalNode("LAndExp");
            curNode.removeNode();
            lAndExp.addNode(eqExp);
            curNode.addNode(lAndExp);
        }

        while(this.curToken.getType().equals(TokenType.tokenMap.get("&&"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode eqExp1 = new NonTerminalNode("EqExp");
            EqExp(eqExp1);
            curNode.addNode(eqExp1);
            this.parserList.add("<LAndExp>"); /////////////why这里

            this.curToken = getToken();
        }

        this.index--;
    }


    /// 相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
    /// 即 EqExp -> RelExp {('=='|'!=') RelExp}
    private void EqExp(NonTerminalNode curNode){
        NonTerminalNode relExp = new NonTerminalNode("RelExp");
        RelExp(relExp);
        curNode.addNode(relExp);

        this.parserList.add("<EqExp>"); /////////////why这里

        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("=="))
                || this.curToken.getType().equals(TokenType.tokenMap.get("!="))){
            NonTerminalNode eqExp = new NonTerminalNode("EqExp");
            curNode.removeNode();
            eqExp.addNode(relExp);
            curNode.addNode(eqExp);
        }

        while(this.curToken.getType().equals(TokenType.tokenMap.get("=="))
                || this.curToken.getType().equals(TokenType.tokenMap.get("!="))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode relExp1 = new NonTerminalNode("RelExp");
            RelExp(relExp1);
            curNode.addNode(relExp1);
            this.parserList.add("<EqExp>"); /////////////why这里

            this.curToken = getToken();
        }

        this.index--;
    }

    /// 关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    /// 即 RelExp -> AddExp {('<'|'>'|'<='|'>=') AddExp}
    private void RelExp(NonTerminalNode curNode){
        NonTerminalNode addExp = new NonTerminalNode("AddExp");
        AddExp(addExp);
        curNode.addNode(addExp);

        this.parserList.add("<RelExp>"); /////////////why这里

        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("<"))
                || this.curToken.getType().equals(TokenType.tokenMap.get(">"))
                || this.curToken.getType().equals(TokenType.tokenMap.get(">="))
                || this.curToken.getType().equals(TokenType.tokenMap.get("<="))){
            NonTerminalNode relExp = new NonTerminalNode("RelExp");
            curNode.removeNode();
            relExp.addNode(addExp);
            curNode.addNode(relExp);
        }

        while(this.curToken.getType().equals(TokenType.tokenMap.get("<"))
                || this.curToken.getType().equals(TokenType.tokenMap.get(">"))
                || this.curToken.getType().equals(TokenType.tokenMap.get(">="))
                || this.curToken.getType().equals(TokenType.tokenMap.get("<="))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode addExp1 = new NonTerminalNode("AddExp");
            AddExp(addExp1);
            curNode.addNode(addExp1);
            this.parserList.add("<RelExp>"); /////////////why这里

            this.curToken = getToken();
        }

        this.index--;
    }


    /// 加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
    /// 即 AddExp -> MulExp {('+' | '-') MulExp}
    private void AddExp(NonTerminalNode curNode){
        NonTerminalNode mulExp = new NonTerminalNode("MulExp");
        MulExp(mulExp);
        curNode.addNode(mulExp);

        this.parserList.add("<AddExp>"); /////////////why这里

        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("+"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("-"))){
            NonTerminalNode addExp = new NonTerminalNode("AddExp");
            curNode.removeNode();
            addExp.addNode(mulExp);
            curNode.addNode(addExp);
        }

        while(this.curToken.getType().equals(TokenType.tokenMap.get("+"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("-"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode mulExp1 = new NonTerminalNode("MulExp");
            MulExp(mulExp1);
            curNode.addNode(mulExp1);
            this.parserList.add("<AddExp>"); /////////////why这里

            this.curToken = getToken();
        }

        this.index--;
    }

    /// 乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    /// 即 UnaryExp {('*' | '/' | '%') UnaryExp}
    private void MulExp(NonTerminalNode curNode){
        NonTerminalNode unaryExp = new NonTerminalNode("UnaryExp");
        UnaryExp(unaryExp);
        curNode.addNode(unaryExp);

        this.parserList.add("<MulExp>"); /////////////why这里

        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("*"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("/"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("%"))){
            NonTerminalNode mulExp = new NonTerminalNode("MulExp");
            curNode.removeNode();
            mulExp.addNode(unaryExp);
            curNode.addNode(mulExp);
        }

        while(this.curToken.getType().equals(TokenType.tokenMap.get("*"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("/"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("%"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode unaryExp1 = new NonTerminalNode("UnaryExp");
            UnaryExp(unaryExp1);
            curNode.addNode(unaryExp1);
            this.parserList.add("<MulExp>"); /////////////why这里

            this.curToken = getToken();
        }

        this.index--;
    }

    /// 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
    private void UnaryExp(NonTerminalNode curNode){
        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("+"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("-"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("!"))){
            NonTerminalNode unaryOp = new NonTerminalNode("UnaryOp");
            unaryOp.addNode(this.curToken);
            curNode.addNode(unaryOp);
            addTokenToParseListByToken(this.curToken);

            this.parserList.add("<UnaryOp>");

            NonTerminalNode unaryExp = new NonTerminalNode("UnaryExp");
            UnaryExp(unaryExp);
            curNode.addNode(unaryExp);

            this.parserList.add("<UnaryExp>");

            return ; //////////////6
        }

        if(this.curToken.getType().equals(TokenType.tokenMap.get("ident"))
            && readTokenByIndex(this.index).getType().equals(TokenType.tokenMap.get("("))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get("("))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);

                this.curToken = getToken();
                if(!this.curToken.getType().equals(TokenType.tokenMap.get(")"))
                    && !this.curToken.getType().equals(TokenType.tokenMap.get(";"))){ ////////////?
                    this.index--;

                    NonTerminalNode funcRParams = new NonTerminalNode("FuncRParams");
                    FuncRParams(funcRParams);
                    curNode.addNode(funcRParams);

                    this.curToken = getToken();
                }

                if(this.curToken.getType().equals(TokenType.tokenMap.get(")"))){
                    curNode.addNode(this.curToken);
                    addTokenToParseListByToken(this.curToken);
                }else{
                    this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "j"));
//                    this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "j");////////////可优化 -2???
                    this.index--;
                }
            }
            else{
                this.index--;
            }
        }else{
            this.index--;

            NonTerminalNode primaryExp = new NonTerminalNode("PrimaryExp");
            PrimaryExp(primaryExp);
            curNode.addNode(primaryExp);
        }

        this.parserList.add("<UnaryExp>");
    }


    /// 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
    private void PrimaryExp(NonTerminalNode curNode){
        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("("))) {
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode exp = new NonTerminalNode("Exp");
            Exp(exp);
            curNode.addNode(exp);

            this.curToken = getToken();

            if(this.curToken.getType().equals(TokenType.tokenMap.get(")"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "j"));
//                this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "j");////////////可优化 -2???
                this.index--;
            }
        }
        else if(this.curToken.getType().equals(TokenType.tokenMap.get("int const"))){
            NonTerminalNode number = new NonTerminalNode("Number");
            number.addNode(this.curToken); /// 叶子
            curNode.addNode(number);
            addTokenToParseListByToken(this.curToken);

            this.parserList.add("<Number>");
        }
        else if(this.curToken.getType().equals(TokenType.tokenMap.get("char const"))){
            NonTerminalNode character = new NonTerminalNode("Character");
            character.addNode(this.curToken);/// 叶子
            curNode.addNode(character);
            addTokenToParseListByToken(this.curToken);

            this.parserList.add("<Character>");
        }
//        else{
//            this.index--;
//            NonTerminalNode lVal = new NonTerminalNode("LVal");
//            LVal(lVal);
//            curNode.addNode(lVal);
//        }
        else if(this.curToken.getType().equals(TokenType.tokenMap.get("ident"))){
            this.index--;
            NonTerminalNode lVal = new NonTerminalNode("LVal");
            LVal(lVal);
            curNode.addNode(lVal);
        }

        this.parserList.add("<PrimaryExp>");
    }

    /// 函数实参表 FuncRParams → Exp { ',' Exp }
    private void FuncRParams(NonTerminalNode curNode){
        NonTerminalNode exp = new NonTerminalNode("Exp");
        Exp(exp);
        curNode.addNode(exp);

        this.curToken = getToken();
        while(this.curToken.getType().equals(TokenType.tokenMap.get(","))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode exp1 = new NonTerminalNode("Exp");
            Exp(exp1);
            curNode.addNode(exp1);

            this.curToken = getToken();
        }

        this.index--;
        this.parserList.add("<FuncRParams>");
    }


    //// 左值表达式 LVal → Ident ['[' Exp ']'] // k
    private void LVal(NonTerminalNode curNode){
        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);

        this.curToken = getToken();
        if(this.curToken.getType().equals(TokenType.tokenMap.get("["))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode exp = new NonTerminalNode("Exp");
            Exp(exp);
            curNode.addNode(exp);

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get("]"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "k"));
//                this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "k");////////////可优化 -2???
                this.index--;
            }
        }else{
            this.index--;
        }
        this.parserList.add("<LVal>");
    }


    /* 语句 Stmt → LVal '=' Exp ';' // i
            | [Exp] ';' // i
            | Block
            | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
            | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
            | 'break' ';' | 'continue' ';' // i
            | 'return' [Exp] ';' // i
            | LVal '=' 'getint''('')'';' // i j
            | LVal '=' 'getchar''('')'';' // i j
            | 'printf''('StringConst {','Exp}')'';' // i j
    */
    private void Stmt(NonTerminalNode curNode){
        this.curToken = getToken();

        if(this.curToken.getType().equals(TokenType.tokenMap.get("{"))){
            this.index--;
            NonTerminalNode block = new NonTerminalNode("Block");
            Block(block);
            curNode.addNode(block);
        }
//        else if(this.curToken.getType().equals(TokenType.tokenMap.get("Ident"))){
//            this.index--;
//
//            NonTerminalNode lVal = new NonTerminalNode("LVal");
//            LVal(lVal);
//            curNode.addNode(lVal);
//
//            this.curToken = getToken();
//            curNode.addNode(this.curToken);
//            addTokenToParseListByToken(this.curToken);
//
//            this.curToken = getToken();
//            while(!this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
//
//            }
//        }
        else if(this.curToken.getType().equals(TokenType.tokenMap.get("if"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            this.curToken = getToken();
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            NonTerminalNode cond = new NonTerminalNode("Cond");
            Cond(cond);
            curNode.addNode(cond);

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get(")"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "j"));
//                this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "j");////////////可优化 -2???
                this.index--;
            }

            NonTerminalNode stmt = new NonTerminalNode("Stmt");
            Stmt(stmt);
            curNode.addNode(stmt);

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get("else"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);

                NonTerminalNode stmt1 = new NonTerminalNode("Stmt");
                Stmt(stmt1);
                curNode.addNode(stmt1);
            }
            else{
                this.index--;
            }
        }
        /// 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        else if(this.curToken.getType().equals(TokenType.tokenMap.get("for"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            this.curToken = getToken();
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.index--;
                NonTerminalNode forStmt = new NonTerminalNode("ForStmt");
                ForStmt(forStmt);
                curNode.addNode(forStmt);

                this.curToken = getToken();
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.index--;
                NonTerminalNode cond = new NonTerminalNode("Cond");
                Cond(cond);
                curNode.addNode(cond);

                this.curToken = getToken();
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get(")"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.index--;
                NonTerminalNode forStmt = new NonTerminalNode("ForStmt");
                ForStmt(forStmt);
                curNode.addNode(forStmt);

                this.curToken = getToken();
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }

            NonTerminalNode stmt = new NonTerminalNode("Stmt");
            Stmt(stmt);
            curNode.addNode(stmt);
        }
        /// 'break' ';' | 'continue' ';' // i
        else if(this.curToken.getType().equals(TokenType.tokenMap.get("break"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "i"));
//                this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
                this.index--;
            }
        }
        else if(this.curToken.getType().equals(TokenType.tokenMap.get("continue"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "i"));
//                this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
                this.index--;
            }
        }
        /// 'return' [Exp] ';' // i
        else if(this.curToken.getType().equals(TokenType.tokenMap.get("return"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get("("))
                || this.curToken.getType().equals(TokenType.tokenMap.get("int const"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("char const"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("ident"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("+"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("-"))
                || this.curToken.getType().equals(TokenType.tokenMap.get("*"))){
                this.index--;

                NonTerminalNode exp = new NonTerminalNode("Exp");
                Exp(exp);
                curNode.addNode(exp);

                this.curToken = getToken();
            }

            if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "i"));
//                this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
                this.index--;
            }
        }
        /// 'printf''('StringConst {','Exp}')'';' // i j
        else if(this.curToken.getType().equals(TokenType.tokenMap.get("printf"))){
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            this.curToken = getToken();
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

            this.curToken = getToken();
//            NonTerminalNode stringConst = new NonTerminalNode("StringConst");
//            StringConst(stringConst);
//            curNode.addNode(stringConst);
            curNode.addNode(this.curToken);
            addTokenToParseListByToken(this.curToken);

//            this.parserList.add("<StringConst>");

            this.curToken = getToken();
            while(this.curToken.getType().equals(TokenType.tokenMap.get(","))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);

                NonTerminalNode exp = new NonTerminalNode("Exp");
                Exp(exp);
                curNode.addNode(exp);

                this.curToken = getToken();
            }
            this.index--;

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get(")"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "j"));
//                this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "j");////////////可优化 -2???
                this.index--;
            }

            this.curToken = getToken();
            if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);
            }else{
                this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "i"));
//                this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
                this.index--;
            }
        }
        else{
            boolean isLVal = false;
            int i = this.index - 1;

            while(!readTokenByIndex(i).getType().equals(TokenType.tokenMap.get(";"))){
                if(readTokenByIndex(i).getType().equals(TokenType.tokenMap.get("="))){
                    isLVal = true;
                    break;
                }
                i++;
            }

            if(isLVal){
                this.index--;
            // System.out.println(this.curToken.getValue() + " " + + this.curToken.getLineNum());

                NonTerminalNode lVal = new NonTerminalNode("LVal");
                LVal(lVal);
                curNode.addNode(lVal);

                /// | LVal '=' 'getint''('')'';' // i j
                //  | LVal '=' 'getchar''('')'';' // i j
                /// | LVal '=' Exp ';' // i
                this.curToken = getToken();
                curNode.addNode(this.curToken);
                addTokenToParseListByToken(this.curToken);

                this.curToken = getToken();
                if(this.curToken.getType().equals(TokenType.tokenMap.get("getint"))){
                    curNode.addNode(this.curToken);
                    addTokenToParseListByToken(this.curToken);

                    this.curToken = getToken();
                    curNode.addNode(this.curToken);
                    addTokenToParseListByToken(this.curToken);

                    this.curToken = getToken();
                    if(this.curToken.getType().equals(TokenType.tokenMap.get(")"))){
                        curNode.addNode(this.curToken);
                        addTokenToParseListByToken(this.curToken);
                    }else{
                        this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "j"));
//                        this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "j");////////////可优化 -2???
                        this.index--;
                    }

                    this.curToken = getToken();
                    if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
                        curNode.addNode(this.curToken);
                        addTokenToParseListByToken(this.curToken);
                    }else{
                        this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "i"));
//                        this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
                        this.index--;
                    }
                }
                else if(this.curToken.getType().equals(TokenType.tokenMap.get("getchar"))){
                    curNode.addNode(this.curToken);
                    addTokenToParseListByToken(this.curToken);

                    this.curToken = getToken();
                    curNode.addNode(this.curToken);
                    addTokenToParseListByToken(this.curToken);

                    this.curToken = getToken();
                    if(this.curToken.getType().equals(TokenType.tokenMap.get(")"))){
                        curNode.addNode(this.curToken);
                        addTokenToParseListByToken(this.curToken);
                    }else{
                        this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "j"));
//                        this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "j");////////////可优化 -2???
                        this.index--;
                    }

                    this.curToken = getToken();
                    if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
                        curNode.addNode(this.curToken);
                        addTokenToParseListByToken(this.curToken);
                    }else{
                        this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "i"));
//                        this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
                        this.index--;
                    }
                }
                else{
                    this.index--;

                    NonTerminalNode exp = new NonTerminalNode("Exp");
                    Exp(exp);
                    curNode.addNode(exp);

                    this.curToken = getToken();
                    if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
                        curNode.addNode(this.curToken);
                        addTokenToParseListByToken(this.curToken);
                    }else{
                        this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "i"));
//                        this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
                        this.index--;
                    }
                }
            } else {
                if (!this.curToken.getType().equals(TokenType.tokenMap.get(";"))) {
                    this.index--;

                    NonTerminalNode exp = new NonTerminalNode("Exp");
                    Exp(exp);
                    curNode.addNode(exp);

                    this.curToken = getToken();
                }

                if (this.curToken.getType().equals(TokenType.tokenMap.get(";"))) {
                    curNode.addNode(this.curToken);
                    addTokenToParseListByToken(this.curToken);
                } else {
                    this.errorList.add(new Error(readTokenByIndex(this.index - 2).getLineNum(), "i"));
//                    this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
                    this.index--;
                }
            }

        }

//
//        else if(this.curToken.getType().equals(TokenType.tokenMap.get("ident"))
//                && !readTokenByIndex(this.index).getType().equals(TokenType.tokenMap.get("("))
//                && !readTokenByIndex(this.index).getType().equals(TokenType.tokenMap.get(";"))){
//            this.index--;
//            // System.out.println(this.curToken.getValue() + " " + + this.curToken.getLineNum());
//
//            NonTerminalNode lVal = new NonTerminalNode("LVal");
//            LVal(lVal);
//            curNode.addNode(lVal);
//
//            /// | LVal '=' 'getint''('')'';' // i j
//            //  | LVal '=' 'getchar''('')'';' // i j
//            /// | LVal '=' Exp ';' // i
//            this.curToken = getToken();
//            curNode.addNode(this.curToken);
//            addTokenToParseListByToken(this.curToken);
//
//            this.curToken = getToken();
//            if(this.curToken.getType().equals(TokenType.tokenMap.get("getint"))){
//                curNode.addNode(this.curToken);
//                addTokenToParseListByToken(this.curToken);
//
//                this.curToken = getToken();
//                curNode.addNode(this.curToken);
//                addTokenToParseListByToken(this.curToken);
//
//                this.curToken = getToken();
//                if(this.curToken.getType().equals(TokenType.tokenMap.get(")"))){
//                    curNode.addNode(this.curToken);
//                    addTokenToParseListByToken(this.curToken);
//                }else{
//                    this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "j");////////////可优化 -2???
//                    this.index--;
//                }
//
//                this.curToken = getToken();
//                if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
//                    curNode.addNode(this.curToken);
//                    addTokenToParseListByToken(this.curToken);
//                }else{
//                    this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
//                    this.index--;
//                }
//            }
//            else if(this.curToken.getType().equals(TokenType.tokenMap.get("getchar"))){
//                curNode.addNode(this.curToken);
//                addTokenToParseListByToken(this.curToken);
//
//                this.curToken = getToken();
//                curNode.addNode(this.curToken);
//                addTokenToParseListByToken(this.curToken);
//
//                this.curToken = getToken();
//                if(this.curToken.getType().equals(TokenType.tokenMap.get(")"))){
//                    curNode.addNode(this.curToken);
//                    addTokenToParseListByToken(this.curToken);
//                }else{
//                    this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "j");////////////可优化 -2???
//                    this.index--;
//                }
//
//                this.curToken = getToken();
//                if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
//                    curNode.addNode(this.curToken);
//                    addTokenToParseListByToken(this.curToken);
//                }else{
//                    this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
//                    this.index--;
//                }
//            }
//            else{
//                this.index--;
//
//                NonTerminalNode exp = new NonTerminalNode("Exp");
//                Exp(exp);
//                curNode.addNode(exp);
//
//                this.curToken = getToken();
//                if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
//                    curNode.addNode(this.curToken);
//                    addTokenToParseListByToken(this.curToken);
//                }else{
//                    this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
//                    this.index--;
//                }
//            }
//        }
//        else{
//            if(!this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
//                this.index--;
//
//                NonTerminalNode exp = new NonTerminalNode("Exp");
//                Exp(exp);
//                curNode.addNode(exp);
//
//                this.curToken = getToken();
//            }
//
//            if(this.curToken.getType().equals(TokenType.tokenMap.get(";"))){
//                curNode.addNode(this.curToken);
//                addTokenToParseListByToken(this.curToken);
//            }else{
//                this.errorList.add(readTokenByIndex(this.index - 2).getLineNum() + " " + "i");////////////可优化 -2???
//                this.index--;
//            }
//        }

        this.parserList.add("<Stmt>");
    }

    /// 语句 ForStmt → LVal '=' Exp
    private void ForStmt(NonTerminalNode curNode){
        NonTerminalNode lVal = new NonTerminalNode("LVal");
        LVal(lVal);
        curNode.addNode(lVal);

        this.curToken = getToken();
        curNode.addNode(this.curToken);
        addTokenToParseListByToken(this.curToken);

        NonTerminalNode exp = new NonTerminalNode("Exp");
        Exp(exp);
        curNode.addNode(exp);

        this.parserList.add("<ForStmt>");
    }
}
