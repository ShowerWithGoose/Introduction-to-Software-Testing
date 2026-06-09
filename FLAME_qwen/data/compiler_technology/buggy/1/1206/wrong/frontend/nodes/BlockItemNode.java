package frontend.nodes;

import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:17
 */
public class BlockItemNode {
    // BlockItem → Decl | Stmt
    DeclNode declNode;
    StmtNode stmtNode;
    public BlockItemNode(DeclNode declNode,StmtNode stmtNode){
        this.declNode=declNode;
        this.stmtNode=stmtNode;
    }

    public void output() throws IOException {
        if(declNode!=null){
            declNode.output();
        }else if(stmtNode!=null){
            stmtNode.output();
        }
    }
}
