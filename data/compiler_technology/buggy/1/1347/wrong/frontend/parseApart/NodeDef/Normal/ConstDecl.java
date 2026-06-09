package frontend.parseApart.NodeDef.Normal;

import frontend.LexType;
import frontend.Token;

import java.util.ArrayList;

public class ConstDecl {
    private LexType BType;
    private ArrayList<ConstDef> constDefs = new ArrayList<>();

    public ConstDecl() {}

    public void setBType(LexType lexType) {
        this.BType = lexType;
    }

    public void setConstDefs(ConstDef constDef) {
        this.constDefs.add(constDef);
    }

    public String returnSymbolType() {
        String string = "<ConstDecl>";
        return string;
    }
}
