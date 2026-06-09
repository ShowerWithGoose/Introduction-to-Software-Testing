package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class LAndExpNode {
    // 逻辑与表达式 LAndExp → EqExp[ '&&' LAndExp]
    private EqExpNode eqExpNode;
    private Token andToken;
    private LAndExpNode lAndExpNode;

    public LAndExpNode(EqExpNode eqExpNode, Token operator, LAndExpNode lAndExpNode) {
        this.eqExpNode = eqExpNode;
        this.andToken = operator;
        this.lAndExpNode = lAndExpNode;
    }

    public EqExpNode getEqExpNode() {
        return eqExpNode;
    }

    public LAndExpNode getLAndExpNode() {
        return lAndExpNode;
    }

    public void print() {
        eqExpNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.LAndExp));
        if (andToken != null) {
            MyIO.writeToken(andToken.toString());
            lAndExpNode.print();
        }
    }
}
