package frontend.parser.stmt.types;

import frontend.lexer.Token;
import frontend.parser.expr.types.Cond;
import frontend.parser.expr.types.Exp;
import frontend.parser.expr.types.LVal;

import java.util.ArrayList;

//Stmt → LVal '=' Exp ';' // i
//        | [Exp] ';' // i
//        | Block
//        | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
//        | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
//        | 'break' ';' | 'continue' ';' // i
//        | 'return' [Exp] ';' // i
//        | LVal '=' 'getint''('')'';' // i j
//        | LVal '=' 'getchar''('')'';' // i j
//        | 'printf''('StringConst {','Exp}')'';' // i j
public class Stmt implements BlockItem {

    public ArrayList<Exp> getExps() {
        return this.exps;
    }

    public enum StmtType {
        ASSIGN_STMT,
        EXP_STMT,
        BLOCK_STMT,
        IF_ELSE,
        FOR,
        BREAK_OR_CONTINUE,
        RETURN,
        INPUT,
        PRINTF
    }
    private final StmtType stmtType;
    private LVal lVal; private Token eql; private Exp exp;
    public Stmt(LVal lVal, Token eql, Exp exp, Token semicn) {
        this.lVal = lVal;
        this.eql = eql;
        this.exp = exp;
        this.semicn = semicn;
        this.stmtType = StmtType.ASSIGN_STMT;
    }
    private Token semicn;
    public Stmt(Exp exp, Token semicn) {
        this.exp = exp;
        this.semicn = semicn;
        this.stmtType = StmtType.EXP_STMT;
    }
    public Stmt(Token semicn) {
        this.semicn = semicn;
        this.stmtType = StmtType.EXP_STMT;
    }
    private Block block;
    public Stmt(Block block) {
        this.block = block;
        this.stmtType = StmtType.BLOCK_STMT;
    }
    private Token ifTK, elseTK, lParent, rParent; private Cond cond; private Stmt ifStmt, elseStmt;
    public Stmt(Token ifTK, Token lParent, Cond cond, Token rParent, Stmt ifStmt) {
        this.ifTK = ifTK;
        this.lParent = lParent;
        this.cond = cond;
        this.rParent = rParent;
        this.ifStmt = ifStmt;
        this.stmtType = StmtType.IF_ELSE;
    }
    public Stmt(Token ifTK, Token lParent, Cond cond, Token rParent, Stmt ifStmt, Token elseTK, Stmt elseStmt) {
        this.ifTK = ifTK;
        this.lParent = lParent;
        this.cond = cond;
        this.rParent = rParent;
        this.ifStmt = ifStmt;
        this.elseTK = elseTK;
        this.elseStmt = elseStmt;
        this.stmtType = StmtType.IF_ELSE;
    }
    private Token forTK, lSemicn, rSemicn; private ForStmt initStmt, stepStmt; private Stmt forLoopBody;
    public Stmt(Token forTK, Token lParent, ForStmt initStmt, Token lSemicn, Cond cond, Token rSemicn, ForStmt stepStmt, Token rParent, Stmt forLoopBody) {
        this.forTK = forTK;
        this.lParent = lParent;
        this.initStmt = initStmt;
        this.lSemicn = lSemicn;
        this.cond = cond;
        this.rSemicn = rSemicn;
        this.stepStmt = stepStmt;
        this.rParent = rParent;
        this.forLoopBody = forLoopBody;
        this.stmtType = StmtType.FOR;
    }
    private Token breakOrContinue, returnTK, inputTK;
    public Stmt(Token breakOrContinue, Token semicn) {
        this.breakOrContinue = breakOrContinue;
        this.semicn = semicn;
        this.stmtType = StmtType.BREAK_OR_CONTINUE;
    }
    public Stmt(Token returnTK, Exp exp, Token semicn) {
        this.returnTK = returnTK;
        this.exp = exp;
        this.semicn = semicn;
        this.stmtType = StmtType.RETURN;
    }
    public Stmt(LVal lVal, Token eql, Token inputTK, Token lParent, Token rParent, Token semicn) {
        this.lVal = lVal;
        this.eql = eql;
        this.inputTK = inputTK;
        this.lParent = lParent;
        this.rParent = rParent;
        this.semicn = semicn;
        this.stmtType = StmtType.INPUT;
    }
    private Token printTK, stringConst;
    private ArrayList<Token> seps;
    private ArrayList<Exp> exps;
    public Stmt(Token printTK, Token lParent, Token stringConst, ArrayList<Token> seps, ArrayList<Exp> exps, Token rParent, Token semicn) {
        this.printTK = printTK;
        this.lParent = lParent;
        this.rParent = rParent;
        this.stringConst = stringConst;
        this.seps = seps;
        this.exps = exps;
        this.semicn = semicn;
        this.stmtType = StmtType.PRINTF;
    }
    public Token getReturnTK() {
        return this.returnTK;
    }
    public Token getPrintTK() {
        return this.printTK;
    }
    @Override
    public String toString() {
        StringBuilder result = new StringBuilder();
        switch (this.stmtType) {
            case ASSIGN_STMT -> {
                result.append(lVal);
                result.append(eql);
                result.append(exp);
                if (semicn != null) result.append(semicn);
            }
            case EXP_STMT -> {
                if (exp != null) result.append(exp);
                if (semicn != null) result.append(semicn);
            }
            case BLOCK_STMT -> {
                result.append(block);
            }
            case IF_ELSE -> {
                result.append(ifTK);
                result.append(lParent);
                result.append(cond);
                if (rParent != null) result.append(rParent);
                result.append(ifStmt);
                if (elseTK != null) {
                    result.append(elseTK);
                    result.append(elseStmt);
                }
            }
            case FOR -> {
                result.append(forTK);
                result.append(lParent);
                if (initStmt != null) result.append(initStmt);
                result.append(lSemicn);
                if (cond != null) result.append(cond);
                result.append(rSemicn);
                if (stepStmt != null) result.append(stepStmt);
                result.append(rParent);
                result.append(forLoopBody);
            }
            case BREAK_OR_CONTINUE -> {
                result.append(breakOrContinue);
                if (semicn != null) result.append(semicn);
            }
            case RETURN -> {
                result.append(returnTK);
                if (exp != null) result.append(exp);
                if (semicn != null) result.append(semicn);
            }
            case INPUT -> {
                result.append(lVal);
                result.append(eql);
                result.append(inputTK);
                result.append(lParent);
                if (rParent != null) result.append(rParent);
                if (semicn != null) result.append(semicn);
            }
            case PRINTF -> {
                result.append(printTK);
                result.append(lParent);
                result.append(stringConst);
                for (int i = 0; i < seps.size(); i++) {
                    result.append(seps.get(i)).append(exps.get(i));
                }
                if (rParent != null) result.append(rParent);
                if (semicn != null) result.append(semicn);
            }
        }
        result.append("<Stmt>\n");
        return result.toString();
    }
    public ForStmt getInitStmt() {
        return initStmt;
    }
    public ForStmt getStepStmt() {
        return stepStmt;
    }
    public Stmt getIfStmt() {
        return ifStmt;
    }
    public Stmt getElseStmt() {
        return this.elseStmt;
    }
    public Cond getCond() {
        return cond;
    }
    public StmtType getType() {
        return this.stmtType;
    }
    public Token getBreakContinueTK() {
        return this.breakOrContinue;
    }
    public Block getStmtBlock() {
        return this.block;
    }
    public Stmt getForLoopBody() {
        return this.forLoopBody;
    }

    /**
     * 获得EXP语句或赋值语句的表达式
     * @return Exp
     */
    public Exp getExp() {
        return this.exp;
    }

    /**
     * 获得赋值语句、INPUT语句的左值
     * @return 左值
     */
    public LVal getLVal() {
        return this.lVal;
    }

    /**
     * 获取printf语句的字符串常量
     * @return 字符串常量
     */
    public Token getStringConst() {
        return this.stringConst;
    }
}
