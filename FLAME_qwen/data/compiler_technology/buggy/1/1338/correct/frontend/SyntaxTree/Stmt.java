package frontend.SyntaxTree;

//语句 Stmt → LVal '=' Exp ';' // 每种类型的语句都要覆盖
//        | [Exp] ';' //有无Exp两种情况
//        | Block
//        | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
//        | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // 1. 无缺省，1种情况 2.
//        ForStmt与Cond中缺省一个，3种情况 3. ForStmt与Cond中缺省两个，3种情况 4. ForStmt与Cond全部
//        缺省，1种情况
//        | 'break' ';' | 'continue' ';'
//        | 'return' [Exp] ';' // 1.有Exp 2.无Exp
//        | LVal '=' 'getint''('')'';'
//        | LVal '=' 'getchar''('')'';'
//        | 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp

import java.util.ArrayList;

public class Stmt {
    private LVal lVal;
    private ArrayList<Exp> exps;
    private Block block;
    private Cond ifCond;
    private Stmt ifStmt;
    private Stmt elseStmt;
    private ForStmt forStmt1;
    private Cond forCond;
    private ForStmt forStmt2;
    private Stmt ForStmt;
    private String stringConst;


    public Stmt() {
        exps = new ArrayList<Exp>();
    }

    public void setLVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void addExp(Exp exp) {
        this.exps.add(exp);
    }

    public void setBlock(Block block) {
        this.block = block;
    }

    public void setIfCond(Cond ifCond) {
        this.ifCond = ifCond;
    }

    public void setIfStmt(Stmt ifStmt) {
        this.ifStmt = ifStmt;
    }

    public void setElseStmt(Stmt elseStmt) {
        this.elseStmt = elseStmt;
    }

    public void setForStmt1(ForStmt forStmt1) {
        this.forStmt1 = forStmt1;
    }

    public void setForCond(Cond forCond) {
        this.forCond = forCond;
    }

    public void setForStmt2(ForStmt forStmt2) {
        this.forStmt2 = forStmt2;
    }

    public void setForStmt(Stmt ForStmt) {
        this.ForStmt = ForStmt;
    }

    public void setStringConst(String stringConst) {
        this.stringConst = stringConst;
    }
}
