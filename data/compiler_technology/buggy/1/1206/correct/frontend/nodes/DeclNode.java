package frontend.nodes;

import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/9/30 11:32
 */
public class DeclNode {
    // Decl → ConstDecl | VarDecl
    ConstDeclNode constDeclNode;
    VarDeclNode varDeclNode;
    public DeclNode(ConstDeclNode constDeclNode, VarDeclNode varDeclNode){
        this.constDeclNode=constDeclNode;
        this.varDeclNode=varDeclNode;
    }

    public void output() throws IOException{
        if(constDeclNode!=null){
            constDeclNode.output();
        }else {
            varDeclNode.output();
        }
    }
}
