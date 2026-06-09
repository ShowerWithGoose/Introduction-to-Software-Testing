package frontend.parser.stmt;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class ContinueStmt extends Stmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.CONTINUETK);
    }

    public ContinueStmt() {

    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.CONTINUETK + " continue\n");
        string += (TokenType.SEMICN + " ;\n");
        string += "<Stmt>\n";
        return string;
    }
}
