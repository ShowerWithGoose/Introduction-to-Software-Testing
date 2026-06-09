package node;

import frontend.Parser;

public class ConstExp {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.ConstExp;
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public AddExp getAddExp() {
        return addExp;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(addExp.toString());
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
