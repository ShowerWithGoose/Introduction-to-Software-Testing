package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;

public class BType implements SyntaxNode{
    private Token token;

    public BType(Token token) {
        this.token = token;
    }

    @Override
    public String toString() {
        return token.toString();
    }
}
