package frontend.GrammaticalElements;

import frontend.Token;

public class UnaryOp {
    private final String name = "<UnaryOp>";
    private Token op;

    public UnaryOp(Token op) {
        this.op = op;
    }

    @Override
    public String toString() {
        return op.toString() + this.name + '\n';
    }
}
