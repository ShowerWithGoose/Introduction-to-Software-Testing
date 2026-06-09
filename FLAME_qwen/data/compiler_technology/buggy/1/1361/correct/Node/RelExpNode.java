package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class RelExpNode {
    //关系表达式 RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    private AddExpNode addExpNode;
    private Token operator;
    private RelExpNode relExpNode;


    public RelExpNode(AddExpNode addExpNode, Token operator, RelExpNode relExpNode) {
        this.addExpNode = addExpNode;
        this.operator = operator;
        this.relExpNode = relExpNode;
    }


    public void print() {
        addExpNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.RelExp));
        if (operator != null) {
            IO.ParserOutput(operator);
            relExpNode.print();
        }
    }
}
