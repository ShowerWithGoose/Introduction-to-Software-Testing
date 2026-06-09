package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
 */
public class EqExp extends STNode {
    public RelExp relExp;
    public EqExp eqExp;
    public Token token; // '==', '!='
}
