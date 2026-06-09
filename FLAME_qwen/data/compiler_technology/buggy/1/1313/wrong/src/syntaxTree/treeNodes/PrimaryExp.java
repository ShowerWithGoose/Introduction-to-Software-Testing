package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;
import src.syntaxTree.enums.PrimaryExpType;

/**
 * 基本表达式 PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
 */
public class PrimaryExp extends STNode {
    public PrimaryExpType primaryExpType;
    public Token lParent;
    public Exp exp;
    public Token rParent;
    public LVal lVal;
    public Number number;
    public Character character;
}
