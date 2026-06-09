package frontend.parser.ast.block;

import frontend.lexer.Token;

public class StmtIf implements Statement {
    private Token ifToken;
    private Token lParent;
    private Cond cond;
    private Token rParent;
    private Stmt ifStmt;
    private Token elseToken;
    private Stmt elseStmt;
    private String error;

    public StmtIf(Token ifToken, Token lParent, Cond cond, Token rParent, Stmt ifStmt, Token elseToken, Stmt elseStmt) {
        this.ifToken = ifToken;
        this.lParent = lParent;
        this.cond = cond;
        this.rParent = rParent;
        this.ifStmt = ifStmt;
        this.elseToken = elseToken;
        this.elseStmt = elseStmt;
        this.error = "";

        if (rParent == null) {
            this.error = cond.getLineno() + " j\n";
        }
    }

    public StmtIf(Token ifToken, Token lParent, Cond cond, Token rParent, Stmt ifStmt) {
        this.ifToken = ifToken;
        this.lParent = lParent;
        this.cond = cond;
        this.rParent = rParent;
        this.ifStmt = ifStmt;
        this.elseToken = null;
        this.elseStmt = null;
        this.error = "";

        if (rParent == null) {
            this.error = cond.getLineno() + " j\n";
        }
    }

    public String getOutput() {
        StringBuilder out = new StringBuilder();
        out.append(ifToken.getOutput());
        out.append(lParent.getOutput());
        out.append(cond.getOutput());
        if (rParent != null) {
            out.append(rParent.getOutput());
        }
        out.append(ifStmt.getOutput());
        if (elseToken != null) {
            out.append(elseToken.getOutput());
            out.append(elseStmt.getOutput());
        }

        return out.toString();
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        out.append(cond.getError());
        out.append(error);
        out.append(ifStmt.getError());
        if (elseStmt != null) {
            out.append(elseStmt.getError());
        }

        return out.toString();
    }

}
