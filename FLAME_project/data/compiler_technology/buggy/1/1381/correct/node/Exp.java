package node;

import frontend.Parser;

public class Exp {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.Exp;
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(addExp);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
