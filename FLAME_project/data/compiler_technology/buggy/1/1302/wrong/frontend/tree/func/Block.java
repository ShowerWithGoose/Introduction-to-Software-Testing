package frontend.tree.func;

import frontend.tree.Node;
import frontend.semantic.SymbolManager;

/**
 * 语句块 Block → '{' { BlockItem } '}'
 */
public class Block extends Node {
    @Override
    public void semanticAnalysis() {
        SymbolManager.getInstance().enterBlock();
        super.semanticAnalysis();
        SymbolManager.getInstance().exitBlock();
    }
}
