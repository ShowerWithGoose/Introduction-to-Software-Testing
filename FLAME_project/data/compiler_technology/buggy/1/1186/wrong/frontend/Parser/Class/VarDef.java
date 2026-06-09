package frontend.Parser.Class;

import java.util.ArrayList;

public class VarDef {
    private String ident;
    private ConstExp constExp = null;
    private InitVal initVal;

    public VarDef(String ident, ConstExp constExp, InitVal initVal, ArrayList<String> outputList) {
        this.ident = ident;
        this.constExp = constExp;
        this.initVal = initVal;
        outputList.add("<VarDef>");
    }

    public VarDef(String ident, InitVal initVal, ArrayList<String> outputList) {
        this.ident = ident;
        this.initVal = initVal;
        outputList.add("<VarDef>");
    }

    public VarDef(String ident, ConstExp constExp, ArrayList<String> outputList) {
        this.ident = ident;
        this.constExp = constExp;
        outputList.add("<VarDef>");
    }

    public VarDef(String ident, ArrayList<String> outputList) {
        this.ident = ident;
        outputList.add("<VarDef>");
    }

    public String getName() {
        return ident;
    }

    public boolean getArrayType() {
        return constExp != null;
    }
}

