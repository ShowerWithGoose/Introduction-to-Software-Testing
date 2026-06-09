package frontend.AST;

import java.util.ArrayList;

import frontend.AST.Decl.Decl;
import frontend.AST.Func.FuncDef;
import frontend.AST.Func.MainFuncDef;

// CompUnit â†’ {Decl} {FuncDef} MainFuncDef
public class CompUnit implements SyntaxNode {
    private final ArrayList<Decl> decls;
    private final ArrayList<FuncDef> funcDefs;
    private final MainFuncDef mainFuncDef;

    public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs, MainFuncDef mainFuncDef) {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }

    @Override
    public void print() {
        for (Decl decl : decls) {
            decl.print();
        }
        for (FuncDef funcDef : funcDefs) {
            funcDef.print();
        }
        mainFuncDef.print();
        AST.ast.addLine(getName());
    }

    @Override
    public String getName() {
        return "<CompUnit>";
    }
}
