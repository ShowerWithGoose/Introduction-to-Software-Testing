package frontend.tree.exp;

import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.semantic.SymbolManager;
import frontend.tree.Node;

/**
 * LVal → Ident ['[' Exp ']']
 * error: c k
 */
public class LVal extends Node {
    private Token ident;

    @Override
    public void semanticAnalysis() {
        ident = getIdent();
        String name = ident.getValue();
        if (!SymbolManager.getInstance().isDefined(name)) { // 未定义的名字
            ErrorList.getInstance().addError("c", ident.getLineNum());
        }
        super.semanticAnalysis();
    }

    public Token getIdent() {
        if (ident == null) {
            ident = (Token) children.get(0);
        }
        return ident;
    }

    public String getIdentifierName() {
        return getIdent().getValue();
    }
}
