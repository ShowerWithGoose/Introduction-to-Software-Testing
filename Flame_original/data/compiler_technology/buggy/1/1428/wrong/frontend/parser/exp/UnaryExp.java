package frontend.parser.exp;

import frontend.lexer.TokenType;

import java.util.ArrayList;
import java.util.HashSet;

public abstract class UnaryExp {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.add(TokenType.IDENFR);
        FIRST.addAll(PrimaryExp.FIRST);
        FIRST.add(TokenType.PLUS);
        FIRST.add(TokenType.MINU);
        FIRST.add(TokenType.NOT);
    }

    protected ArrayList<TokenType> signs;

    public UnaryExp(ArrayList<TokenType> signs) {
        this.signs = signs;
    }


    public abstract String toString();
}
