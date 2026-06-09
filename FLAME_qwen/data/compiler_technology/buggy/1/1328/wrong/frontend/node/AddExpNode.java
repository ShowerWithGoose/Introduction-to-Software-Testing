package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class AddExpNode {
    // 加减表达式 AddExp → MulExp[ ('+' | '−') AddExp]
    private MulExpNode mulExpNode;
    private Token operator;
    private AddExpNode addExpNode;

    public AddExpNode(MulExpNode mulExpNode, Token operator, AddExpNode addExpNode) {
        this.mulExpNode = mulExpNode;
        this.operator = operator;
        this.addExpNode = addExpNode;
    }

    public MulExpNode getMulExpNode() {
        return mulExpNode;
    }

    public Token getOperator() {
        return operator;
    }

    public AddExpNode getAddExpNode() {
        return addExpNode;
    }

    public void print() {
        mulExpNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.AddExp));
        if (operator != null) {
            MyIO.writeToken(operator.toString());
            addExpNode.print();
        }
    }
}
