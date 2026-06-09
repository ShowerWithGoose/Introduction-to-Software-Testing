package syntacticanalysis.node;

import syntacticanalysis.node.function.FuncDef;
import syntacticanalysis.node.function.MainFuncDef;
import syntacticanalysis.node.init.Decl;

import java.util.ArrayList;

public class CompUnit {
    private String name = "<CompUnit>";
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs, MainFuncDef mainFuncDef) {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    public String syntaxOutput()
    {
        StringBuilder sb = new StringBuilder();
        if (!decls.isEmpty()) {
            for (Decl decl : decls) {
                sb.append(decl.syntaxOutput());
                sb.append("\n");
            }
        }
        if (!funcDefs.isEmpty()) {
            for (FuncDef funcDef : funcDefs) {
                sb.append(funcDef.syntaxOutput());
                sb.append("\n");
            }
        }
        sb.append(mainFuncDef.syntaxOutput());
        sb.append("\n");
        sb.append(name);
        return sb.toString();
    }
}
