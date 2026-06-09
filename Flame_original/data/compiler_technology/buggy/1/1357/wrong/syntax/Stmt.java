package syntax;

import lexer.LexType;
import logger.Logger;

import javax.swing.text.StringContent;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Objects;

public class Stmt {
    public enum StmtType {
        ASSIGN,
        EXP,
        BLOCK,
        IF,
        FOR,
        BREAK,
        CONTINUE,
        RETURN,
        GETINT,
        GETCHAR,
        PRINTF
    }

    public static final LexType[] FIRST;

    static {
        HashSet<LexType> firstSet = new HashSet<>();
        firstSet.addAll(Arrays.asList(LVal.FIRST));
        firstSet.addAll(Arrays.asList(Exp.FIRST));
        firstSet.add(LexType.SEMICN);
        firstSet.addAll(Arrays.asList(Block.FIRST));
        firstSet.add(LexType.IFTK);
        firstSet.add(LexType.FORTK);
        firstSet.add(LexType.BREAKTK);
        firstSet.add(LexType.CONTINUETK);
        firstSet.add(LexType.RETURNTK);
        firstSet.addAll(Arrays.asList(LVal.FIRST));
        firstSet.addAll(Arrays.asList(LVal.FIRST));
        firstSet.add(LexType.PRINTFTK);
        FIRST = firstSet.toArray(new LexType[0]);
    }

    private final StmtType stmtType;
    private final LVal lVal;
    private final Exp exp;
    private final Block block;
    private final Cond cond;
    private final Stmt stmt1;
    private final Stmt stmt2;
    private final ForStmt forStmt1;
    private final ForStmt forStmt2;
    private final String string;
    private final Exp[] exps;

    public Stmt(LVal lVal, Exp exp) {
        this.stmtType = StmtType.ASSIGN;
        this.lVal = Objects.requireNonNull(lVal);
        this.exp = Objects.requireNonNull(exp);
        this.block = null;
        this.cond = null;
        this.stmt1 = null;
        this.stmt2 = null;
        this.forStmt1 = null;
        this.forStmt2 = null;
        this.string = null;
        this.exps = null;
        Logger.logGood("<Stmt>\n");
    }

    public Stmt(Exp exp) {
        this.stmtType = StmtType.EXP;
        this.lVal = null;
        this.exp = exp;
        this.block = null;
        this.cond = null;
        this.stmt1 = null;
        this.stmt2 = null;
        this.forStmt1 = null;
        this.forStmt2 = null;
        this.string = null;
        this.exps = null;
        Logger.logGood("<Stmt>\n");
    }

    public Stmt(Block block) {
        this.stmtType = StmtType.BLOCK;
        this.lVal = null;
        this.exp = null;
        this.block = Objects.requireNonNull(block);
        this.cond = null;
        this.stmt1 = null;
        this.stmt2 = null;
        this.forStmt1 = null;
        this.forStmt2 = null;
        this.string = null;
        this.exps = null;
        Logger.logGood("<Stmt>\n");
    }

    public Stmt(Cond cond, Stmt stmt1, Stmt stmt2) {
        this.stmtType = StmtType.IF;
        this.lVal = null;
        this.exp = null;
        this.block = null;
        this.cond = Objects.requireNonNull(cond);
        this.stmt1 = Objects.requireNonNull(stmt1);
        this.stmt2 = stmt2;
        this.forStmt1 = null;
        this.forStmt2 = null;
        this.string = null;
        this.exps = null;
        Logger.logGood("<Stmt>\n");
    }

    public Stmt(ForStmt forStmt1, Cond cond, ForStmt forStmt2, Stmt stmt) {
        this.stmtType = StmtType.FOR;
        this.lVal = null;
        this.exp = null;
        this.block = null;
        this.cond = cond;
        this.stmt1 = Objects.requireNonNull(stmt);
        this.stmt2 = null;
        this.forStmt1 = forStmt1;
        this.forStmt2 = forStmt2;
        this.string = null;
        this.exps = null;
        Logger.logGood("<Stmt>\n");
    }

    public Stmt() {
        this.stmtType = StmtType.BREAK;
        this.lVal = null;
        this.exp = null;
        this.block = null;
        this.cond = null;
        this.stmt1 = null;
        this.stmt2 = null;
        this.forStmt1 = null;
        this.forStmt2 = null;
        this.string = null;
        this.exps = null;
        Logger.logGood("<Stmt>\n");
    }

    public Stmt(int unused) {
        this.stmtType = StmtType.CONTINUE;
        this.lVal = null;
        this.exp = null;
        this.block = null;
        this.cond = null;
        this.stmt1 = null;
        this.stmt2 = null;
        this.forStmt1 = null;
        this.forStmt2 = null;
        this.string = null;
        this.exps = null;
        Logger.logGood("<Stmt>\n");
    }

    public Stmt(Exp exp, int unused) {
        this.stmtType = StmtType.RETURN;
        this.lVal = null;
        this.exp = exp;
        this.block = null;
        this.cond = null;
        this.stmt1 = null;
        this.stmt2 = null;
        this.forStmt1 = null;
        this.forStmt2 = null;
        this.string = null;
        this.exps = null;
        Logger.logGood("<Stmt>\n");
    }
    
    public Stmt(LVal lVal) {
        this.stmtType = StmtType.GETINT;
        this.lVal = Objects.requireNonNull(lVal);
        this.exp = null;
        this.block = null;
        this.cond = null;
        this.stmt1 = null;
        this.stmt2 = null;
        this.forStmt1 = null;
        this.forStmt2 = null;
        this.string = null;
        this.exps = null;
        Logger.logGood("<Stmt>\n");
    }
    
    public Stmt(LVal lVal, int unused) {
        this.stmtType = StmtType.GETCHAR;
        this.lVal = Objects.requireNonNull(lVal);
        this.exp = null;
        this.block = null;
        this.cond = null;
        this.stmt1 = null;
        this.stmt2 = null;
        this.forStmt1 = null;
        this.forStmt2 = null;
        this.string = null;
        this.exps = null;
        Logger.logGood("<Stmt>\n");
    }
    
    public Stmt(String string, Exp[] exps) {
        this.stmtType = StmtType.PRINTF;
        this.lVal = null;
        this.exp = null;
        this.block = null;
        this.cond = null;
        this.stmt1 = null;
        this.stmt2 = null;
        this.forStmt1 = null;
        this.forStmt2 = null;
        this.string = Objects.requireNonNull(string);
        this.exps = Objects.requireNonNull(exps);
        Logger.logGood("<Stmt>\n");
    }
}
