package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class MainFuncDefNode {
    //主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block // j
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
    public void print() {
        IO.ParserOutput(intToken);
        IO.ParserOutput(mainToken);
        IO.ParserOutput(leftParentToken);
        IO.ParserOutput(rightParentToken);
        blockNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.MainFuncDef));
    }
}
