package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 单目运算符 UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中
 */
public class UnaryOp extends STNode {
    public Token token;
}
