package Node;

import Token.Token;
import frontend.Parser;

public class MainFuncDefNode {
    //MainFuncDef â†’ 'int' 'main' '(' ')' Block
    private BlockNode blockNode;
    Token intToken;
    Token mainToken;
    Token leftParent;
    Token rightParent;
    public MainFuncDefNode(Token intToken, Token mainToken, Token leftParent, Token rightParent, BlockNode blockNode){
        this.blockNode = blockNode;
        this.intToken = intToken;
        this.mainToken = mainToken;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
    }

    public void print(){
        Parser.getInstance().output(intToken);
        Parser.getInstance().output(mainToken);
        Parser.getInstance().output(leftParent);
        Parser.getInstance().output(rightParent);
        blockNode.print();
        Parser.getInstance().output(NodeType.MainFuncDef);
    }
}
