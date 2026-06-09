package frontend.parser.stmt;

import frontend.lexer.TokenType;
import frontend.parser.exp.Exp;

import java.util.HashSet;

public class ExpStmt extends Stmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(Exp.FIRST);
        FIRST.add(TokenType.SEMICN);
    }

    private Exp exp;

    public ExpStmt(Exp exp) {
        this.exp = exp;
    }

    @Override
    public String toString() {
        String string = "";
        if (this.exp != null) {
            string += this.exp.toString();
        }
        string += (TokenType.SEMICN + " ;\n");
        string += "<Stmt>\n";
        return string;
    }
}
