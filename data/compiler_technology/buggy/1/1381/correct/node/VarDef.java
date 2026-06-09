package node;

import frontend.Parser;

public class VarDef {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.VarDef;
    private Ident ident;
    private ConstExp arraySize;
    private InitVal initVal;

    public VarDef(Ident ident, ConstExp arraySize, InitVal initVal) {
        this.ident = ident;
        this.arraySize = arraySize;
        this.initVal = initVal;
    }

    public Ident getIdent() {
        return ident;
    }

    public ConstExp getArraySize() {
        return arraySize;
    }

    public InitVal getInitVal() {
        return initVal;
    }

    public boolean isArray() {
        return arraySize != null;
    }

    public boolean isInit() {
        return initVal != null;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(ident);
        if (arraySize != null) {
            ret.append("\n").append(arraySize);
        }
        if (initVal != null) {
            ret.append("\n").append(initVal);
        }
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
