package frontend.node;

import frontend.Parser;
import utils.MyIO;

public class DeclNode {
    // 声明 Decl -> ConstDecl | VarDecl
    private ConstDeclNode constDecl;
    private VarDeclNode varDecl;

    public DeclNode(ConstDeclNode constDecl, VarDeclNode varDecl) {
        this.constDecl = constDecl;
        this.varDecl = varDecl;
    }

    public ConstDeclNode getConstDecl() {
        return constDecl;
    }
    public VarDeclNode getVarDecl() {
        return varDecl;
    }

    public void print() {
        if (constDecl != null) {
            constDecl.print();
        } else {
            varDecl.print();
        }
    }
}
