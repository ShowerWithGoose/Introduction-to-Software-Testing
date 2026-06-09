package syntaxTree;

import token.Token;

public abstract class Def {
    private final Token ident;
    private final ConstExp constExp;

    public Def(Token ident, ConstExp constExp) {
        this.ident = ident;
        this.constExp = constExp;
    }
}
