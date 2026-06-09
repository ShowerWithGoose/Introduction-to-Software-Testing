package frontend.GrammaticalElements;

import frontend.GrammaticalElements.declaration.Decl;
import frontend.GrammaticalElements.declaration.FuncDef;
import frontend.GrammaticalElements.declaration.MainFuncDef;

import java.util.ArrayList;

public class CompUnit {
    private final String name = "<CompUnit>";
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs, MainFuncDef mainFuncDef) {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Decl decl : decls) {
            sb.append(decl.toString());
        }
        for (FuncDef funcDef : funcDefs) {
            sb.append(funcDef.toString());
        }
        sb.append(mainFuncDef.toString());
        sb.append(this.name).append("\n");
        return sb.toString();
    }
}
