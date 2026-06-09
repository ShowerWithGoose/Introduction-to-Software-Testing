import java.io.IOException;
import java.util.List;

public class ConstInitValNode extends ASTNode {
    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return null;
    }
}

class NumberConst extends ConstInitValNode{
    private ConstExpNode constexp;

    public NumberConst(ConstExpNode constexp){
        this.constexp =constexp;
    }

    public ConstExpNode getConstexp() {
        return constexp;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitNumberConst(this);
    }
}

class ArrayConst extends ConstInitValNode{
    private List<ConstExpNode> constexps;

    public ArrayConst(List<ConstExpNode> constexps){
        this.constexps =constexps;
    }

    public List<ConstExpNode> getConstexps() {
        return constexps;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitArrayConst(this);
    }
}

class StringConst extends ConstInitValNode{
    private String s;

    public StringConst(String s){
        this.s =s;
    }

    public String getS() {
        return s;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitStringConst(this);
    }
}