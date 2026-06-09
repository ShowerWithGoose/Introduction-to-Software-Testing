package syntaxTree;

import token.Token;

public class LVal {
    private final Token ident;
    private final Exp exp;

    public LVal(Token ident, Exp exp) {
        this.ident = ident;
        this.exp = exp;
    }
}
