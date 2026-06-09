package frontend.parser.stmt;

import frontend.lexer.TokenType;

import java.util.HashSet;

public abstract class DeclStmt extends Stmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.CONSTTK);
        FIRST.add(TokenType.INTTK);
        FIRST.add(TokenType.CHARTK);
    }

    @Override
    public abstract String toString();
}
