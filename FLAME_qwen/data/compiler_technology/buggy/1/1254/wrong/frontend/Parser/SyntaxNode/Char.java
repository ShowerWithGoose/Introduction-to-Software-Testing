package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;

public class Char implements SyntaxNode {
    private final String name = "<Character>";
    private Token charConst;

    public Char(Token charConst) {
        this.charConst = charConst;
    }

    @Override
    public String toString() {
        return charConst.toString() + name + "\n";
    }
}
