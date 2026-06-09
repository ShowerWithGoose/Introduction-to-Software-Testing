package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

import java.util.ArrayList;

/**
 * 关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
 */
public class RelExp extends STNode {
    public AddExp addExp;
    public RelExp relExp;
    public Token token; // '<', '>', '<=', '>='

}
