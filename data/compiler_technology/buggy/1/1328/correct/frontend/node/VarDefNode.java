package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class VarDefNode {
    // 变量初值 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '= InitVal
    private Token ident;
    private Token lbrackToken;
    private ConstExpNode constExpNode;
    private Token rBrackToken;
    private Token assignToken;
    private InitValNode initValNode;

    public VarDefNode(Token ident, Token lbrackToken, ConstExpNode constExpNode, Token rBrackToken, Token assignToken, InitValNode initValNode) {
        this.ident = ident;
        this.lbrackToken = lbrackToken;
        this.constExpNode = constExpNode;
        this.rBrackToken = rBrackToken;
        this.assignToken = assignToken;
        this.initValNode = initValNode;
    }

    public Token getIdent() {
        return ident;
    }
    public ConstExpNode getConstExpNode() {
        return constExpNode;
    }
    public InitValNode getInitValNode() {
        return initValNode;
    }

    public void print() {
        MyIO.writeToken(ident.toString());
        if (constExpNode != null) {
            MyIO.writeToken(lbrackToken.toString());
            constExpNode.print();
            MyIO.writeToken(rBrackToken.toString());
        }
        if (initValNode != null) {
            MyIO.writeToken(assignToken.toString());
            initValNode.print();
        }
        MyIO.writeNode(Parser.nodeType.get(NodeType.VarDef));
    }
}
