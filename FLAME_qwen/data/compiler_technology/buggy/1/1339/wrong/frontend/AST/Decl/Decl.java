package frontend.AST.Decl;

import frontend.AST.SyntaxNode;

// Decl → ConstDecl | VarDecl
public class Decl implements SyntaxNode {
    private ConstDecl constDecl;
    private VarDecl varDecl;

    public Decl(ConstDecl constDecl) {
        this.constDecl = constDecl;
    }

    public Decl(VarDecl varDecl) {
        this.varDecl = varDecl;
    }


    @Override
    public void print() {
        if (constDecl != null) {
            constDecl.print();
        } else {
            varDecl.print();
        }
    }

    @Override
    public String getName() {
        // 不需要打印
        return "<Decl>";
    }
}
