package frontend.Parser;

import frontend.Parser.ASTNode;
import frontend.Parser.Declaration.Decl;
import frontend.Parser.Function.FuncDef;
import frontend.Parser.Function.MainFuncDef;

import java.io.BufferedWriter;
import java.util.ArrayList;

public class CompUnit implements ASTNode {
    private ArrayList<Decl> decls;          // 可选
    private ArrayList<FuncDef> funcDefs;    // 可选
    private MainFuncDef mainFuncDef;

    public CompUnit (ArrayList<Decl> decls,
                     ArrayList<FuncDef> funcDefs,
                     MainFuncDef mainFuncDef) {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        if (!decls.isEmpty()) {
            for (Decl decl : decls) {
                sb.append(decl.printString());
            }
        }
        if (!funcDefs.isEmpty()) {
            for (FuncDef funcDef : funcDefs) {
                sb.append(funcDef.printString());
            }
        }
        if (mainFuncDef != null) {
            sb.append(mainFuncDef.printString());
        }
        sb.append("<" + "CompUnit" + ">\n");
        return sb.toString();
    }
}
