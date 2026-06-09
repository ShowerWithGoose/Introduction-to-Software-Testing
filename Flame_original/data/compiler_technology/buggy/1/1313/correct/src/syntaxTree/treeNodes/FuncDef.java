package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

import java.util.ArrayList;

/**
 * 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
 */
public class FuncDef extends STNode {
    public FuncType funcType;
    public Token ident;
    public Token lParent;
    public FuncFParams funcFParams;
    public Token rParent;
    public Block block;

}
