package frontend.Tree;

import java.util.ArrayList;

public class VarDecl {
    private BType bType;
    private ArrayList<VarDef> varDefs;

    public VarDecl(BType bType, ArrayList<VarDef> varDefs) {
        this.bType = bType;
        this.varDefs = varDefs;
    }
}
