package frontend.GrammaticalElements.function;

import frontend.GrammaticalElements.declaration.BType;
import frontend.Token;

public class FuncFParam {
    private final String name = "<FuncFParam>";
    private BType bType;
    private Token ident;
    private Token leftSquare;
    private Token rightSquare;

    public FuncFParam(BType bType, Token ident) {
        this.bType = bType;
        this.ident = ident;
    }

    public FuncFParam(BType bType, Token ident, Token leftSquare, Token rightSquare) {
        this.bType = bType;
        this.ident = ident;
        this.leftSquare = leftSquare;
        this.rightSquare = rightSquare;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType.toString());
        sb.append(ident.toString());
        if (leftSquare != null) {
            sb.append(leftSquare.toString());
            sb.append(rightSquare.toString());
        }
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
