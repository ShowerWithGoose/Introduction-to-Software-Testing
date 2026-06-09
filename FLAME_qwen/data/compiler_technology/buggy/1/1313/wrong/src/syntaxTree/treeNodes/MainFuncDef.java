package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

/**
 * 主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block // j
 */
public class MainFuncDef extends STNode {
    public Token tokenInt;
    public Token tokenMain;
    public Token lParent;
    public Token rParent;
    public Block block;
}
