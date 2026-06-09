package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

import java.util.List;

public class ConstDefNode {
    // 常量定义 ConstDef -> Ident [ '[' ConstExp ']'  '=' ConstInitVal
    private Token ident;
    private Token lbrackToken;
    private ConstExpNode constExpNode;
    private Token rbrackToken;
    private Token equalToken;
    private ConstInitValNode constInitValNode;

    public ConstDefNode(Token ident, Token lbrackToken, ConstExpNode constExpNode, Token rbrackToken, Token equalToken, ConstInitValNode constInitValNode) {
        this.ident = ident;
        this.lbrackToken = lbrackToken;
        this.constExpNode = constExpNode;
        this.rbrackToken = rbrackToken;
        this.equalToken = equalToken;
        this.constInitValNode = constInitValNode;
    }

    public Token getIdent() {
        return ident;
    }
    public ConstExpNode getConstExpNode() {
        return constExpNode;
    }
    public ConstInitValNode getConstInitValNode() {
        return constInitValNode;
    }

    public void print() {
        MyIO.writeToken(ident.toString());
        if(getConstExpNode()!=null){
            MyIO.writeToken(lbrackToken.toString());
            constExpNode.print();
            MyIO.writeToken(rbrackToken.toString());
        }
        MyIO.writeToken(equalToken.toString());
        constInitValNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.ConstDef));
    }
}
