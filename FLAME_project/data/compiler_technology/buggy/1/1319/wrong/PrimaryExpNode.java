import java.io.IOException;

public class PrimaryExpNode extends ASTNode {
    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return null;
    }
}

class ParentExp extends PrimaryExpNode{
    private ExpNode expNode;

    public ParentExp(ExpNode expNode){
        this.expNode = expNode;
    }

    public ExpNode getExpNode() {
        return expNode;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitParentExp(this);
    }
}

class LvalExp extends PrimaryExpNode{
    private LValNode lValNode;

    public LvalExp(LValNode lValNode){
        this.lValNode = lValNode;
    }

    public LValNode getlValNode() {
        return lValNode;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitLvalExp(this);
    }
}

class NumberExp extends PrimaryExpNode {
    private int a;

    public NumberExp(int a) {
        this.a = a;

    }

    public int getA() {
        return a;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitNumberExp(this);
    }
}

class CharExp extends PrimaryExpNode{
    private String ch;

    public CharExp(String ch){
        this.ch = ch;
    }

    public String getCh() {
        return ch;
    }

    @Override
    public <T> T accept(ASTVisitor<T> visitor) throws IOException {
        return visitor.visitCharExp(this);
    }
}