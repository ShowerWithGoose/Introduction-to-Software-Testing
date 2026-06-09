package struct;

import token.Token;

/* LVal â†’ Ident ['[' Exp ']'] */
public class LVal {
    private final Token ident;
    private final Token lBrackToken;
    private final Exp exp;
    private final Token rBrackToken;

    public LVal(Token ident, Token lBrackToken, Exp exp, Token rBrackToken) {
        this.ident = ident;
        this.lBrackToken = lBrackToken;
        this.exp = exp;
        this.rBrackToken = rBrackToken;
    }

    public Token getIdent() {
        return ident;
    }

    public Token getlBrackToken() {
        return lBrackToken;
    }

    public Exp getExp() {
        return exp;
    }

    public Token getrBrackToken() {
        return rBrackToken;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (lBrackToken != null) {
            sb.append(lBrackToken.toString());
            sb.append(exp.toString());
            sb.append(rBrackToken.toString());
        }
        sb.append("<LVal>\n");
        return sb.toString();
    }
}
