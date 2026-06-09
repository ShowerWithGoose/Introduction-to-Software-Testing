package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;

public class Number implements SyntaxNode {
    private final String name = "<Number>";
    private Token intConst;

    public Number(Token intConst) {
        this.intConst = intConst;
    }

    @Override
    public String toString() {
        return intConst.toString() + name + "\n";
    }
}
