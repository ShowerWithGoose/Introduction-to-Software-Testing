package frontend.Nodes;

import frontend.Token;

public class Number implements Node {
    private Token intConst;

    public Number() {
        this.intConst = null;
    }

    public void addIntConst(Token intConst) {
        this.intConst = intConst;
    }

    @Override
    public String error() {
        if (intConst == null) {
            return "";
        }
        return intConst.error();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (intConst != null) {
            sb.append(intConst.toString());
        }
        sb.append("<Number>\n");
        return sb.toString();
    }
}
