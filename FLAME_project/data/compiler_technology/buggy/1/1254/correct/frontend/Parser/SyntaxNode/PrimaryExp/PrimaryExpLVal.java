package frontend.Parser.SyntaxNode.PrimaryExp;

import frontend.Parser.SyntaxNode.LVal;

public class PrimaryExpLVal extends PrimaryExp {
    private LVal lVal;

    public PrimaryExpLVal(LVal lVal) {
        this.lVal = lVal;
    }

    @Override
    public String toString() {
        return lVal.toString() + name + "\n";
    }
}
