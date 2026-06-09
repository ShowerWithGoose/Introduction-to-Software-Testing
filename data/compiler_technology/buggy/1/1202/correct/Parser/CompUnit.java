package Parser;

import Parser.Decl.Decl;
import Parser.FuncDef.FuncDef;

import java.util.ArrayList;

public class CompUnit implements Syntax {

    private String name;
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs, MainFuncDef mainFuncDef) {
        this.decls = decls;
        this.name = getName();
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    @Override
    public String getName() {
        return "<CompUnit>";
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
            for (Decl decl : decls) {
                sb.append(decl.syntaxOutput());
            }
        for (FuncDef funcDef : funcDefs) {
            sb.append(funcDef.syntaxOutput());
        }
        sb.append(mainFuncDef.syntaxOutput());
        sb.append(getName() + "\n");
        return sb.toString();
    }
}
