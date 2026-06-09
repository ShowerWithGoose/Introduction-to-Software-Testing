package frontend.parser.stmt.Decl;

import frontend.lexer.TokenType;
import frontend.parser.exp.Exp;

import java.util.HashSet;

public abstract class InitVal {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(Exp.FIRST);
        FIRST.add(TokenType.LBRACE);
        FIRST.add(TokenType.STRCON);
    }

    @Override
    public abstract String toString();
}
