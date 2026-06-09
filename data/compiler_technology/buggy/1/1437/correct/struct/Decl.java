package struct;

/* Decl â†’ ConstDecl | VarDecl */
public class Decl {
    private ConstDecl constDecl;
    private VarDecl varDecl;

    public Decl(ConstDecl constDecl) {
        this.constDecl = constDecl;
    }

    public Decl(VarDecl varDecl) {
        this.varDecl = varDecl;
    }

    public ConstDecl getConstDecl() {
        return constDecl;
    }

    public VarDecl getVarDecl() {
        return varDecl;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (constDecl != null) {
            sb.append(constDecl.toString());
        } else {
            sb.append(varDecl.toString());
        }
        // sb.append("<Decl>\n");
        return sb.toString();
    }
}
