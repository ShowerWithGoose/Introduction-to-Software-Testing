package frontend.parseApart.NodeDef.Normal;

import frontend.Token;
import frontend.parseApart.NodeDef.Exps.ConstExp;

public class ConstDef {
    private String name;
    private int line;
    private ConstExp constExp = null;
    private ConstInitVal constInitVal;

    public ConstDef() {}

    public void setNameAndLine(Token token) {
        this.name = token.getName();
        this.line = token.getLine();
    }

    public void setConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void setConstInitVal(ConstInitVal constInitVal) {
        this.constInitVal = constInitVal;
    }

    public String returnSymbolType() {
        String string = "<ConstDef>";
        return string;
    }
}
