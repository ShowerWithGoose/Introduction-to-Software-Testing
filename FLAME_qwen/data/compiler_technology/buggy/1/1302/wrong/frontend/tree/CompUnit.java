package frontend.tree;

import frontend.semantic.SymbolManager;

/**
 * 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
 */
public class CompUnit extends Node {

    public CompUnit() {
        super();
    }

    @Override
    public void semanticAnalysis() {
        SymbolManager.getInstance().enterBlock();
        super.semanticAnalysis();
        SymbolManager.getInstance().exitBlock();
    }
}
