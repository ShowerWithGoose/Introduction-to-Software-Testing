package frontend.tree.decl;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.tree.Node;
import frontend.semantic.BType;
import frontend.semantic.SymbolManager;

/**
 * 变量声明 VarDecl → BType VarDef { ',' VarDef } ';'
 * error: i
 */
public class VarDecl extends Node {
    @Override
    public void semanticAnalysis() {
        BType bType;
        if (((Token)children.get(0)).getLexType() == LexType.INTTK) {
            bType = BType.INT;
        } else {
            bType = BType.CHAR;
        }
        SymbolManager.getInstance().setCurBType(bType);
        super.semanticAnalysis();
        SymbolManager.getInstance().setCurBType(null);
    }
}
