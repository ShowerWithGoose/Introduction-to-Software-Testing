package parser.node;

import lexer.Token;
import lexer.TokenType;
import parser.NodeType;

public class MainFuncDefNode {
    Token intTK;
    Token mainTK;
    Token lParent;
    Token rParent;
    BlockNode blockNode;

    public MainFuncDefNode(Token intTK, Token mainTK, Token lParent, Token rParent, BlockNode blockNode) {
        this.intTK = intTK;
        this.mainTK = mainTK;
        this.lParent = lParent;
        this.rParent = rParent;
        this.blockNode = blockNode;
    }

    public void print() {
        intTK.print();
        mainTK.print();
        lParent.print();
        rParent.print();
        blockNode.print();
        System.out.println(NodeType.MainFuncDef);
    }

}
