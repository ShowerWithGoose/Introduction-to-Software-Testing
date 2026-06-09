package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

import java.util.ArrayList;
import java.util.List;

public class InitValNode {
    // 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private ExpNode expNode;
    private Token lbraceToken;
    private ArrayList<ExpNode> expNodes;
    private Token commaToken;
    private Token rbraceToken;
    private Token stringConstToken;

    public InitValNode(ExpNode expNode, Token lbraceToken, ArrayList<ExpNode> expNodes, Token commaToken, Token rbraceToken, Token stringConstToken) {
        this.expNode = expNode;
        this.lbraceToken = lbraceToken;
        this.expNodes = expNodes;
        this.commaToken = commaToken;
        this.rbraceToken = rbraceToken;
        this.stringConstToken = stringConstToken;
    }

    public ExpNode getExpNode() {
        return expNode;
    }

    public ArrayList<ExpNode> getExpNodes() {
        return expNodes;
    }

    public void print() {
        if (expNode != null) {
            expNode.print();
        } else if (stringConstToken != null) {
            MyIO.writeToken(stringConstToken.toString());
        } else {
            MyIO.writeToken(lbraceToken.toString());
            if (!expNodes.isEmpty()) {
                expNodes.get(0).print();
                for (int i = 1; i < expNodes.size(); i++) {
                    MyIO.writeToken(commaToken.toString());
                    expNodes.get(i).print();
                }
            }
            MyIO.writeToken(rbraceToken.toString());
        }
        MyIO.writeNode(Parser.nodeType.get(NodeType.InitVal));
    }
}
