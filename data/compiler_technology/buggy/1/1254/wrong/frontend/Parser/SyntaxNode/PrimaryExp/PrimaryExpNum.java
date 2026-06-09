package frontend.Parser.SyntaxNode.PrimaryExp;

import frontend.Parser.SyntaxNode.Number;

public class PrimaryExpNum extends PrimaryExp {
    private Number number;

    public PrimaryExpNum(Number number) {
        this.number = number;
    }

    @Override
    public String toString() {
        return number.toString() + name + "\n";
    }
}
