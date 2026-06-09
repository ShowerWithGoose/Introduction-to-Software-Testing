package frontend.Tree;

public class Decl {
    private ConstDecl constDecl;

    private VarDecl varDecl;

    public Decl(ConstDecl constDecl){
        this.constDecl=constDecl;
    }

    public Decl(VarDecl varDecl){
        this.varDecl=varDecl;
    }
}
