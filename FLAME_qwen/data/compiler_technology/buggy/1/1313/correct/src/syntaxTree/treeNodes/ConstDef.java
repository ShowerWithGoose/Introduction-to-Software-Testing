package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
 */
public class ConstDef extends STNode {
    public Token ident;
    public Token lBrack;
    public ConstExp constExp;
    public Token rBrack;
    public Token assign;
    public ConstInitVal constInitVal;
}
