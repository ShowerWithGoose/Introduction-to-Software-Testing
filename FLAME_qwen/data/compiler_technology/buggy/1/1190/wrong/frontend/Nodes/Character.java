package frontend.Nodes;

import frontend.Token;

public class Character implements Node {
    private Token charConst;

    public Character() {
        this.charConst = null;
    }

    public void addCharConst(Token charConst) {
        this.charConst = charConst;
    }

    @Override
    public String error() {
        if (charConst == null) {
            return "";
        }
        return charConst.error();
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        if (charConst != null) {
            sb.append(charConst.toString());
        }
        sb.append("<Character>\n");
        return sb.toString();
    }
}
