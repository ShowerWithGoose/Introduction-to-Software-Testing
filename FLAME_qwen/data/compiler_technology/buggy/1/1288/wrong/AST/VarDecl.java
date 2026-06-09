package AST;

import java.util.ArrayList;

public class VarDecl {
    private BType bType;
    private ArrayList<VarDef> varDefs = new ArrayList<>();
    public VarDecl(BType bType, ArrayList<VarDef> varDefs){
        this.bType = bType;
        this.varDefs=(varDefs);
    }
}
