package frontend.tree.decl;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.tree.Node;
import frontend.semantic.BType;
import frontend.semantic.SymbolManager;

/**
 * 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
 * error: i
 */
public class ConstDecl extends Node {
    @Override
    public void semanticAnalysis() {
        BType bType;
        if (((Token)children.get(1)).getLexType() == LexType.INTTK) {
            bType = BType.INT;
        } else {
            bType = BType.CHAR;
        }
        SymbolManager.getInstance().setCurBType(bType);
        super.semanticAnalysis();
        SymbolManager.getInstance().setCurBType(null);
    }
}
