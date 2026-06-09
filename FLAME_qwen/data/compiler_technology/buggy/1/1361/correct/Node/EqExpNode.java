package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class EqExpNode {
    //相等性表达式 EqExp → RelExp | EqExp ('==' | '!=') RelExp
    private RelExpNode relExpNode;
    private Token operator;
    private EqExpNode eqExpNode;

    public EqExpNode(RelExpNode relExpNode, Token operator, EqExpNode eqExpNode) {
        this.relExpNode = relExpNode;
        this.operator = operator;
        this.eqExpNode = eqExpNode;
    }

    public void print() {
        relExpNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.EqExp));
        if (operator != null) {
            IO.ParserOutput(operator);
            eqExpNode.print();
        }
    }
}
