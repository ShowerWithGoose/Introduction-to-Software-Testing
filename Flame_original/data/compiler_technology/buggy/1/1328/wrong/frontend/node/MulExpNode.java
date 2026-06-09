package frontend.node;

import frontend.Parser;
import frontend.token.Token;
import utils.MyIO;

public class MulExpNode {
    // 乘除模表达式 MulExp → UnaryExp[ ('*' | '/' | '%') MulExp]

    private UnaryExpNode unaryExpNode;
    private Token operator;
    private MulExpNode mulExpNode;

    public MulExpNode(UnaryExpNode unaryExpNode, Token operator, MulExpNode mulExpNode) {
        this.unaryExpNode = unaryExpNode;
        this.operator = operator;
        this.mulExpNode = mulExpNode;
    }

    public UnaryExpNode getUnaryExpNode() {
        return unaryExpNode;
    }

    public Token getOperator() {
        return operator;
    }

    public MulExpNode getMulExpNode() {
        return mulExpNode;
    }

    public void print() {
        unaryExpNode.print();
        // WARN: 注意这里的顺序，要把改变掉的语法树结构在打印的时候调整回来
        MyIO.writeNode(Parser.nodeType.get(NodeType.MulExp));
        if (operator != null) {
            MyIO.writeToken(operator.toString());
            mulExpNode.print();
        }
    }
}
