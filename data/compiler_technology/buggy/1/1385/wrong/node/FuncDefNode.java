package node;

import token.Token;

import java.io.IOException;

public class FuncDefNode {
    // FuncDef -> FuncType Ident '(' [FuncFParams] ')' Block

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
    
    public void print() throws IOException {
        funcTypeNode.print();
        ident.print();
        leftParentToken.print();
        if (funcFParamsNode!=null) {
            funcFParamsNode.print();
        }
        rightParentToken.print();
        blockNode.print();
        Io.Text.printWord("<FuncDef>");
    }
    
}
