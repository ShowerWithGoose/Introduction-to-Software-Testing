package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;

public class FuncType implements SyntaxNode {
    private final String name = "<FuncType>";
    private Token type;

    public FuncType(Token type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return type.toString() + name + "\n";
    }
}
