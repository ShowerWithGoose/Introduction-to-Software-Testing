package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

import java.util.ArrayList;

/**
 * 加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
 */
public class AddExp extends STNode {
    public MulExp mulExp;
    public AddExp addExp;
    public Token token; // '+', '-'
}
