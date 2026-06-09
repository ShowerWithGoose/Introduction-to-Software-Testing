package parser_part;

import llvm_part.IrModule;
import llvm_part.IrValue;
import parser_part.declaration.Decl;
import parser_part.function.FuncDef;
import parser_part.function.MainFuncDef;

import java.util.ArrayList;

public class CompUnit implements Node {
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs, MainFuncDef mainFuncDef) {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    public ArrayList<Decl> getDecls() {
        return decls;
    }

    public ArrayList<FuncDef> getFuncDefs() {
        return funcDefs;
    }

    public MainFuncDef getMainFuncDef() {
        return mainFuncDef;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Decl decl : decls) {
            sb.append(decl);
        }
        for (FuncDef funcDef : funcDefs) {
            sb.append(funcDef);
        }
        sb.append(mainFuncDef).append("<CompUnit>\n");
        return sb.toString();
    }
}
