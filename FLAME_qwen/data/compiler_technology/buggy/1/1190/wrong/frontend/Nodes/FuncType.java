package frontend.Nodes;

import frontend.Token;

public class FuncType implements Node {
    private Token token;

    public FuncType() {
        this.token = null;
    }

    public void addType(Token token) {
        this.token = token;
    }

    @Override
    public String error() {
        StringBuilder sb = new StringBuilder();
        if (token != null) {
            sb.append(token.error());
        }
        return sb.toString();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (token != null) {
            sb.append(token.toString());
        }
        sb.append("<FuncType>\n");
        return sb.toString();
    }
}
