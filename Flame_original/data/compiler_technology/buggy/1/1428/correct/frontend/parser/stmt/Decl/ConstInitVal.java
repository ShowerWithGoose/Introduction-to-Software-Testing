package frontend.parser.stmt.Decl;

import frontend.lexer.TokenType;
import frontend.parser.exp.ConstExp;

import java.util.HashSet;

public abstract class ConstInitVal {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(ConstExp.FIRST);
        FIRST.add(TokenType.LBRACE);
        FIRST.add(TokenType.STRCON);
    }

    @Override
    public abstract String toString();
}
