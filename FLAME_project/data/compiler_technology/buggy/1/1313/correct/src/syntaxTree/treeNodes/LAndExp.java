package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
 */
public class LAndExp extends STNode {
    public EqExp eqExp;
    public LAndExp lAndExp;
    public Token tokenAnd; // '&&'
}
