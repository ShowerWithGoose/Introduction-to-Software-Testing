package AST;

import IO.*;

import java.io.IOException;

public class DeclNode extends ASTNode{

    ASTNodes type = ASTNodes.Decl;
    ConstDeclNode constDecl;
    VarDeclNode varDecl;

    int t;

    public DeclNode(ConstDeclNode constDecl) {
        this.constDecl = constDecl;
        t = 1;
    }

    public DeclNode(VarDeclNode varDecl) {
        this.varDecl = varDecl;
        t = 2;
    }

    public ASTNodes getType() {
        return type;
    }

    public ConstDeclNode getConstDecl() {
        return constDecl;
    }

    public int getT() {
        return t;
    }

    public VarDeclNode getVarDecl() {
        return varDecl;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
        if (constDecl!= null) {
            constDecl.postOrderTraversal(io);
        }
        if (varDecl!= null){
            varDecl.postOrderTraversal(io);
        }

    }

    
    public void postOrderNoPrint() {
        if (constDecl!= null) {

            constDecl.postOrderNoPrint();
        }
        if (varDecl!= null){
            varDecl.postOrderNoPrint();
        }
    }
}
