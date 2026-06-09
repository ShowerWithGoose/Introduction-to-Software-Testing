package frontend.parser.stmt;

import frontend.lexer.TokenType;
import frontend.parser.base.Lval;

import java.util.HashSet;

public class GetCharStmt extends Stmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(Lval.FIRST);
    }

    private Lval lval;

    public GetCharStmt(Lval lval) {
        this.lval = lval;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.lval.toString();
        string += (TokenType.ASSIGN + " =\n");
        string += (TokenType.GETCHARTK + " getchar\n");
        string += (TokenType.LPARENT + " (\n");
        string += (TokenType.RPARENT + " )\n");
        string += (TokenType.SEMICN + " ;\n");
        string += "<Stmt>\n";
        return string;
    }
}
