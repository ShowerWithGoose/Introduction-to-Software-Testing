package syntaxTree;

import token.Token;

public class PrimaryExp extends UnaryExp {
    private final Exp exp;
    private final LVal lVal;
    private final Token value;
    private final PrimaryExpType type;

    public PrimaryExp(Exp exp, LVal lVal, Token value, PrimaryExpType type) {
        this.exp = exp;
        this.lVal = lVal;
        this.value = value;
        this.type = type;
    }
}
