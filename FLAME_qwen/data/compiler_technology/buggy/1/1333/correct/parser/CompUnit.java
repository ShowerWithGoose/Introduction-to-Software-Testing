package parser;

import parser.func.FuncDef;
import parser.func.MainFuncDef;

import java.util.ArrayList;

public class CompUnit {
    private final ArrayList<Decl> decls;
    private final ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnit() {
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
        this.mainFuncDef = null;
    }

    public void addDecl(Decl decl) {
        this.decls.add(decl);
    }

    public void addFuncDef(FuncDef funcDef) {
        this.funcDefs.add(funcDef);
    }

    public void setMainFuncDef(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }

    public String toString() {
        StringBuilder str = new StringBuilder();
        for (Decl decl : this.decls) {
            str.append(decl.toString());
        }
        for (FuncDef funcDef : this.funcDefs) {
            str.append(funcDef.toString());
        }
        str.append(this.mainFuncDef.toString() + "<CompUnit>\n");
        return str.toString();
    }
}
