package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

import java.util.List;

public class LValNode {
    // 左值表达式 LVal -> Ident ['[' Exp ']']
    private Token ident;
    private Token lbrackToken;
    private ExpNode expNode;
    private Token rbrackToken;

    public LValNode(Token ident, Token lbrackToken, ExpNode expNode, Token rbrackToken) {
        this.ident = ident;
        this.lbrackToken = lbrackToken;
        this.expNode = expNode;
        this.rbrackToken = rbrackToken;
    }

    public Token getIdent() {
        return ident;
    }

    public ExpNode getExpNode() {
        return expNode;
    }

    public void print() {
        MyIO.writeToken(ident.toString());
        if (expNode != null) {
            MyIO.writeToken(lbrackToken.toString());
            expNode.print();
            MyIO.writeToken(rbrackToken.toString());
        }
        MyIO.writeNode(Parser.nodeType.get(NodeType.LVal));
    }
}
