package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 基本类型 BType → 'int' | 'char'
 */
public class BType extends STNode {
    public Token token;
}
