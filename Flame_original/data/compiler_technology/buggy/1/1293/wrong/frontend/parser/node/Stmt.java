package frontend.parser.node;

import frontend.lexer.Token;
import frontend.parser.ParserType;
import frontend.parser.TreeNode;

import java.util.ArrayList;

public class Stmt extends TreeNode {
    private ArrayList<Token> tokens = new ArrayList<>();
    private LVal lVal = null;
    private Cond cond = null;
    private Block block = null;
    private ArrayList<Stmt> stmts = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();
    private ArrayList<ForStmt> forStmts = new ArrayList<>();

    public void setTokens(Token token) {
        this.tokens.add(token);
    }

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setCond(Cond cond) {
        this.cond = cond;
    }

    public void setBlock(Block block) {
        this.block = block;
    }

    public void setStmts(Stmt stmt) {
        this.stmts.add(stmt);
    }

    public void setExps(Exp exp) {
        this.exps.add(exp);
    }

    public void setForStmts(ForStmt forStmt) {
        this.forStmts.add(forStmt);
    }

    public Stmt(ParserType parserType, Token token) {
        super(parserType, token);
    }
}
