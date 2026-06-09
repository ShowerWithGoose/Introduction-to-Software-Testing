package frontend;


import java.io.*;
import java.util.List;

import frontend.*;
import frontend.DataStructure.*;
import frontend.DataStructure.ASTNodes.ASTNode;
import frontend.DataStructure.ASTNodes.ENode;
import frontend.DataStructure.ASTNodes.NNode;
import frontend.DataStructure.ASTNodes.TNode;

public class Parser {
    private int curTokenIndex;
    private List<Lex> lexList = Lex.LexList;
    private Lex curLex;
    private ASTNode root;
    private String outputData;
    public static Parser getInstance(){
        Parser instance = new Parser();
        return instance;
    }

    public void analyze(){
        curTokenIndex = -1;
        outputData = "";
        getToken();
        CompUnit();
    }

    private void CompUnit(){
        root = new NNode("CompUnit");
        //curNode = root;
        while((isConst() || isFuncType()) && !end()){
            if(isConst()){
                Decl(root);
            } else if (isFuncType()){
                if(lexList.get(curTokenIndex + 1).lexType.equals(Lexer.LexType.IDENFR)){
                    if(lexList.get(curTokenIndex + 2).token.equals("(")){
                        FuncDef(root);
                    } else if (!curLex.lexType.equals(Lexer.LexType.VOIDTK)){
                        Decl(root);
                    }
                }
            }
            if(curLex.lexType.equals(Lexer.LexType.INTTK) && lexList.get(curTokenIndex + 1).lexType.equals(Lexer.LexType.MAINTK)) {
                MainFuncDef(root);
            }
        }
    }
    private void Decl(ASTNode parent){
        if(isConst()){
            ConstDecl(parent);
        } else {
            VarDecl(parent);
        }
    }
    private void ConstDecl(ASTNode parent){
        ASTNode curNode = addNode(parent, new NNode("ConstDecl"));
        addNode(curNode, new TNode(curLex, curLex.token));
        Btype(curNode);
        ConstDef(curNode);
        while(curLex.token.equals(",")){
            addNode(curNode, new TNode(curLex, curLex.token));
            ConstDef(curNode);
        }
        if(curLex.token.equals(";")) {
            addNode(curNode, new TNode(curLex, curLex.token));
        } else {
            //TODO:addENode i
            addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'i'), ";"));
        }

    }
    private void Btype(ASTNode parent){
        addNode(parent, new TNode(curLex, curLex.token));
    }
    private void ConstDef(ASTNode parent){
        ASTNode curNode = addNode(parent, new NNode("ConstDef"));
        if(curLex.lexType == Lexer.LexType.IDENFR){
            addNode(curNode, new TNode(curLex, curLex.token));
        }
        if(curLex.token.equals("[")){
            addNode(curNode, new TNode(curLex, curLex.token));
            ConstExp(curNode);
            if(curLex.token.equals("]")){
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'k'), "]"));
            }
        }
        if (curLex.token.equals("=")){
            addNode(curNode, new TNode(curLex, curLex.token));
            ConstInitVal(curNode);
        }
    }
    private void ConstInitVal(ASTNode parent){
        ASTNode curNode = addNode(parent, new NNode("ConstInitVal"));
        if(curLex.token.equals("{")){
            addNode(curNode, new TNode(curLex, curLex.token));
            if(curLex.token.equals("}")){
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                ConstExp(curNode);
                while (curLex.token.equals(",")){
                    addNode(curNode, new TNode(curLex, curLex.token));
                    ConstExp(curNode);
                }
                if(curLex.token.equals("}")){
                    addNode(curNode, new TNode(curLex, curLex.token));
                }
            }
        } else if (curLex.lexType.equals(Lexer.LexType.STRCON)){
            addNode(curNode, new TNode(curLex, curLex.token));
        } else {
            ConstExp(curNode);
        }
    }
    private void VarDecl(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("VarDecl"));
        Btype(curNode);
        VarDef(curNode);
        while(curLex.token.equals(",")){
            addNode(curNode, new TNode(curLex, curLex.token));
            VarDef(curNode);
        }
        if(curLex.token.equals(";")) {
            addNode(curNode, new TNode(curLex, curLex.token));
        } else {
            addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'i'), ";"));
        }
    }
    private void VarDef(ASTNode parent) {
            ASTNode curNode = addNode(parent, new NNode("VarDef"));
            addNode(curNode, new TNode(curLex, curLex.token));
            if(curLex.token.equals("[")){
                addNode(curNode, new TNode(curLex, curLex.token));
                ConstExp(curNode);
                if(curLex.token.equals("]")){
                    addNode(curNode, new TNode(curLex, curLex.token));
                } else {
                    addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'k'), "]"));
                }
            }
            if(curLex.token.equals("=")){
                addNode(curNode, new TNode(curLex, curLex.token));
                InitVal(curNode);
            }
        }
    private void InitVal(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("InitVal"));
        if(curLex.token.equals("{")){
            addNode(curNode, new TNode(curLex, curLex.token));
            if(curLex.token.equals("}")){
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                Exp(curNode);
                while (curLex.token.equals(",")){
                    addNode(curNode, new TNode(curLex, curLex.token));
                    Exp(curNode);
                }
                addNode(curNode, new TNode(curLex, curLex.token));
            }
        } else if (curLex.lexType.equals(Lexer.LexType.STRCON)){
            addNode(curNode, new TNode(curLex, curLex.token));
        } else {
            Exp(curNode);
        }
    }
    private void FuncDef(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("FuncDef"));
        FuncType(curNode);
        addNode(curNode, new TNode(curLex, curLex.token));
        addNode(curNode, new TNode(curLex, curLex.token));
        if(curLex.token.equals(")")){
            addNode(curNode, new TNode(curLex, curLex.token));
        } else {
            FuncFParams(curNode);
            if(curLex.token.equals(")")){
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'j'), ")"));
            }
        }
        Block(curNode);
    }
    private void MainFuncDef(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("MainFuncDef"));
        addNode(curNode, new TNode(curLex, curLex.token));
        addNode(curNode, new TNode(curLex, curLex.token));
        addNode(curNode, new TNode(curLex, curLex.token));
        if(curLex.token.equals(")")){
            addNode(curNode, new TNode(curLex, curLex.token));
        } else {
            addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'j'), ")"));
        }
        Block(curNode);
    }
    private void FuncType(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("FuncType"));
        addNode(curNode, new TNode(curLex, curLex.token));
    }
    private void FuncFParams(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("FuncFParams"));
        FuncFParam(curNode);
        while (curLex.token.equals(",")){
            addNode(curNode, new TNode(curLex, curLex.token));
            FuncFParam(curNode);
        }
    }
    private void FuncFParam(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("FuncFParam"));
        Btype(curNode);
        addNode(curNode, new TNode(curLex, curLex.token));
        if(curLex.token.equals("[")){
            addNode(curNode, new TNode(curLex, curLex.token));
            if(curLex.token.equals("]")){
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'k'), "]"));
            }
        }
    }
    private void Block(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("Block"));
        addNode(curNode, new TNode(curLex, curLex.token));
        while(!curLex.token.equals("}")){
            BlockItem(curNode);
        }
        addNode(curNode, new TNode(curLex, curLex.token));
    }
    private void BlockItem(ASTNode parent) {
        if(isConst() || isBType()){
            Decl(parent);
        } else {
            Stmt(parent);
        }
    }
    private void Stmt(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("Stmt"));
        if(curLex.lexType.equals(Lexer.LexType.IDENFR)){
            int tempLexIndex = curTokenIndex;
            LVal(curNode);
            if(curLex.token.equals("=")) {
                addNode(curNode, new TNode(curLex, curLex.token));
                if(curLex.lexType.equals(Lexer.LexType.GETINTTK) || curLex.lexType.equals(Lexer.LexType.GETCHARTK)) {
                    addNode(curNode, new TNode(curLex, curLex.token));
                    addNode(curNode, new TNode(curLex, curLex.token));
                    if (curLex.token.equals(")")) {
                        addNode(curNode, new TNode(curLex, curLex.token));
                    } else {
                        addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'j'), ")"));
                    }
                    if (curLex.token.equals(";")) {
                        addNode(curNode, new TNode(curLex, curLex.token));
                    } else {
                        addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'i'), ";"));
                    }
                } else {
                    Exp(curNode);
                    if (curLex.token.equals(";")) {
                        addNode(curNode, new TNode(curLex, curLex.token));
                    } else {
                        addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'i'), ";"));
                    }
                }
            } else {
                reverse(curNode, tempLexIndex);
                Exp(curNode);
                if(curLex.token.equals(";")){
                    addNode(curNode, new TNode(curLex, curLex.token));
                } else {
                    addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'i'), ";"));
                }
            }
        } else if (curLex.token.equals(";")){
            addNode(curNode, new TNode(curLex, curLex.token));
        } else if (curLex.token.equals("{")){
            Block(curNode);
        } else if (curLex.lexType.equals(Lexer.LexType.IFTK)){
            addNode(curNode, new TNode(curLex, curLex.token));
            addNode(curNode, new TNode(curLex, curLex.token));
            Cond(curNode);
            if (curLex.token.equals(")")) {
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'j'), ")"));
            }
            Stmt(curNode);
            if(curLex.lexType.equals(Lexer.LexType.ELSETK)){
                addNode(curNode, new TNode(curLex, curLex.token));
                Stmt(curNode);
            }
        } else if (curLex.lexType.equals(Lexer.LexType.FORTK)){
            addNode(curNode, new TNode(curLex, curLex.token));
            addNode(curNode, new TNode(curLex, curLex.token));
            if(!curLex.token.equals(";")){
                ForStmt(curNode);
            }
            addNode(curNode, new TNode(curLex, curLex.token));
            if(!curLex.token.equals(";")){
                Cond(curNode);
            }
            addNode(curNode, new TNode(curLex, curLex.token));
            if(!curLex.token.equals(")")){
                ForStmt(curNode);
            }
            addNode(curNode, new TNode(curLex, curLex.token));
            Stmt(curNode);
        } else if (curLex.lexType.equals(Lexer.LexType.BREAKTK) || curLex.lexType.equals(Lexer.LexType.CONTINUETK)){
            addNode(curNode, new TNode(curLex, curLex.token));
            if(curLex.token.equals(";")){
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'i'), ";"));
            }
        } else if (curLex.lexType.equals(Lexer.LexType.RETURNTK)){
            addNode(curNode, new TNode(curLex, curLex.token));
            if(!curLex.token.equals(";")){
                Exp(curNode);
                if(curLex.token.equals(";")){
                    addNode(curNode, new TNode(curLex, curLex.token));
                } else {
                    addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'i'), ";"));
                }
            } else {
                addNode(curNode, new TNode(curLex, curLex.token));
                //TODO:really?
            }
        } else if (curLex.lexType.equals(Lexer.LexType.PRINTFTK)){
            addNode(curNode, new TNode(curLex, curLex.token));
            addNode(curNode, new TNode(curLex, curLex.token));
            addNode(curNode, new TNode(curLex, curLex.token));
            while (curLex.token.equals(",")){
                addNode(curNode, new TNode(curLex, curLex.token));
                Exp(curNode);
            }
            if (curLex.token.equals(")")) {
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'j'), ")"));
            }
            if (curLex.token.equals(";")) {
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'i'), ";"));
            }
        }
    }
    private void LVal(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("LVal"));
        addNode(curNode, new TNode(curLex, curLex.token));
        if(curLex.token.equals("[")){
            addNode(curNode, new TNode(curLex, curLex.token));
            if(curLex.token.equals("]")){
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'k'), "]"));
            }
        }
    }
    private void Exp(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("Exp"));
        AddExp(curNode);
    }
    private void Cond(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("Cond"));
        LOrExp(curNode);
    }
    private void ForStmt(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("ForStmt"));
        LVal(curNode);
        addNode(curNode, new TNode(curLex, curLex.token));
        Exp(curNode);
    }
    private void PrimaryExp(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("PrimaryExp"));
        if(curLex.token.equals("(")){
            addNode(curNode, new TNode(curLex, curLex.token));
            Exp(curNode);
            if(curLex.token.equals(")")){
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'j'), ")"));
            }
        } else if (curLex.lexType.equals(Lexer.LexType.IDENFR)){
            LVal(curNode);
        } else if (curLex.lexType.equals(Lexer.LexType.INTCON)){
            Number(curNode);
        } else if (curLex.lexType.equals(Lexer.LexType.CHRCON)){
            Character(curNode);
        }

    }
    private void Number(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("Number"));
        addNode(curNode, new TNode(curLex, curLex.token));
    }
    private void Character(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("Character"));
        addNode(curNode, new TNode(curLex, curLex.token));
    }
    private void UnaryExp(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("UnaryExp"));
        if(curLex.lexType.equals(Lexer.LexType.IDENFR) && lexList.get(curTokenIndex + 1).token.equals("(")){
            addNode(curNode, new TNode(curLex, curLex.token));
            addNode(curNode, new TNode(curLex, curLex.token));
            if(curLex.token.equals(")")){
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                FuncRParams(curNode);
                if(curLex.token.equals(")")){
                    addNode(curNode, new TNode(curLex, curLex.token));
                } else {
                    addNode(curNode, new ENode(new ErrorIndex(curTokenIndex - 1, lexList.get(curTokenIndex - 1).lineNum, 'j'), ")"));
                }
            }
        } else if (isUnaryOP()){
            UnaryOp(curNode);
            UnaryExp(curNode);
        } else {
            PrimaryExp(curNode);
        }
    }
    private void UnaryOp(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("UnaryOp"));
        addNode(curNode, new TNode(curLex, curLex.token));
    }
    private void FuncRParams(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("FuncRParams"));
        Exp(curNode);
        while(curLex.token.equals(",")){
            addNode(curNode, new TNode(curLex, curLex.token));
            Exp(curNode);
        }
    }
    private void MulExp(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("MulExp"));
        UnaryExp(curNode);
        while ("*/%".contains(curLex.token)){
            curNode = insertNode(parent, curNode, new NNode("MulExp"));
            addNode(curNode, new TNode(curLex, curLex.token));
            UnaryExp(curNode);
        }
    }
    private void AddExp(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("AddExp"));
        MulExp(curNode);
        while ("+-".contains(curLex.token)){
            curNode = insertNode(parent, curNode, new NNode("AddExp"));
            addNode(curNode, new TNode(curLex, curLex.token));
            MulExp(curNode);
        }
    }
    private void RelExp(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("RelExp"));
        AddExp(curNode);
        while (curLex.token.equals("<") || curLex.token.equals(">") || curLex.token.equals("<=") || curLex.token.equals(">=")){
            curNode = insertNode(parent, curNode, new NNode("RelExp"));
            addNode(curNode, new TNode(curLex, curLex.token));
            AddExp(curNode);
        }
    }
    private void EqExp(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("EqExp"));
        RelExp(curNode);
        while (curLex.token.equals("==") || curLex.token.equals("!=")){
            curNode = insertNode(parent, curNode, new NNode("EqExp"));
            addNode(curNode, new TNode(curLex, curLex.token));
            RelExp(curNode);
        }
    }
    private void LAndExp(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("LAndExp"));
        EqExp(curNode);
        while (curLex.token.equals("&&")){
            curNode = insertNode(parent, curNode, new NNode("LAndExp"));
            //addNode(curNode, new TNode(curLex, curLex.token));
            if(curLex.correct){
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                addNode(curNode, new ENode(new ErrorIndex(curTokenIndex, curLex.lineNum, 'a'), "&&"));
                getToken();
            }
            EqExp(curNode);
        }
    }
    private void LOrExp(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("LOrExp"));
        LAndExp(curNode);
        while (curLex.token.equals("||")){
            curNode = insertNode(parent, curNode, new NNode("LOrExp"));
            //addNode(curNode, new TNode(curLex, curLex.token));
            if(curLex.correct){
                addNode(curNode, new TNode(curLex, curLex.token));
            } else {
                addNode(curNode, new ENode(new ErrorIndex(curTokenIndex, curLex.lineNum, 'a'), "||"));
                getToken();
            }
            LAndExp(curNode);
        }
    }
    private void ConstExp(ASTNode parent) {
        ASTNode curNode = addNode(parent, new NNode("ConstExp"));
        AddExp(curNode);
    }

    private void getToken(){
        if(curTokenIndex < lexList.size() - 1){
            curLex = lexList.get(++curTokenIndex);
        }
    }
    private boolean isConst(){
        return (curLex.token.equals("const"));
    }
    private boolean isBType(){
        return (curLex.token.equals("int") || curLex.token.equals("char"));
    }
    private boolean isFuncType(){
        return (curLex.token.equals("void") || curLex.token.equals("int") || curLex.token.equals("char"));
    }
    private boolean isUnaryOP(){
        return "+-!".contains(curLex.token);
    }

    private boolean end(){
        return curTokenIndex >= lexList.size() - 1;
    }

    private ASTNode addNode(ASTNode Parent,ASTNode Child){
        if(Child instanceof TNode){
            Parent.addChild(Child);
            getToken();
        } else if (Child instanceof NNode){
            Parent.addChild(Child);
            return Child;
        } else if (Child instanceof ENode){
            Parent.addChild(Child);
            ErrorIndex.errorList.add(((ENode) Child).errorInfo);
        }
        return null;
    }
    private ASTNode insertNode(ASTNode Parent, ASTNode Child, ASTNode Insert){
        delNode(Parent, Child);
        Insert.addChild(Child);
        Parent.addChild(Insert);
        return Insert;
    }
    private void delNode(ASTNode Parent, ASTNode Child){
        Parent.removeChild(Child);
    }
    private void reverse(ASTNode Node, int lexIndex){
        Node.children.remove(Node.children.size() - 1);
        curTokenIndex = lexIndex;
        curLex = lexList.get(curTokenIndex);
    }
    private void postOrder(ASTNode Node){
        if(Node.children.size() == 0){
            if(Node instanceof NNode || Node instanceof ENode){
                outputData += Node.name + '\n';
                return;
            } else if(Node instanceof TNode){
                outputData += ((TNode) Node).lexInfo.lexType + " " + ((TNode) Node).lexInfo.token + '\n';
                return;
            }
        }
        int i;
        for (i = 0; i < Node.children.size(); i++){
            postOrder(Node.children.get(i));
        }
        outputData += Node.name + '\n';
    }
    public void output() throws IOException{
        int i;
        if(ErrorIndex.isCorrect()){
            FileWriter parserOutput = new FileWriter("parser.txt");
            postOrder(root);
            parserOutput.write(outputData);
            parserOutput.flush();
        }
        else{
            FileWriter errorOutput = new FileWriter("error.txt");
            for(i = 0; i < ErrorIndex.errorList.size(); i++){
                errorOutput.write(ErrorIndex.errorList.get(i).lineNum + " " + ErrorIndex.errorList.get(i).errType + '\n');
            }
            errorOutput.flush();
        }
    }
}

