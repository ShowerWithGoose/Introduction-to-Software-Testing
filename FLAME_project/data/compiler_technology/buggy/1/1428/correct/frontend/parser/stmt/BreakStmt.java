package frontend.parser.stmt;

import frontend.lexer.TokenType;

import java.util.HashSet;

public class BreakStmt extends Stmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.BREAKTK);
    }

    public BreakStmt() {

    }

    @Override
    public String toString() {
        String string = "";
        string += (TokenType.BREAKTK + " break\n");
        string += (TokenType.SEMICN + " ;\n");
        string += "<Stmt>\n";
        return string;
    }
}
