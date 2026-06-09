package frontend.parser;

import frontend.parser.declaration.Decl;
import frontend.parser.function.FuncDef;
import frontend.parser.function.MainFuncDef;

import java.util.ArrayList;

public class CompUnit {
    private final String name = "<CompUnit>";
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnit() {
        decls = new ArrayList<>();
        funcDefs = new ArrayList<>();
        mainFuncDef = null;
    }

    public void addDecl(Decl decl) {
        decls.add(decl);
    }

    public void addFuncDef(FuncDef funcDef) {
        funcDefs.add(funcDef);
    }

    public void setMainFuncDef(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }

    public String getOutPut() {
        StringBuilder str = new StringBuilder();
        for (Decl decl : decls) {
            str.append(decl.getOutPut());
        }
        for (FuncDef funcDef : funcDefs) {
            str.append(funcDef.getOutPut());
        }
        str.append(mainFuncDef.getOutPut());
        str.append(name + "\n");
        return str.toString();
    }

    public String getError() {
        StringBuilder str = new StringBuilder();
        for (Decl decl : decls) {
            str.append(decl.getError());
        }
        for (FuncDef funcDef : funcDefs) {
            str.append(funcDef.getError());
        }
        str.append(mainFuncDef.getError());
        return str.toString();
    }
}
