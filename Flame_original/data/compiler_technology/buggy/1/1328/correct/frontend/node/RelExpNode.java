package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class RelExpNode {
    // 关系表达式 RelExp → AddExp[ ('<' | '>' | '<=' | '>=') RelExp]
    private AddExpNode addExpNode;
    private Token operator;
    private RelExpNode relExpNode;

    public RelExpNode(AddExpNode addExpNode, Token operator, RelExpNode relExpNode) {
        this.addExpNode = addExpNode;
        this.operator = operator;
        this.relExpNode = relExpNode;
    }

    public AddExpNode getAddExpNode() {
        return addExpNode;
    }

    public Token getOperator() {
        return operator;
    }

    public RelExpNode getRelExpNode() {
        return relExpNode;
    }

    public void print() {
        addExpNode.print();
        MyIO.writeNode(Parser.nodeType.get(NodeType.RelExp));
        if (operator != null) {
            MyIO.writeToken(operator.toString());
            relExpNode.print();
        }
    }
}
