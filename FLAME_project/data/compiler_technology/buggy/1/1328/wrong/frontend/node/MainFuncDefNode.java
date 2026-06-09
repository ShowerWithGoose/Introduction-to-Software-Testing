package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class MainFuncDefNode {
    // 主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block

    private Token intToken;
    private Token mainToken;
    private Token leftParentToken;
    private Token rightParentToken;
    private BlockNode blockNode;

    public MainFuncDefNode(Token intToken, Token mainToken, Token leftParentToken, Token rightParentToken, BlockNode blockNode) {
        this.intToken = intToken;
        this.mainToken = mainToken;
        this.leftParentToken = leftParentToken;
        this.rightParentToken = rightParentToken;
        this.blockNode = blockNode;
    }

    public BlockNode getBlockNode() {
        return blockNode;
    }

    public void print() {
        MyIO.writeToken(intToken.toString());
        MyIO.writeToken(mainToken.toString());
        MyIO.writeToken(leftParentToken.toString());
        MyIO.writeToken(rightParentToken.toString());
        blockNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.MainFuncDef));
    }
}
