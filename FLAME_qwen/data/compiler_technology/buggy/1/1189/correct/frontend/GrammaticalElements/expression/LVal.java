package frontend.GrammaticalElements.expression;

import frontend.Token;

public class LVal {
    private final String name = "<LVal>";
    private Token ident;
    private Token leftSquare;
    private Exp exp;
    private Token rightSquare;

    public LVal(Token ident) {
        this.ident = ident;
    }

    public LVal(Token ident, Token leftSquare, Exp exp, Token rightSquare) {
        this.ident = ident;
        this.leftSquare = leftSquare;
        this.exp = exp;
        this.rightSquare = rightSquare;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (leftSquare != null) {
            sb.append(leftSquare.toString());
            sb.append(exp.toString());
            sb.append(rightSquare.toString());
        }
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
