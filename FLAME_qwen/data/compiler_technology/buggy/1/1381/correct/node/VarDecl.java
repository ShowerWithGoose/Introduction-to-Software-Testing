package node;

import frontend.Parser;

import java.util.ArrayList;

public class VarDecl extends Decl {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.VarDecl;
    private BType bType;
    private ArrayList<VarDef> varDefList;

    public VarDecl(BType bType, ArrayList<VarDef> varDefList) {
        this.bType = bType;
        this.varDefList = varDefList;
    }

    public BType getBType() {
        return bType;
    }

    public ArrayList<VarDef> getVarDefList() {
        return varDefList;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder();
        ret.append("<").append(nodeType).append(">");
        ret.append("\n").append(bType.toString());
        for (VarDef varDef : varDefList) {
            ret.append("\n").append(varDef.toString());
        }
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}