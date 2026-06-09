package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

import java.util.ArrayList;

public class ConstInitValNode {
    // 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private ConstExpNode constExpNode;
    private Token lbraceToken;
    private ArrayList<ConstExpNode> constExpNodes;
    private Token commaToken;
    private Token rbraceToken;
    private Token stringConstToken;

    public ConstInitValNode(ConstExpNode constExpNode, Token lbraceToken, ArrayList<ConstExpNode> constExpNodes, Token comma, Token rbraceToken, Token stringConstToken) {
        this.constExpNode = constExpNode;
        this.lbraceToken = lbraceToken;
        this.constExpNodes = constExpNodes;
        this.commaToken = comma;
        this.rbraceToken = rbraceToken;
        this.stringConstToken = stringConstToken;
    }

    public ConstExpNode getConstExpNode() {
        return constExpNode;
    }

    public ArrayList<ConstExpNode> getConstExpNodes() {
        return constExpNodes;
    }

    public void print() {
        if (constExpNode != null) {
            constExpNode.print();
        } else if (stringConstToken != null) {
            MyIO.writeToken(stringConstToken.toString());
        } else {
            MyIO.writeToken(lbraceToken.toString());
            if (!constExpNodes.isEmpty()) {
                constExpNodes.get(0).print();
                for (int i = 1; i < constExpNodes.size(); i++) {
                    MyIO.writeToken(commaToken.toString());
                    constExpNodes.get(i).print();
                }
            }
            MyIO.writeToken(rbraceToken.toString());
        }
        MyIO.writeNode(Parser.nodeType.get(NodeType.ConstInitVal));
    }
}
