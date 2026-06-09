package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;


/**
 * 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
 * 改写：Ident [ '[' ConstExp ']' ] [ '=' InitVal ] // k
 */
public class VarDef extends STNode {
    public Token ident;
    public Token lBrack;
    public ConstExp constExp;
    public Token rBrack;
    public Token assign;
    public InitVal initval;
}
