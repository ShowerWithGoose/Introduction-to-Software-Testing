package frontend.parser.stmt;

import frontend.lexer.TokenType;
import frontend.parser.base.Lval;
import frontend.parser.exp.Exp;
import frontend.parser.func.Block;

import java.util.HashSet;

public abstract class Stmt {
    public static HashSet<TokenType> FIRST = new HashSet<>();

    static {
        FIRST.addAll(Lval.FIRST);
        FIRST.addAll(Block.FIRST);
        FIRST.add(TokenType.BREAKTK);
        FIRST.add(TokenType.CONTINUETK);
        FIRST.add(TokenType.CONSTTK);
        FIRST.add(TokenType.INTTK);
        FIRST.add(TokenType.CHARTK);
        FIRST.addAll(Exp.FIRST);
        FIRST.add(TokenType.SEMICN);
        FIRST.add(TokenType.FORTK);
        FIRST.add(TokenType.IFTK);
        FIRST.add(TokenType.PRINTFTK);
        FIRST.add(TokenType.RETURNTK);
    }

    public abstract String toString();
}
