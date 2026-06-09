package frontend.Nodes;

import frontend.Token;

public class UnaryOp implements Node {
    private Token op;

    public UnaryOp() {
        this.op = null;
    }

    public void addOp(Token token) {
        this.op = token;
    }

    @Override
    public String error() {
        if (op == null) {
            return "";
        }
        return op.error();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (op != null) {
            sb.append(op.toString());
        }
        sb.append("<UnaryOp>\n");
        return sb.toString();
    }
}
