package syntaxTree;

import token.Token;

public class VarDef extends Def{
    private final InitVal initVal;

    public VarDef(Token ident, ConstExp constExp, InitVal initVal) {
        super(ident, constExp);
        this.initVal = initVal;
    }
}
