package frontend.parser.stmt;

import frontend.lexer.TokenType;
import frontend.parser.exp.Exp;

import java.util.HashSet;

public class ReturnStmt extends Stmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.RETURNTK);
    }

    private Exp exp;

    public ReturnStmt(Exp exp) {
        this.exp = exp;
    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.RETURNTK + " return\n");
        if (this.exp != null) {
            string += this.exp.toString();
        }
        string += (TokenType.SEMICN + " ;\n");
        string += "<Stmt>\n";
        return string;
    }
}
