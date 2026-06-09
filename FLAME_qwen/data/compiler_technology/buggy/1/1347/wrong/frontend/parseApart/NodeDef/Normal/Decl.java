package frontend.parseApart.NodeDef.Normal;

public class Decl {
    private ConstDecl constDecl;
    private VarDecl varDecl;
    private int type;

    public Decl() {

    }

    public void setConstDecl(ConstDecl constDecl) {
        this.constDecl = constDecl;
        this.type = 1;
    }

    public void setVarDecl(VarDecl varDecl) {
        this.varDecl = varDecl;
        this.type = 2;
    }

    public String returnSymbolType() {
        String string = "<Decl>";
        return string;
    }
}
