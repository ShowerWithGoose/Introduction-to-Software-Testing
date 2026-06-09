package frontend.GrammaticalElements.declaration;

import frontend.GrammaticalElements.expression.ConstExp;
import frontend.Token;

public class ConstDef {
    /*Token ident;
    Token leftSquare;
    ConstExp* constExp{};
    Token rightSquare;
    Token assign;
    ConstInitVal* constInitVal{};*/
    private final String name = "<ConstDef>";
    private Token ident;
    private Token leftSquare;
    private ConstExp constExp;
    private Token rightSquare;
    private Token assign;
    private ConstInitVal constInitVal;

    public ConstDef(Token ident, Token assign, ConstInitVal constInitVal) {
        this.ident = ident;
        this.assign = assign;
        this.constInitVal = constInitVal;
    }

    public ConstDef(Token ident, Token leftSquare, ConstExp constExp, Token rightSquare, Token assign, ConstInitVal constInitVal) {
        this.ident = ident;
        this.leftSquare = leftSquare;
        this.constExp = constExp;
        this.rightSquare = rightSquare;
        this.assign = assign;
        this.constInitVal = constInitVal;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (leftSquare != null) {
            sb.append(leftSquare.toString());
            sb.append(constExp.toString());
            sb.append(rightSquare.toString());
        }
        sb.append(assign.toString());
        sb.append(constInitVal.toString());
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
