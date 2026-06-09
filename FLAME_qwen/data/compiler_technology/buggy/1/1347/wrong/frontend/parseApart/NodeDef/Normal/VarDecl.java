package frontend.parseApart.NodeDef.Normal;

import frontend.LexType;

import java.util.ArrayList;

public class VarDecl {

    private LexType BType;
    private ArrayList<VarDef> varDefs = new ArrayList<>();

    public VarDecl() {}

    public void setBType(LexType lexType) {
        this.BType = lexType;
    }

    public void setVarDefs(VarDef varDef) {
        this.varDefs.add(varDef);
    }

    public String returnSymbolType() {
        String string = "<VarDecl>";
        return string;
    }
}
