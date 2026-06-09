package node;

import frontend.Parser;

import java.util.ArrayList;

public class ConstDecl extends Decl {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.ConstDecl;
    private BType bType;
    private ArrayList<ConstDef> constDefList;

    public ConstDecl(BType bType, ArrayList<ConstDef> constDefList) {
        this.bType = bType;
        this.constDefList = constDefList;
    }

    private BType getbType() {
        return bType;
    }

    private ArrayList<ConstDef> getConstDefList() {
        return constDefList;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(bType.toString());
        for (ConstDef constDef : constDefList) {
            ret.append("\n").append(constDef.toString());
        }
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
