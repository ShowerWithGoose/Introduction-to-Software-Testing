package frontend.Tree;

import frontend.Lexer.LexType;

import java.util.ArrayList;

public class Stmt {
    private LVal lVal;

    private Exp exp;
    private Block block;
    private Cond cond;
    private Stmt stmt;
    private Stmt stmtElse;
    private ForStmt forStmt1;
    private Cond forCond;
    private ForStmt forStmt2;
    private Stmt forStmt3;
    private LexType lexType;
    private Exp returnExp;
    private String string;
    private ArrayList<Exp> exps;

    private StmtType type;

    public Stmt(LVal lVal, Exp exp, StmtType type) {
        this.lVal = lVal;
        this.exp = exp;
        this.type = type;
    }

    public Stmt(Exp exp, StmtType type) {
        this.exp = exp;
        this.type = type;
    }

    public Stmt(Block block, StmtType type) {
        this.block = block;
        this.type = type;
    }

    public Stmt(Cond cond, Stmt stmt, Stmt stmtElse, StmtType type) {
        this.cond = cond;
        this.stmt = stmt;
        this.stmtElse = stmtElse;
        this.type = type;
    }

    public Stmt(ForStmt forStmt1, Cond forCond, ForStmt forStmt2, Stmt forStmt3, StmtType type) {
        this.forCond = forCond;
        this.forStmt1 = forStmt1;
        this.forStmt2 = forStmt2;
        this.forStmt3 = forStmt3;
        this.type = type;
    }

    public Stmt(Exp returnExp, StmtType stmtType, StmtType type) {
        this.returnExp = returnExp;
        this.type = type;
    }

    public Stmt(StmtType type) {
        this.type = type;
    }

    public Stmt(LVal lVal, StmtType type) {
        this.lVal = lVal;
        this.type = type;
    }

    public Stmt(String string, ArrayList<Exp> exps, StmtType type) {
        this.string = string;
        this.exps = exps;
        this.type = type;
    }
}
