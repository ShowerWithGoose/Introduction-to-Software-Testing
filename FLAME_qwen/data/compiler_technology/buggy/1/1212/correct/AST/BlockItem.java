package AST;

import IO.*;

import java.io.IOException;

public class BlockItem extends ASTNode{

    ASTNodes type = ASTNodes.BlockItem;
    private StmtNode stmtNode;

    private DeclNode declNode;

    int t;

    public BlockItem(StmtNode stmtNode) {
        this.stmtNode = stmtNode;
        this.t = 1;
    }

    public BlockItem(DeclNode declNode) {
        this.declNode = declNode;
        this.t = 2;
    }

    public ASTNodes getType() {
        return type;
    }

    public DeclNode getDeclNode() {
        return declNode;
    }

    public StmtNode getStmtNode() {
        return stmtNode;
    }

    public int getT() {
        return t;
    }
    
    public void postOrderTraversal(IO io) throws IOException {
        if (t == 1) {
            stmtNode.postOrderTraversal(io);
        } else if (t == 2) {
            declNode.postOrderTraversal(io);
        }
    }

    
    public void postOrderNoPrint() {
        if (t == 1) {
            stmtNode.postOrderNoPrint();
        } else if (t == 2) {
            declNode.postOrderNoPrint();
        }

    }
}
