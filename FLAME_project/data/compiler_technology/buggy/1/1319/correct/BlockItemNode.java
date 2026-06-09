import java.io.IOException;

public class BlockItemNode extends ASTNode {
    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return null;
    }
}

class DeclBlock extends BlockItemNode{
    private final DeclNode declNode;

    public DeclBlock(DeclNode declNode){
        this.declNode =declNode;
    }

    public DeclNode getDeclNode() {
        return declNode;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitDeclBlock(this);
    }
}

class StmtBlock extends BlockItemNode{
    private final StmtNode stmtNode;

    public StmtBlock(StmtNode stmtNode){
        this.stmtNode = stmtNode;
    }

    public StmtNode getStmtNode() {
        return stmtNode;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitStmtBlock(this);
    }
}