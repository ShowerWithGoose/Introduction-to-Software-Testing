package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 函数形参 FuncFParam → BType Ident ['[' ']'] // k
 */
public class FuncFParam extends STNode {
    public BType bType;
    public Token ident;
    public Token lBrack;
    public Token rBrack;

}
