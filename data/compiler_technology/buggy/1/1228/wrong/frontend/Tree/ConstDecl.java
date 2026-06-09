package frontend.Tree;

import java.util.ArrayList;

public class ConstDecl {
    private BType bType;
    private ArrayList<ConstDef> constDefs;

    public ConstDecl(BType bType,ArrayList<ConstDef> constDefs){
        this.bType=bType;
        this.constDefs=constDefs;
    }
}
