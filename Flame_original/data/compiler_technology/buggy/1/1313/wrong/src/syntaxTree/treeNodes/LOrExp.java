package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
 */
public class LOrExp extends STNode {
    public LAndExp lAndExp;
    public LOrExp lOrExp;
    public Token tokenOr; // '||'
}
