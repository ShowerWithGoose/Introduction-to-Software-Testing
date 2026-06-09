package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class MulExpNode {
    //乘除模表达式 MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    private UnaryExpNode unaryExpNode;
    private Token operator;
    private MulExpNode mulExpNode;

    public MulExpNode(UnaryExpNode unaryExpNode, Token operator, MulExpNode mulExpNode) {
        this.unaryExpNode = unaryExpNode;
        this.operator = operator;
        this.mulExpNode = mulExpNode;
    }

    public void print() {
        unaryExpNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.MulExp));
        if (operator != null) {
            IO.ParserOutput(operator);
            mulExpNode.print();
        }
    }
}
