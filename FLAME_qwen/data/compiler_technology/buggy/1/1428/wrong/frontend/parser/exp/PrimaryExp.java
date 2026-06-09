package frontend.parser.exp;

import frontend.lexer.TokenType;
import frontend.parser.base.Lval;

import java.util.HashSet;

public abstract class PrimaryExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.CHRCON);
        FIRST.add(TokenType.LPARENT);
        FIRST.addAll(Lval.FIRST);
        FIRST.add(TokenType.INTCON);
    }

    public PrimaryExp() {

    }

    public abstract String toString();
}
