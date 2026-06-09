package frontend.tree.func;

import frontend.error.ErrorList;
import frontend.tree.Node;
import frontend.tree.exp.LVal;
import frontend.semantic.SymbolManager;

/**
 * 语句 ForStmt → LVal '=' Exp
 * error: h
 */
public class ForStmt extends Node {
    @Override
    public void semanticAnalysis() {
        LVal lVal = ((LVal) children.get(0));
        if (SymbolManager.getInstance().isConst(lVal.getIdentifierName())) { // 不能改变常量的值
            ErrorList.getInstance().addError("h", lVal.getIdent().getLineNum());
        }
        super.semanticAnalysis();
    }
}
