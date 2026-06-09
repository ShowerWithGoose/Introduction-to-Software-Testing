package syntaxTree;

import token.Token;

public class ConstDef extends Def{
    private final ConstInitVal initVal;

    public ConstDef(Token ident, ConstExp constExp, ConstInitVal initVal) {
        super(ident, constExp);
        this.initVal = initVal;
    }
}
