package node;

import frontend.Parser;

import java.util.ArrayList;

public class CompUnit {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.CompUnit;
    private ArrayList<Decl> declList;
    private ArrayList<FuncDef> funcDefList;
    private MainFuncDef mainFuncDef;

    public CompUnit(ArrayList<Decl> declList, ArrayList<FuncDef> funcDefList,
                    MainFuncDef mainFuncDef) {
        this.declList = declList;
        this.funcDefList = funcDefList;
        this.mainFuncDef = mainFuncDef;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        for (Decl decl : declList) {
            ret.append("\n").append(decl.toString());
        }
        for (FuncDef funcDef : funcDefList) {
            ret.append("\n").append(funcDef.toString());
        }
        ret.append("\n").append(mainFuncDef.toString());
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
