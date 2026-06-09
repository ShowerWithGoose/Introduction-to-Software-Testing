package frontend.parser;

import frontend.parser.declaration.Decl;
import frontend.parser.function.FuncDef;
import frontend.parser.function.MainFuncDef;

import java.util.ArrayList;

public class CompUnit implements SyntaxUnit{
    private final String name = "<CompUnit>";
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnit(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }

    public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs,
                    MainFuncDef mainFuncDef) {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        if (this.decls != null && !decls.isEmpty()) {
            for (Decl decl: decls) {
                sb.append(decl.syntaxPrint());
            }
        }
        if (this.funcDefs != null && !funcDefs.isEmpty()) {
            for (FuncDef funcDef: funcDefs) {
                sb.append(funcDef.syntaxPrint());
            }
        }
        sb.append(mainFuncDef.syntaxPrint());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
