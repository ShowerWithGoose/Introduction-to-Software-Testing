package frontend.Nodes;

import frontend.Token;

public class BType implements Node {
    private Token bType;

    public BType() {
        this.bType = null;
    }

    public void addBType(Token bType) {
        this.bType = bType;
    }

    @Override
    public String error() {
        return bType.error();
    }

    @Override
    public String toString() {
        return bType.toString();
    }
}
