import java.io.IOException;

public class UnaryOpNode extends ASTNode{
    private char ch;

    public UnaryOpNode(char ch){
        this.ch = ch;
    }

    public char getCh() {
        return ch;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitUnaryOp(this);
    }
}
