package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

import java.util.ArrayList;

/**
 * 乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
 */
public class MulExp extends STNode {
    public UnaryExp unaryExp;
    public MulExp mulExp;
    public Token token; // '*', '/', '%'

}
