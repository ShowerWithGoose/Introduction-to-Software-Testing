package frontend.Parser.SyntaxNode.PrimaryExp;

import frontend.Lexer.Token.Token;
import frontend.Lexer.Token.TokenType;
import frontend.Parser.SyntaxNode.SyntaxNode;

import java.util.HashSet;

public class PrimaryExp implements SyntaxNode {
    protected final String name = "<PrimaryExp>";
    private static HashSet<TokenType> first= new HashSet<>();

    public static HashSet<TokenType> getFirst() {
        first.add(TokenType.LPARENT);
        first.add(TokenType.IDENFR);
        first.add(TokenType.INTCON);
        first.add(TokenType.CHRCON);
        return first;
    }
}
