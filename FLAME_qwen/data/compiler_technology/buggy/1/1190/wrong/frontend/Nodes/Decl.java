package frontend.Nodes;

public class Decl implements Node {
    private int type;
    private ConstDecl constDecl;
    private VarDecl varDecl;

    public Decl() {
        this.type = 0;
        this.constDecl = null;
        this.varDecl = null;
    }

    public void setType(int type) {
        this.type = type;
    }

    public void addConstDecl(ConstDecl constDecl) {
        this.constDecl = constDecl;
    }

    public void addVarDecl(VarDecl varDecl) {
        this.varDecl = varDecl;
    }

    @Override
    public String error() {
        return switch (type) {
            case 1 -> constDecl.error();
            case 2 -> varDecl.error();
            default -> "";
        };
    }

    @Override
    public String toString() {
        return switch (type) {
            case 1 -> constDecl.toString();
            case 2 -> varDecl.toString();
            default -> "";
        };
    }
}
