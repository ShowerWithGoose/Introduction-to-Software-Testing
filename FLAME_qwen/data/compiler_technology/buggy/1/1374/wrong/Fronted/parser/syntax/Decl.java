package Fronted.parser.syntax;

// Decl â†’ ConstDecl | VarDecl
public class Decl {
    private final String name = "<Decl>";

    private ConstDecl constDecl = null;

    private VarDecl varDecl = null;

    public Decl(ConstDecl constDecl) {
        this.constDecl = constDecl;
    }

    public Decl(VarDecl varDecl) {
        this.varDecl = varDecl;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        if (constDecl != null) {
            out.append(constDecl);
        } else {
            out.append(varDecl);
        }
        return out.toString();
    }

    public ConstDecl getConstDecl() {
        return constDecl;
    }

    public VarDecl getVarDecl() {
        return varDecl;
    }

    public void setConstDecl(ConstDecl constDecl) {
        this.constDecl = constDecl;
    }

    public void setVarDecl(VarDecl varDecl) {
        this.varDecl = varDecl;
    }
}
