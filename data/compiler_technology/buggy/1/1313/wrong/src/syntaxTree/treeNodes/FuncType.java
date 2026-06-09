package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 函数类型 FuncType → 'void' | 'int' | 'char'
 */
public class FuncType extends STNode {
    public Token token;
}
