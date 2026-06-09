package frontend;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class Praser {
    private static Praser instance = new Praser();
    public static Praser getInstance() {return instance;}

    public static TreeNode root = new TreeNode(null,Component.CompUnit);
    private List<ErrorType> errorList = new ArrayList<>();
    private boolean existError = false;
    private Token curToken;
    private List<Token> tokenList;

    private int curIndex = 0;
    public void start(List<Token> tokenList , List<ErrorType> errorList){
        this.tokenList = tokenList;
        this.errorList = errorList;
        curToken = tokenList.get(curIndex);
        CompUnit(root);
//        try {
//            if (!errorList.isEmpty()) {
//                String errorOutputPath = "error.txt"; // 正确的单词输出文件路径
//                FileWriter errorWriter = new FileWriter(errorOutputPath, true);
//                ErrorType.sortErrorTypes(errorList);
//                for(int i = 0; i< errorList.size(); i++){
//                    errorList.get(i).printError(errorWriter);
//                }
//                errorWriter.close();
//            } else {
//                String stdOutputPath = "parser.txt"; // 正确的单词输出文件路径
//                FileWriter stdWriter = new FileWriter(stdOutputPath, true);
//                root.print(stdWriter);
//                stdWriter.close();
//            }
//        }catch (IOException e){}
    }
    // 规约：每个非终结符解析结束后均指向下一个token
    private void CompUnit(TreeNode curNode){
        while(curIndex<tokenList.size()){
            if(match(curToken, "int") && match(tokenList.get(curIndex+1), "main")){
                curNode.addChild(new TreeNode(null , Component.MainFuncDef));
                MainFuncDef(curNode.getNextNode());
            }
            else if(match(tokenList.get(curIndex+2), "(")){
                curNode.addChild(new TreeNode(null , Component.FuncDef));
                FuncDef(curNode.getNextNode());
            }
            else if(match(curToken, "const") || match(curToken, "int") || match(curToken, "char")){
                curNode.addChild(new TreeNode(null , Component.Decl));
                Decl(curNode.getNextNode());
            }
        }
    }
    private void Decl(TreeNode curNode){
        if(match(curToken, "const")){
            curNode.addChild(new TreeNode(null, Component.ConstDecl));
            ConstDecl(curNode.getNextNode());
        }
        else{
            curNode.addChild(new TreeNode(null , Component.VarDecl));
            VarDecl(curNode.getNextNode());
        }
    }
    private void ConstDecl(TreeNode curNode) {
        // const
        curNode.addChild(new TreeNode(curToken, Component.Terminal));
        next();
        // BType
        curNode.addChild(new TreeNode(null, Component.BType));
        BType(curNode.getNextNode());
        // ConstDef
        curNode.addChild(new TreeNode(null, Component.ConstDef));
        ConstDef(curNode.getNextNode());
        while(match(curToken, ",")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            curNode.addChild(new TreeNode(null, Component.ConstDef));
            ConstDef(curNode.getNextNode());
        }
        errorI(curNode);
    }
    private void VarDecl(TreeNode curNode){
        // BType
        curNode.addChild(new TreeNode(null, Component.BType));
        BType(curNode.getNextNode());
        // VarDef
        curNode.addChild(new TreeNode(null, Component.VarDef));
        VarDef(curNode.getNextNode());
        while(match(curToken, ",")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            curNode.addChild(new TreeNode(null, Component.VarDef));
            VarDef(curNode.getNextNode());
        }
        errorI(curNode);
    }
    private void BType(TreeNode curNode){
        curNode.addChild(new TreeNode(curToken, Component.Terminal));
        next();
    }
    private void ConstDef(TreeNode curNode){
        // Ident
        Ident(curNode);
        if(match(curToken, "[")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            // ConstExp
            curNode.addChild(new TreeNode(null, Component.ConstExp));
            ConstExp(curNode.getNextNode());
            errorK(curNode);
            if(match(curToken, "=")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
            }
            next();
            // ConstInitVal
            curNode.addChild(new TreeNode(null, Component.ConstInitVal));
            ConstInitVal(curNode.getNextNode());
        }
        else if(match(curToken, "=")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            // ConstInitVal
            curNode.addChild(new TreeNode(null, Component.ConstInitVal));
            ConstInitVal(curNode.getNextNode());
        }
    }
    private void Ident(TreeNode curNode){
        curNode.addChild(new TreeNode(curToken, Component.Terminal));
        next();
    }

    private void ConstInitVal(TreeNode curNode){
        if(match(curToken, "{")) {
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            if(match(curToken, "}")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
                return;
            }
            // ConstExp
            curNode.addChild(new TreeNode(null, Component.ConstExp));
            ConstExp(curNode.getNextNode());
            while(match(curToken, ",")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
                // ConstExp
                curNode.addChild(new TreeNode(null, Component.ConstExp));
                ConstExp(curNode.getNextNode());
            }
            if(match(curToken, "}")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
            }
        }
        else if(curToken.getType().equals(TokenType.StringConst)){
            // StringConst
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
        }
        else{
            // ConstExp
            curNode.addChild(new TreeNode(null,Component.ConstExp));
            ConstExp(curNode.getNextNode());
        }
    }
    private void VarDef(TreeNode curNode){
        // Ident
        Ident(curNode);
        if(match(curToken, "[")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            // ConstExp
            curNode.addChild(new TreeNode(null, Component.ConstExp));
            ConstExp(curNode.getNextNode());
            errorK(curNode);
            if(match(curToken, "=")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
                // InitVal
                curNode.addChild(new TreeNode(null, Component.InitVal));
                InitVal(curNode.getNextNode());
            }

        }
        else if(match(curToken, "=")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            // InitVal
            curNode.addChild(new TreeNode(null, Component.InitVal));
            InitVal(curNode.getNextNode());
        }
    }
    private void ConstExp(TreeNode curNode){
        // AddExp
        curNode.addChild(new TreeNode(null, Component.AddExp));
        AddExp(curNode.getNextNode());
    }
    private void Exp(TreeNode curNode){
        // AddExp
        curNode.addChild(new TreeNode(null, Component.AddExp));
        AddExp(curNode.getNextNode());
    }


    private void InitVal(TreeNode curNode){
        if(match(curToken, "{")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            if(match(curToken, "}")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
                return;
            }
            // Exp
            curNode.addChild(new TreeNode(null, Component.Exp));
            Exp(curNode.getNextNode());
            while(match(curToken, ",")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
                // Exp
                curNode.addChild(new TreeNode(null, Component.Exp));
                Exp(curNode.getNextNode());
            }
            if(match(curToken, "}")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
            }
        }
        else if(curToken.getType().equals(TokenType.StringConst)){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
        }
        else{
            // Exp
            curNode.addChild(new TreeNode(null,Component.Exp));
            Exp(curNode.getNextNode());
        }
    }
    private void FuncDef(TreeNode curNode){
        // FuncType
        curNode.addChild(new TreeNode(null, Component.FuncType));
        FuncType(curNode.getNextNode());
        // Ident
        Ident(curNode);
        if(match(curToken, "(")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
        }
        if(match(curToken, ")")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
        }
        else{
            if(match(curToken, "{")) {
                errorJ(curNode);
            }
            else{
                // FuncFParams
                curNode.addChild(new TreeNode(null, Component.FuncFParams));
                FuncFParams(curNode.getNextNode());
                errorJ(curNode);
            }
        }
        // Block
        curNode.addChild(new TreeNode(null, Component.Block));
        Block(curNode.getNextNode());
    }
    private void FuncType(TreeNode curNode){
        curNode.addChild(new TreeNode(curToken, Component.Terminal));
        next();
    }
    private void FuncFParams(TreeNode curNode){
        // FuncFParam
        curNode.addChild(new TreeNode(null, Component.FuncFParam));
        FuncFParam(curNode.getNextNode());
        while(match(curToken, ",")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            // FuncFParam
            curNode.addChild(new TreeNode(null, Component.FuncFParam));
            FuncFParam(curNode.getNextNode());
        }
    }
    private void FuncFParam(TreeNode curNode){
        // BType
        curNode.addChild(new TreeNode(null, Component.BType));
        BType(curNode.getNextNode());
        // Ident
        Ident(curNode);
        if(match(curToken,"[")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            errorK(curNode);
        }
    }
    private void Block(TreeNode curNode){
        if(match(curToken, "{")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            while(!match(curToken, "}")){
                // BlockItem
                curNode.addChild(new TreeNode(null, Component.BlockItem));
                BlockItem(curNode.getNextNode());
            }
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
        }

    }
    private void BlockItem(TreeNode curNode){
        if(match(curToken, "const") || match(curToken, "int") || match(curToken, "char")) {
            // Decl
            curNode.addChild(new TreeNode(null, Component.Decl));
            Decl(curNode.getNextNode());
        }
        else{
            // Stmt
            curNode.addChild(new TreeNode(null, Component.Stmt));
            Stmt(curNode.getNextNode());
        }
    }
    private void Stmt(TreeNode curNode){
        if(match(curToken, "if")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            if(match(curToken, "(")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
                // Cond
                curNode.addChild(new TreeNode(null, Component.Cond));
                Cond(curNode.getNextNode());
                errorJ(curNode);
            }
            // Stmt
            curNode.addChild(new TreeNode(null, Component.Stmt));
            Stmt(curNode.getNextNode());
            if(match(curToken, "else")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
                // Stmt
                curNode.addChild(new TreeNode(null, Component.Stmt));
                Stmt(curNode.getNextNode());
            }
        }
        else if(match(curToken, "for")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            if(match(curToken, "(")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
                // Stmt
                if (FrontStatic.isIdent(curToken.getWord())){
                    curNode.addChild(new TreeNode(null, Component.ForStmt));
                    ForStmt(curNode.getNextNode());
                }
                if(match(curToken, ";")){
                    curNode.addChild(new TreeNode(curToken, Component.Terminal));
                    next();
                }
                if(match(curToken, ";")){
                    curNode.addChild(new TreeNode(curToken, Component.Terminal));
                    next();
                }
                else{
                    // Cond
                    curNode.addChild(new TreeNode(null, Component.Cond));
                    Cond(curNode.getNextNode());
                    if(match(curToken, ";")){
                        curNode.addChild(new TreeNode(curToken, Component.Terminal));
                        next();
                    }
                }
                // Stmt
                if (FrontStatic.isIdent(curToken.getWord())){
                    curNode.addChild(new TreeNode(null, Component.ForStmt));
                    ForStmt(curNode.getNextNode());
                }
                if(match(curToken, ")")){
                    curNode.addChild(new TreeNode(curToken, Component.Terminal));
                    next();
                }
                // Stmt
                curNode.addChild(new TreeNode(null, Component.Stmt));
                Stmt(curNode.getNextNode());
            }
        }
        else if (match(curToken, "break") || match(curToken, "continue")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            errorI(curNode);
        }
        else if(match(curToken, "return")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            if(match(curToken, ";")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
            }
            else{
                if(isExp(curToken)){
                    // Exp
                    curNode.addChild(new TreeNode(null, Component.Exp));
                    Exp(curNode.getNextNode());
                    errorI(curNode);
                }
                else{
                    errorI(curNode);
                }
            }
        }
        else if(match(curToken,"printf")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            if(match(curToken, "(")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
                if(curToken.getType().equals(TokenType.StringConst)){
                    curNode.addChild(new TreeNode(curToken, Component.Terminal));
                    next();
                }
                while(match(curToken, ",")){
                    curNode.addChild(new TreeNode(curToken, Component.Terminal));
                    next();
                    // Exp
                    curNode.addChild(new TreeNode(null, Component.Exp));
                    Exp(curNode.getNextNode());
                }
                errorJ(curNode);
                errorI(curNode);
            }
        }
        else if(match(curToken, "{")){
            // Block
            curNode.addChild(new TreeNode(null , Component.Block));
            Block(curNode.getNextNode());
        }
        else{
            if(FrontStatic.isIdent(curToken.getWord())){
                int pos = curIndex;
                int errorNum = errorList.size();
                // LVal
                curNode.addChild(new TreeNode(curToken, Component.LVal));
                LVal(curNode.getNextNode());
                // 这里进行回溯
                if(match(curToken, "=")){
                    curNode.addChild(new TreeNode(curToken, Component.Terminal));
                    next();
                    if(match(curToken, "getint") || match(curToken, "getchar")){
                        curNode.addChild(new TreeNode(curToken, Component.Terminal));
                        next();
                        if(match(curToken, "(")){
                            curNode.addChild(new TreeNode(curToken, Component.Terminal));
                            next();
                            errorJ(curNode);
                        }
                    }
                    else{
                        // Exp
                        curNode.addChild(new TreeNode(null, Component.Exp));
                        Exp(curNode.getNextNode());
                    }
                    errorI(curNode);
                }
                else{
                    curIndex = pos;
                    curNode.removeChild();
                    curToken = tokenList.get(curIndex);
                    for (int i = errorList.size() - 1; i >= errorNum; i--){
                        errorList.remove(i);
                    }
                    curNode.addChild(new TreeNode(null, Component.Exp));
                    Exp(curNode.getNextNode());
                    errorI(curNode);
                }
            }
            else{
                if(match(curToken, ";")){
                    curNode.addChild(new TreeNode(curToken, Component.Terminal));
                    next();
                }
                else{
                    curNode.addChild(new TreeNode(null, Component.Exp));
                    Exp(curNode.getNextNode());
                    errorI(curNode);
                }
            }
        }
    }
    private void Cond(TreeNode curNode){
        // LOrExp
        curNode.addChild(new TreeNode(null, Component.LOrExp));
        LOrExp(curNode.getNextNode());
    }
    private void ForStmt(TreeNode curNode){
        // LVal
        curNode.addChild(new TreeNode(curToken, Component.LVal));
        LVal(curNode.getNextNode());
        if(match(curToken, "=")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            // Exp
            curNode.addChild(new TreeNode(null, Component.Exp));
            Exp(curNode.getNextNode());
        }
    }
    private void LVal(TreeNode curNode){
        // Ident
        Ident(curNode);
        if(match(curToken, "[")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            // Exp
            curNode.addChild(new TreeNode(null, Component.Exp));
            Exp(curNode.getNextNode());
            errorK(curNode);
        }
    }
    private void PrimaryExp(TreeNode curNode){
        if(match(curToken, "(")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            // Exp
            curNode.addChild(new TreeNode(null, Component.Exp));
            Exp(curNode.getNextNode());
            errorJ(curNode);
        }
        else if(FrontStatic.isIdent(curToken.getWord())){
            // LVal
            curNode.addChild(new TreeNode(curToken, Component.LVal));
            LVal(curNode.getNextNode());
        }
        else if(FrontStatic.isDigit(curToken.getWord())){
            // Number
            curNode.addChild(new TreeNode(curToken, Component.Number));
            Number(curNode.getNextNode());
        }
        else{
            // Character
            curNode.addChild(new TreeNode(curToken, Component.Character));
            Character(curNode.getNextNode());
        }
    }
    private void Number(TreeNode curNode){
        IntConst(curNode);
    }
    private void Character(TreeNode curNode){
        CharConst(curNode);
    }

    private void UnaryExp(TreeNode curNode){
        if(match(curToken, "+") || match(curToken, "-") || match(curToken, "!")){
            // UnaryOp
            curNode.addChild(new TreeNode(curToken, Component.UnaryOp));
            UnaryOp(curNode.getNextNode());
            // UnaryExp
            curNode.addChild(new TreeNode(null, Component.UnaryExp));
            UnaryExp(curNode.getNextNode());
        }
        else if(FrontStatic.isIdent(curToken.getWord()) && match(tokenList.get(curIndex + 1), "(")){
            // Ident
            Ident(curNode);
            if(match(curToken, "(")){
                curNode.addChild(new TreeNode(curToken, Component.Terminal));
                next();
                if(match(curToken, ")")){
                    curNode.addChild(new TreeNode(curToken, Component.Terminal));
                    next();
                }
                else if(isExp(curToken)){
                    // FuncRParams
                    curNode.addChild(new TreeNode(null, Component.FuncRParams));
                    FuncRParams(curNode.getNextNode());
                    errorJ(curNode);
                }
                else{
                    errorJ(curNode);
                }
            }
        }
        else{
            // PrimaryExp
            curNode.addChild(new TreeNode(null, Component.PrimaryExp));
            PrimaryExp(curNode.getNextNode());
        }
    }
    private void UnaryOp(TreeNode curNode){
        curNode.addChild(new TreeNode(curToken, Component.Terminal));
        next();
    }
    private void FuncRParams(TreeNode curNode){
        // Exp
        curNode.addChild(new TreeNode(null, Component.Exp));
        Exp(curNode.getNextNode());
        while(match(curToken, ",")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            //Exp
            curNode.addChild(new TreeNode(null, Component.Exp));
            Exp(curNode.getNextNode());
        }
    }
    private void MulExp(TreeNode curNode) {
        curNode.addChild(new TreeNode(null, Component.UnaryExp));
        UnaryExp(curNode.getNextNode());
        TreeNode fNode = curNode.getFather();
        TreeNode node;
        while(match(curToken, "*") || match(curToken, "/") || match(curToken, "%")) {
            node = new TreeNode(null, Component.MulExp);
            fNode.removeChild();
            fNode.addChild(node);
            node.addChild(curNode);
            node.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            node.addChild(new TreeNode(null, Component.UnaryExp));
            UnaryExp(node.getNextNode());
            curNode = node;
        }
    }
    private void AddExp(TreeNode curNode){
        curNode.addChild(new TreeNode(null, Component.MulExp));
        MulExp(curNode.getNextNode());
        TreeNode fNode = curNode.getFather();
        TreeNode node;
        while(match(curToken, "+") || match(curToken, "-")){
            node = new TreeNode(null, Component.AddExp);
            fNode.removeChild();
            fNode.addChild(node);
            node.addChild(curNode);
            node.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            node.addChild(new TreeNode(null, Component.MulExp));
            MulExp(node.getNextNode());
            curNode = node;
        }
    }

    private void RelExp(TreeNode curNode){
        curNode.addChild(new TreeNode(null, Component.AddExp));
        AddExp(curNode.getNextNode());
        TreeNode fNode = curNode.getFather();
        TreeNode node;
        while(match(curToken, "<") || match(curToken, ">") || match(curToken, "<=") || match(curToken, ">=")){
            node = new TreeNode(null, Component.RelExp);
            fNode.removeChild();
            fNode.addChild(node);
            node.addChild(curNode);
            node.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            node.addChild(new TreeNode(null, Component.AddExp));
            AddExp(node.getNextNode());
            curNode = node;
        }
    }
    private void EqExp(TreeNode curNode){
        curNode.addChild(new TreeNode(null, Component.RelExp));
        RelExp(curNode.getNextNode());
        TreeNode fNode = curNode.getFather();
        TreeNode node;
        while(match(curToken, "==") || match(curToken, "!=")){
            node = new TreeNode(null, Component.EqExp);
            fNode.removeChild();
            fNode.addChild(node);
            node.addChild(curNode);
            node.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            node.addChild(new TreeNode(null, Component.RelExp));
            RelExp(node.getNextNode());
            curNode = node;
        }
    }
    private void LAndExp(TreeNode curNode){
        curNode.addChild(new TreeNode(null, Component.EqExp));
        EqExp(curNode.getNextNode());
        TreeNode fNode = curNode.getFather();
        TreeNode node;
        while (match(curToken, "&&")){
            node = new TreeNode(null, Component.LAndExp);
            fNode.removeChild();
            fNode.addChild(node);
            node.addChild(curNode);
            node.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            node.addChild(new TreeNode(null, Component.EqExp));
            EqExp(node.getNextNode());
            curNode = node;
        }
    }
    private void LOrExp(TreeNode curNode){
        curNode.addChild(new TreeNode(null, Component.LAndExp));
        LAndExp(curNode.getNextNode());
        TreeNode fNode = curNode.getFather();
        TreeNode node;
        while(match(curToken, "||")){
            node = new TreeNode(null, Component.LOrExp);
            fNode.removeChild();
            fNode.addChild(node);
            node.addChild(curNode);
            node.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            node.addChild(new TreeNode(null, Component.LAndExp));
            LAndExp(node.getNextNode());
            curNode = node;
        }
    }
    private void IntConst(TreeNode curNode){
        curNode.addChild(new TreeNode(curToken, Component.Terminal));
        next();
    }
    private void CharConst(TreeNode curNode){
        curNode.addChild(new TreeNode(curToken, Component.Terminal));
        next();
    }

    private void MainFuncDef(TreeNode curNode){
        if(match(curToken, "int")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
        }
        if(match(curToken, "main")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
        }
        if(match(curToken, "(")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
            errorJ(curNode);
            // Block
            curNode.addChild(new TreeNode(null, Component.Block));
            Block(curNode.getNextNode());
        }
    }
    public boolean next(){
        curIndex++;
        if(curIndex >= tokenList.size())
            return false;
        curToken = tokenList.get(curIndex);
        return true;
    }
    public boolean isExp(Token token){
        if(match(token, "(") || FrontStatic.isDigit(token.getWord()) || FrontStatic.isChar(token.getWord())){
            return true;
        }
        else if(FrontStatic.isIdent(token.getWord())){
            return true;
        }
        else if(match(token, "+") || match(token, "-") || match(token, "!")){
            return true;
        }
        return false;
    }
    public boolean match(Token token, String word){
        return token.getWord().equals(word);
    }

    public void errorI(TreeNode curNode){
        if(match(curToken, ";")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
        }
        else{
            existError = true;
            curNode.addChild(new TreeNode(new Token(TokenType.SpecialCharMap.get(";") , ";" ,-1, tokenList.get(curIndex - 1).getLineNum() ), Component.Terminal));
            errorList.add(new ErrorType(tokenList.get(curIndex - 1).getLineNum(), "i", curIndex));
        }
    }
    public void errorJ(TreeNode curNode){
        if(match(curToken, ")")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
        }
        else{
            existError = true;
            curNode.addChild(new TreeNode(new Token(TokenType.SpecialCharMap.get(")") , ")" ,-1, tokenList.get(curIndex - 1).getLineNum() ), Component.Terminal));
            errorList.add(new ErrorType(tokenList.get(curIndex - 1).getLineNum(), "j", curIndex));
        }
    }
    public void errorK(TreeNode curNode){
        if(match(curToken, "]")){
            curNode.addChild(new TreeNode(curToken, Component.Terminal));
            next();
        }
        else{
            existError = true;
            curNode.addChild(new TreeNode(new Token(TokenType.SpecialCharMap.get("]") , "]" ,-1, tokenList.get(curIndex - 1).getLineNum() ), Component.Terminal));
            errorList.add(new ErrorType(tokenList.get(curIndex - 1).getLineNum(), "k", curIndex));
        }
    }
}
