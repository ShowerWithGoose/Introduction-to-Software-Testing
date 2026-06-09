package node;

import frontend.Parser;

public class ConstDef {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.ConstDef;
    private Ident ident;
    private ConstExp arraySize;
    private ConstInitVal constInitVal;

    public ConstDef(Ident ident, ConstExp arraySize, ConstInitVal constInitVal) {
        this.ident = ident;
        this.arraySize = arraySize;
        this.constInitVal = constInitVal;
    }

    public Ident getIdent() {
        return ident;
    }

    public ConstExp getArraySize() {
        return arraySize;
    }

    public ConstInitVal getConstInitVal() {
        return constInitVal;
    }

    public boolean isArray() {
        return arraySize != null;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(ident.toString());
        if (arraySize != null) {
            ret.append("\n").append(arraySize.toString());
        }
        ret.append("\n").append(constInitVal.toString());
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
