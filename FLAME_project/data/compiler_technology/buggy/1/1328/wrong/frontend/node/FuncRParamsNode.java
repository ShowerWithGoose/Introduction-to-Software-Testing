package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

import java.util.ArrayList;

public class FuncRParamsNode {
    // 函数实参表 FuncRParams -> Exp { ',' Exp }

    private ArrayList<ExpNode> expNodes;
    private Token commaToken;

    public FuncRParamsNode(ArrayList<ExpNode> expNodes, Token commaToken) {
        this.expNodes = expNodes;
        this.commaToken = commaToken;
    }

    public ArrayList<ExpNode> getExpNodes() {
        return expNodes;
    }

    public void print() {
        expNodes.get(0).print();
        for (int i = 1; i < expNodes.size(); i++) {
            MyIO.writeToken(commaToken.toString());
            expNodes.get(i).print();
        }
        MyIO.writeNode(Parser.nodeType.get(NodeType.FuncRParams));
    }
}
