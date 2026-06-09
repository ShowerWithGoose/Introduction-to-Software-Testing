package frontend.parser.expr.types;

import frontend.lexer.Token;

public class LVal {
    private final Token ident;
    private Token lBrack = null, rBrack = null;
    private Exp exp = null;
    public LVal(Token ident) {
        this.ident = ident;
    }
    public LVal(Token ident, Token lBrack, Exp exp, Token rBrack) {
        this.ident = ident;
        this.lBrack = lBrack;
        this.rBrack = rBrack;
        this.exp = exp;
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append(ident);
        if (lBrack != null) {
            res.append(lBrack);
            res.append(exp);
            if (rBrack != null) res.append(rBrack);
        }
        res.append("<LVal>\n");
        return res.toString();
    }

    public Token getIdent() {
        return this.ident;
    }
}
