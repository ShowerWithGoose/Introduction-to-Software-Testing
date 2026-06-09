package frontend.Parser.SyntaxNode;

import java.io.IOException;
import java.io.PushbackReader;
import java.nio.charset.MalformedInputException;
import java.util.ArrayList;

public class CompUnit implements SyntaxNode {
    private final String name = "<CompUnit>";
    private ArrayList<Decl> declList;
    private ArrayList<FuncDef> funcDefList;
    private MainFuncDef mainFuncDef;

    public CompUnit(ArrayList<Decl> declList, ArrayList<FuncDef> funcDefList, MainFuncDef mainFuncDef) {
        this.declList = declList;
        this.funcDefList = funcDefList;
        this.mainFuncDef = mainFuncDef;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Decl decl : declList) {
            sb.append(decl.toString());
        }

        for (FuncDef funcDef : funcDefList) {
            sb.append(funcDef.toString());
        }

        sb.append(mainFuncDef.toString());
        sb.append(name + "\n");
        return sb.toString();
    }
}
