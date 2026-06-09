package frontend.ParserModule;

import frontend.ParserModule.BlockItem.Decl;

import java.util.ArrayList;

public class CompileUnit {
    private final ArrayList<Decl> decls = new ArrayList<>();
    private final ArrayList<FuncDef> funcDefs = new ArrayList<>();
    private MainBlock mainBlock;

    public void addDecl(Decl decl) {
        this.decls.add(decl);
    }

    public void addFuncDef(FuncDef funcDef) {
        this.funcDefs.add(funcDef);
    }

    public void setMainBlock(MainBlock mainBlock) {
        this.mainBlock = mainBlock;
    }

    public void printRes() {
        for (Decl decl : decls) {
            decl.printRes();
        }
        for (FuncDef funcDef : funcDefs) {
            funcDef.printRes();
        }
        mainBlock.printRes();
        System.out.println("<CompUnit>");
    }

    public void checkGrammarError() {
        for (Decl decl : decls) {
            decl.checkGrammarError();
        }
        for (FuncDef funcDef : funcDefs) {
            funcDef.checkGrammarError();
        }
        mainBlock.checkGrammarError();
    }

}
