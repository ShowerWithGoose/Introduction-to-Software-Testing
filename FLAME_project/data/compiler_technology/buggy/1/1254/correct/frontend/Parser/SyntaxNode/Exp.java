package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.TokenType;
import frontend.Parser.SyntaxNode.PrimaryExp.PrimaryExp;

import java.util.HashSet;

public class Exp implements SyntaxNode {
    private final String name = "<Exp>";
    private AddExp addExp;
    private static HashSet<TokenType> first= new HashSet<>();

    public static HashSet<TokenType> getFirst() {
        first.addAll(PrimaryExp.getFirst());
        first.add(TokenType.PLUS);
        first.add(TokenType.MINU);
        first.add(TokenType.NOT);
        return first;
    }

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String toString() {
        return addExp.toString() + name + "\n";
    }
}
