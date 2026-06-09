package parser.node;

import lexer.Token;
import parser.NodeType;

public class FuncDefNode {
    FuncTypeNode funcTypeNode;
    Token identTK;
    Token lParent;
    FuncFParamsNode funcFParamsNode;
    Token rParent;
    BlockNode blockNode;

    public FuncDefNode(FuncTypeNode funcTypeNode, Token identTK, Token lParent, FuncFParamsNode funcFParamsNode, Token rParent, BlockNode blockNode) {
        this.funcTypeNode = funcTypeNode;
        this.identTK = identTK;
        this.lParent = lParent;
        this.funcFParamsNode = funcFParamsNode;
        this.rParent = rParent;
        this.blockNode = blockNode;
    }
    public void print() {
        funcTypeNode.print();
        identTK.print();
        lParent.print();
        if (funcFParamsNode!=null)
        {
            funcFParamsNode.print();
        }
        rParent.print();
        blockNode.print();
        System.out.println(NodeType.FuncDef);
    }
}
