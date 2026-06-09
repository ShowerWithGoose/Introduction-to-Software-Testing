import java.io.IOException;

public class NumberNode extends ASTNode {
    private final int value;

    public NumberNode(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitNumber(this);
    }
}
