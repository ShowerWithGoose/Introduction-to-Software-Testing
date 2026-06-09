package node;

import frontend.Parser;

public class Cond {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.Cond;
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public LOrExp getLOrExp() {
        return lOrExp;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(lOrExp);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
