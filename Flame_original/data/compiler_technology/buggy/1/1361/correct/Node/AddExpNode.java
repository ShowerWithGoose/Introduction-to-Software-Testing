package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class AddExpNode {
    //加减表达式 AddExp → MulExp | AddExp ('+' | '−') MulExp
    private MulExpNode mulExpNode;
    private Token operator;
    private AddExpNode addExpNode;

    public AddExpNode(MulExpNode mulExpNode, Token operator, AddExpNode addExpNode) {
        this.mulExpNode = mulExpNode;
        this.operator = operator;
        this.addExpNode = addExpNode;
    }

    public void print() {
        mulExpNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.AddExp));
        if (operator != null) {
            IO.ParserOutput(operator);
            addExpNode.print();
        }
    }
}
