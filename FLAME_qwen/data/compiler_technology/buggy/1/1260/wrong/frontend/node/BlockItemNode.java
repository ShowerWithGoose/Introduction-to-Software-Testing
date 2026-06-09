package frontend.node;

public class BlockItemNode {
    private DeclNode declNode;
    private StmtNode stmtNode;
    public BlockItemNode(DeclNode declNode, StmtNode stmtNode){
        this.declNode = declNode;
        this.stmtNode = stmtNode;
    }
    public void print(){
        if (declNode != null) {
            declNode.print();
        } else {
            stmtNode.print();
        }
    }

}
