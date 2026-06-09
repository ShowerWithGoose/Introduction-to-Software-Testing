package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 左值表达式 LVal → Ident ['[' Exp ']'] // k
 */
public class LVal extends STNode {
    public Token ident;
    public Token lBrack;
    public Exp exp;
    public Token rBrack;
}
