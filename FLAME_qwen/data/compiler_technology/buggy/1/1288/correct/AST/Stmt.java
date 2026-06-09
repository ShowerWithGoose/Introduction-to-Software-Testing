package AST;

import java.util.ArrayList;

public class Stmt {
    private int type;
    private Block block;
    private Cond cond;
    private Stmt thenStmt;
    private Stmt elseStmt;
    private ForStmt forStmt1;
    private ForStmt forStmt2;
    private Stmt stmt;
    private Exp exp;

    private StringConst stringConst;
    private ArrayList<Exp> exps;

    private LVal lVal;

    public Stmt(int type, Block block) {
        this.block = block;
        this.type = type;
    }

    public Stmt(int type, Cond cond, Stmt thenStmt, Stmt elseStmt) {
        this.cond = cond;
        this.thenStmt = thenStmt;
        this.elseStmt = elseStmt;
        this.type = type;
    }

    public Stmt(int type, ForStmt forStmt1, Cond cond, ForStmt forStmt2, Stmt stmt) {
        this.forStmt1 = forStmt1;
        this.cond = cond;
        this.forStmt2 = forStmt2;
        this.stmt = stmt;
        this.type = type;
    }

    public Stmt(int i) {
        this.type = i;
    }

    public Stmt(int type, Exp exp) {
        this.exp = exp;
        this.type = type;
    }

    public Stmt(int type, StringConst stringConst, ArrayList<Exp> exps) {
        this.type = type;
        this.stringConst = stringConst;
        this.exps = exps;
    }
    public Stmt(int type, LVal lVal) {
        this.type = type;
        this.lVal = lVal;
    }
    public Stmt(int type, LVal lVal, Exp exp) {
        this.type = type;
        this.lVal = lVal;
        this.exp = exp;
    }
}
