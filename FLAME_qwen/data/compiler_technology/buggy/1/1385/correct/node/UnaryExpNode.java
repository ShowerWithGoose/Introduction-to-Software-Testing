package node;

import token.Token;

import java.io.IOException;

public class UnaryExpNode {
    // UnaryExp -> PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    private PrimaryExpNode primaryExpNode;
    private Token ident;
    private Token leftParentToken;
    private FuncRParamsNode funcRParamsNode;
    private Token rightParentToken;
    private UnaryOpNode unaryOpNode;
    private UnaryExpNode unaryExpNode;

    public UnaryExpNode(PrimaryExpNode primaryExpNode) {
        this.primaryExpNode = primaryExpNode;
        this.ident = null;
        this.leftParentToken = null;
        this.funcRParamsNode = null;
        this.rightParentToken = null;
        this.unaryOpNode = null;
        this.unaryExpNode = null;
    }

    public UnaryExpNode(Token ident, Token leftParentToken, FuncRParamsNode funcRParamsNode, Token rightParentToken) {
        this.primaryExpNode = null;
        this.unaryOpNode = null;
        this.unaryExpNode = null;
        this.ident = ident;
        this.leftParentToken = leftParentToken;
        this.funcRParamsNode = funcRParamsNode;
        this.rightParentToken = rightParentToken;
    }

    public UnaryExpNode(UnaryOpNode unaryOpNode, UnaryExpNode unaryExpNode) {
        this.primaryExpNode = null;
        this.ident = null;
        this.leftParentToken = null;
        this.funcRParamsNode = null;
        this.rightParentToken = null;
        this.unaryOpNode = unaryOpNode;
        this.unaryExpNode = unaryExpNode;
    }
    
    public void print() throws IOException {
        if (primaryExpNode!=null) {
            primaryExpNode.print();
        }
        else if (ident!=null) {
            ident.print();
            leftParentToken.print();
            if (funcRParamsNode!=null) {
                funcRParamsNode.print();
            }
            rightParentToken.print();
        }
        else {
            unaryOpNode.print();
            unaryExpNode.print();
        }
        Io.Text.printWord("<UnaryExp>");
    }
}
