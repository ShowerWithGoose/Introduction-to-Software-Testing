package AST;

import java.util.ArrayList;

public class ConstDef {
    private Ident ident;
    private ConstExp constExp;
    private ConstInitVal constInitVal;

    public ConstDef(Ident ident, ConstExp constExp, ConstInitVal constInitVal) {
        this.ident = ident;
        this.constExp = constExp;
        this.constInitVal = constInitVal;
    }
}
