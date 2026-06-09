package node;

import token.Token;

import java.io.IOException;

public class MainFuncDefNode {
    // MainFuncDef -> 'int' 'main' '(' ')' Block

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
    
    public void print() throws IOException {
        intToken.print();
        mainToken.print();
        leftParentToken.print();
        rightParentToken.print();
        blockNode.print();
        Io.Text.printWord("<MainFuncDef>");
    }

    
}
