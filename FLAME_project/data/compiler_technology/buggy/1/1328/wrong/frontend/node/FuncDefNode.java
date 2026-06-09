package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class FuncDefNode {
    // 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    
    private FuncTypeNode funcTypeNode;
    private Token ident;
    private Token lparentToken;
    private FuncFParamsNode funcFParamsNode;
    private Token rparentToken;
    private BlockNode blockNode;

    public FuncDefNode(FuncTypeNode funcTypeNode, Token ident, Token lparentToken, FuncFParamsNode funcFParamsNode, Token rparentToken, BlockNode blockNode) {
        this.funcTypeNode = funcTypeNode;
        this.ident = ident;
        this.lparentToken = lparentToken;
        this.funcFParamsNode = funcFParamsNode;
        this.rparentToken = rparentToken;
        this.blockNode = blockNode;
    }

    public FuncTypeNode getFuncTypeNode() {
        return funcTypeNode;
    }

    public Token getIdent() {
        return ident;
    }

    public FuncFParamsNode getFuncFParamsNode() {
        return funcFParamsNode;
    }

    public BlockNode getBlockNode() {
        return blockNode;
    }

    public void print() {
        funcTypeNode.print();
        MyIO.writeToken(ident.toString());
        MyIO.writeToken(lparentToken.toString());
        if (funcFParamsNode != null) {
            funcFParamsNode.print();
        }
        MyIO.writeToken(rparentToken.toString());
        blockNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.FuncDef));
    }
}
