package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class EqExpNode {
    // 相等性表达式 EqExp → RelExp[ ('==' | '!=') EqExp]
    private RelExpNode relExpNode;
    private Token operator;
    private EqExpNode eqExpNode;

    public EqExpNode(RelExpNode relExpNode, Token operator, EqExpNode eqExpNode) {
        this.relExpNode = relExpNode;
        this.operator = operator;
        this.eqExpNode = eqExpNode;
    }

    public RelExpNode getRelExpNode() {
        return relExpNode;
    }

    public Token getOperator() {
        return operator;
    }

    public EqExpNode getEqExpNode() {
        return eqExpNode;
    }

    public void print() {
        relExpNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.EqExp));
        if (operator != null) {
            MyIO.writeToken(operator.toString());
            eqExpNode.print();
        }
    }
}
