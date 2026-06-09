package frontend.Parser.Class;

import frontend.Lexer.Token;

import java.util.ArrayList;

public class Stmt {
    private LVal lVal;
    private Exp exp;
    private Block block;
    private Cond cond;
    private Stmt stmtIf;
    private Stmt stmtElse;
    private ForStmt forStmt1;
    private ForStmt forStmt2;
    private Stmt stmt;
    private Token.tokenType tokenType;
    private String stringConst;
    private ArrayList<Exp> exps;
    public Stmt(LVal lVal,Exp exp,ArrayList<String> outputList){
        this.lVal = lVal;
        this.exp = exp;
        outputList.add("<Stmt>");
    }
    public Stmt(LVal lVal,ArrayList<String> outputList){
        this.lVal = lVal;
        outputList.add("<Stmt>");
    }
    public Stmt(Block block,ArrayList<String> outputList){
        this.block = block;
        outputList.add("<Stmt>");
    }
    public Stmt(Cond cond, Stmt stmtIf, Stmt stmtElse,ArrayList<String> outputList){
        this.cond = cond;
        this.stmtIf = stmtIf;
        this.stmtElse = stmtElse;
        outputList.add("<Stmt>");
    }
    public Stmt(Cond cond, Stmt stmtIf,ArrayList<String> outputList){
        this.cond = cond;
        this.stmtIf = stmtIf;
        outputList.add("<Stmt>");
    }
    public Stmt(ForStmt forStmt1, Cond cond, ForStmt forStmt2,Stmt stmt,ArrayList<String> outputList){
        this.forStmt1 = forStmt1;
        this.cond = cond;
        this.forStmt2 = forStmt2;
        this.stmt = stmt;
        outputList.add("<Stmt>");
    }
    public Stmt(Token.tokenType tokenType,ArrayList<String> outputList){
        this.tokenType = tokenType;
        outputList.add("<Stmt>");
    }
    public Stmt(Token.tokenType tokenType,Exp exp,ArrayList<String> outputList){
        this.tokenType = tokenType;
        this.exp = exp;
        outputList.add("<Stmt>");
    }
    public Stmt(LVal lVal, Token.tokenType tokenType,ArrayList<String> outputList){
        this.lVal = lVal;
        this.tokenType = tokenType;
        outputList.add("<Stmt>");
    }

    public Stmt(String stringConst, ArrayList<Exp> exps,ArrayList<String> outputList){
        this.stringConst = stringConst;
        this.exps = exps;
        outputList.add("<Stmt>");
    }

    public Stmt(Exp exp, Token.tokenType tokenType, ArrayList<String> outputList) {
        this.exp = exp;
        this.tokenType = tokenType;
        outputList.add("<Stmt>");
    }

    public boolean getReturn() {
        return Token.tokenType.RETURNTK == tokenType;
    }
}
