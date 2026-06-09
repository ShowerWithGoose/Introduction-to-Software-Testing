package node;

import frontend.Parser;

import java.util.ArrayList;

public class FuncFParams {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.FuncFParams;
    private ArrayList<FuncFParam> funcFParamList;

    public FuncFParams(ArrayList<FuncFParam> funcFParamList) {
        this.funcFParamList = funcFParamList;
    }

    public ArrayList<FuncFParam> getFuncFParamList() {
        return funcFParamList;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        for (FuncFParam funcFParam : funcFParamList) {
            ret.append("\n").append(funcFParam.toString());
        }
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
