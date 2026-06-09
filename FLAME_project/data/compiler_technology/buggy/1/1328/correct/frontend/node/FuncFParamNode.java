package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

import java.util.List;

public class FuncFParamNode {
    // 函数形参 FuncFParam → BType Ident ['[' ']']

    private BTypeNode bTypeNode;
    private Token ident;
    private Token lbrackToken;
    private Token rbrackToken;

    public FuncFParamNode(BTypeNode bTypeNode, Token ident, Token lbrackToken, Token rbrackToken) {
        this.bTypeNode = bTypeNode;
        this.ident = ident;
        this.lbrackToken = lbrackToken;
        this.rbrackToken = rbrackToken;
    }

    public BTypeNode getbTypeNode() {
        return bTypeNode;
    }

    public Token getIdent() {
        return ident;
    }

    public void print() {
        bTypeNode.print();
        MyIO.writeToken(ident.toString());
        if (lbrackToken != null) {
            MyIO.writeToken(lbrackToken.toString());
            MyIO.writeToken(rbrackToken.toString());
        }
        MyIO.writeNode(Parser.nodeType.get(NodeType.FuncFParam));
    }
}
