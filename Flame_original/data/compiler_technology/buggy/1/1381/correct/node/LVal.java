package node;

import frontend.Parser;

public class LVal {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.LVal;
    private Ident ident;
    private Exp index;

    public LVal(Ident ident, Exp index) {
        this.ident = ident;
        this.index = index;
    }

    public Ident getIdent() {
        return ident;
    }

    public Exp getIndex() {
        return index;
    }

    public boolean hasIndex() {
        return index != null;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(ident);
        if (hasIndex()) ret.append("\n").append(index);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
