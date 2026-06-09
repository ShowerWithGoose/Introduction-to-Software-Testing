package frontend.Tree;

import frontend.Symbol.SymbolTree;

import java.util.ArrayList;

public class CompUnit {
    private ArrayList<Decl> decls;

    private ArrayList<FuncDef> funcDefs;

    private MainFuncDef mainFuncDef;

    public CompUnit(ArrayList<Decl> decls,
                    ArrayList<FuncDef> funcDefs, MainFuncDef mainFuncDef) {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
    }
}
