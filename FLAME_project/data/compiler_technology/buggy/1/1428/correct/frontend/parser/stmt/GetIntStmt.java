package frontend.parser.stmt;

import frontend.lexer.TokenType;
import frontend.parser.base.Lval;

import java.util.HashSet;

public class GetIntStmt extends Stmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(Lval.FIRST);
    }

    private Lval lval;

    public GetIntStmt(Lval lval) {
        this.lval = lval;
    }

    @Override
    public String toString() {
        String string = "";
        string += this.lval.toString();
        string += (TokenType.ASSIGN + " =\n");
        string += (TokenType.GETINTTK + " getint\n");
        string += (TokenType.LPARENT + " (\n");
        string += (TokenType.RPARENT + " )\n");
        string += (TokenType.SEMICN + " ;\n");
        string += "<Stmt>\n";
        return string;
    }
}
