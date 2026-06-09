package frontend.parseApart.NodeDef.Normal;

import frontend.Token;
import frontend.parseApart.NodeDef.Exps.ConstExp;

public class VarDef {

    private String name;
    private int line;

    private ConstExp constExp = null;
    private InitVal initVal = null;

    public VarDef() {}

    public void setConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void setInitVal(InitVal initVal) {
        this.initVal = initVal;
    }

    public void setNameAndLine(Token token) {
        this.name = token.getName();
        this.line = token.getLine();
    }

    public String returnSymbolType() {
        String string = "<VarDef>";
        return string;
    }
}
