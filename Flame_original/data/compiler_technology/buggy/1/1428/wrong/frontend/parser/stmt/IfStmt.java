package frontend.parser.stmt;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class IfStmt extends Stmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.IFTK);
    }

    private Cond cond;
    private Stmt ifStmt;
    private Stmt elseStmt;

    public IfStmt(Cond cond, Stmt ifStmt, Stmt elseStmt) {
        this.elseStmt = elseStmt;
        this.cond = cond;
        this.ifStmt = ifStmt;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.IFTK + " if\n");
        string += (TokenType.LPARENT + " (\n");
        string += this.cond.toString();
        string += (TokenType.RPARENT + " )\n");
        string += this.ifStmt.toString();
        if (this.elseStmt != null) {
            string += (TokenType.ELSETK + " else\n");
            string += this.elseStmt.toString();
        }
        string += "<Stmt>\n";
        return string;
    }
}
