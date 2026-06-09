package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;

public class UnaryOp implements SyntaxNode{
    private final String name = "<UnaryOp>";
    private Token op;

    public UnaryOp(Token op) {
        this.op = op;
    }

    @Override
    public String toString() {
        return op.toString() + name + "\n";
    }
}
