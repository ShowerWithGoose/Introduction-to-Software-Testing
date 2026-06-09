package node;

import frontend.Parser;

import java.util.ArrayList;

public class FuncRParams {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.FuncRParams;
    private ArrayList<Exp> expList;

    public FuncRParams(ArrayList<Exp> expList) {
        this.expList = expList;
    }

    public ArrayList<Exp> getExpList() {
        return expList;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        for (Exp exp : expList) ret.append("\n").append(exp);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
