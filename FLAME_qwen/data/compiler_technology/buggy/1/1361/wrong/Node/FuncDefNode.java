package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class FuncDefNode {
    //函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
    private FuncTypeNode funcTypeNode;
    private Token ident;
    private Token leftParentToken;
    private FuncFParamsNode funcFParamsNode;
    private Token rightParentToken;
    private BlockNode blockNode;

    public FuncDefNode(FuncTypeNode funcTypeNode, Token ident, Token leftParentToken, FuncFParamsNode funcFParamsNode, Token rightParentToken, BlockNode blockNode) {
        this.funcTypeNode = funcTypeNode;
        this.ident = ident;
        this.leftParentToken = leftParentToken;
        this.funcFParamsNode = funcFParamsNode;
        this.rightParentToken = rightParentToken;
        this.blockNode = blockNode;
    }

    public void print() {
        funcTypeNode.print();
        IO.ParserOutput(ident);
        IO.ParserOutput(leftParentToken);
        if (funcFParamsNode != null) {
            funcFParamsNode.print();
        }
        IO.ParserOutput(rightParentToken);
        blockNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.FuncDef));
    }
}
