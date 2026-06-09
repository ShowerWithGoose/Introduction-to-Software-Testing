package frontend.parser.expr.types;

import frontend.lexer.Token;
import frontend.lexer.TokenType;

public class PrimaryExp {
    private Token lParent = null, rParent = null;
    private Exp exp = null;
    public PrimaryExp(Token lParent, Exp exp, Token rParent) {
        this.lParent = lParent;
        this.exp = exp;
        this.rParent = rParent;
    }
    private LVal lVal = null;
    public PrimaryExp(LVal lVal) {
        this.lVal = lVal;
    }
    private Token value = null;
    public PrimaryExp(Token value) {
        this.value = value;
    }
    public static boolean inFirst(Token token) {
        switch (token.getType()) {
            case LPARENT, IDENFR, INTCON, CHRCON -> {
                return true;
            }
            default -> {
                return false;
            }
        }
    }
    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        if (lParent != null) {
            res.append(lParent).append(exp).append(rParent == null ? "" : rParent);
        } else if (lVal != null) {
            res.append(lVal);
        } else {
            res.append(value).append(value.getType() == TokenType.INTCON ? "<Number>\n" : "<Character>\n");
        }
        res.append("<PrimaryExp>\n");
        return res.toString();
    }
}
