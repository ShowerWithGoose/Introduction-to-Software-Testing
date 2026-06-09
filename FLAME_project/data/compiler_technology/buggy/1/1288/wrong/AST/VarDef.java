package AST;

import java.util.ArrayList;

public class VarDef {
    private Ident ident;
    private ConstExp constExp;
    private InitVal initVal;

    public VarDef(Ident ident, ConstExp constExp, InitVal initVal) {
        this.ident = ident;
        this.constExp = constExp;
        this.initVal = initVal;
    }
}
