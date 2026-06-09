package Node;

import frontend.Parser;

public class DeclNode {
    // Decl â†’ ConstDecl | VarDecl
    private ConstDeclNode constDeclNode;
    private VarDeclNode varDeclNode;
    public DeclNode(ConstDeclNode constDeclNode, VarDeclNode varDeclNode){
        this.constDeclNode = constDeclNode;
        this.varDeclNode = varDeclNode;
    }

    public void print(){
        if(constDeclNode != null){
            constDeclNode.print();
        }else {
            varDeclNode.print();
        }
    }
}
