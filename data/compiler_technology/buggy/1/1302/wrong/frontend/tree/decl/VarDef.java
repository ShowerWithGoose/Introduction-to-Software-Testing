package frontend.tree.decl;

import frontend.error.ErrorList;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.semantic.SymbolManager;
import frontend.semantic.Type;
import frontend.tree.Node;

/**
 * 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
 * error: b k
 */
public class VarDef extends Node {
    private Token ident;

    @Override
    public void semanticAnalysis() {
        ident = (Token)children.get(0);
        String name = ident.getValue();
        Type type;
        if (children.size() > 1 && ((Token)children.get(1)).getLexType() == LexType.LBRACK) { // 如果是'['开头，则是数组
            type = Type.ARRAY;
        } else {
            type = Type.VAR;
        }
        if (SymbolManager.getInstance().existsDupName(name)) {
            ErrorList.getInstance().addError("b", ident.getLineNum());
        } else {
            SymbolManager.getInstance().createAndAddSymbol(name, type, false);
        }
        super.semanticAnalysis();
    }
}
