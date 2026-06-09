package frontend.SyntaxTree;

import java.util.ArrayList;

public class ConstDecl {
    private BType bType;
    private ArrayList<ConstDef> constDefs;

    public ConstDecl() {
        this.constDefs = new ArrayList<>();
    }

    public void setBType(BType bType) {
        this.bType = bType;
    }

    public void addConstDef(ConstDef constDef) {
        this.constDefs.add(constDef);
    }
}
