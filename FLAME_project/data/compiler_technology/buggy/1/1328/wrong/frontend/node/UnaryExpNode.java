package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class UnaryExpNode {
    // 一元表达式 UnaryExp -> PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    private PrimaryExpNode primaryExpNode;
    private Token ident;
    private Token lparentToken;
    private FuncRParamsNode funcRParamsNode;
    private Token rparentToken;
    private UnaryOpNode unaryOpNode;
    private UnaryExpNode unaryExpNode;

    public UnaryExpNode(PrimaryExpNode primaryExpNode) {
        this.primaryExpNode = primaryExpNode;
    }

    public UnaryExpNode(Token ident, Token lparentToken, FuncRParamsNode funcRParamsNode, Token rparentToken) {
        this.ident = ident;
        this.lparentToken = lparentToken;
        this.funcRParamsNode = funcRParamsNode;
        this.rparentToken = rparentToken;
    }

    public UnaryExpNode(UnaryOpNode unaryOpNode, UnaryExpNode unaryExpNode) {
        this.unaryOpNode = unaryOpNode;
        this.unaryExpNode = unaryExpNode;
    }

    public PrimaryExpNode getPrimaryExpNode() {
        return primaryExpNode;
    }

    public Token getIdent() {
        return ident;
    }

    public FuncRParamsNode getFuncRParamsNode() {
        return funcRParamsNode;
    }

    public UnaryOpNode getUnaryOpNode() {
        return unaryOpNode;
    }

    public UnaryExpNode getUnaryExpNode() {
        return unaryExpNode;
    }

    public void print() {
        if (primaryExpNode != null) {
            primaryExpNode.print();
        } else if (ident != null) {
            MyIO.writeToken(ident.toString());
            MyIO.writeToken(lparentToken.toString());
            if (funcRParamsNode != null) {
                funcRParamsNode.print();
            }
            MyIO.writeToken(rparentToken.toString());
        } else {
            unaryOpNode.print();
            unaryExpNode.print();
        }
        MyIO.writeNode(Parser.nodeType.get(NodeType.UnaryExp));
    }
}
