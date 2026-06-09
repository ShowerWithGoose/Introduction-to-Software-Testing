package frontend.parser.stmt;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class ForStmt extends Stmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.FORTK);
    }

    private ForAssign forAssign1;
    private ForAssign forAssign2;
    private Cond cond;
    private Stmt stmt;

    public ForStmt(ForAssign forAssign1, ForAssign forAssign2, Cond cond, Stmt stmt) {
        this.stmt = stmt;
        this.forAssign2 = forAssign2;
        this.forAssign1 = forAssign1;
        this.cond = cond;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.FORTK + " for\n");
        string += (TokenType.LPARENT + " (\n");
        if (this.forAssign1 != null) {
            string += this.forAssign1.toString();
        }
        string += (TokenType.SEMICN + " ;\n");
        if (this.cond != null) {
            string += this.cond.toString();
        }
        string += (TokenType.SEMICN + " ;\n");
        if (this.forAssign2 != null) {
            string += this.forAssign2.toString();
        }
        string += (TokenType.RPARENT + " )\n");
        string += this.stmt.toString();
        string += "<Stmt>\n";
        return string;
    }
}
