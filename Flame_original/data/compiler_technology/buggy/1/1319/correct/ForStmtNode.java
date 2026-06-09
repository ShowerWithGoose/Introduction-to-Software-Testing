import java.io.IOException;

public class ForStmtNode extends ASTNode{
    private LValNode lValNode;
    private ExpNode expNode;

    public ForStmtNode(LValNode lValNode, ExpNode expNode){
        this.expNode = expNode;
        this.lValNode = lValNode;
    }

    public ExpNode getExpNode() {
        return expNode;
    }

    public LValNode getlValNode() {
        return lValNode;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitForStmt(this);
    }
}
