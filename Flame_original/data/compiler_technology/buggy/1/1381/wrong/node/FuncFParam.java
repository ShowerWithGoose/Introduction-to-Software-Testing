package node;

import frontend.Parser;

public class FuncFParam {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.FuncFParam;
    private BType bType;
    private Ident ident;
    private boolean isArray;

    public FuncFParam(BType bType, Ident ident, boolean isArray) {
        this.bType = bType;
        this.ident = ident;
        this.isArray = isArray;
    }

    public BType getBType() {
        return bType;
    }

    public Ident getIdent() {
        return ident;
    }

    public boolean isArray() {
        return isArray;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (isArray) ret.append("\n<Array>");
        ret.append("\n").append(bType.toString());
        ret.append("\n").append(ident.toString());
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
