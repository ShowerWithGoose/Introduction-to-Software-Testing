package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class LAndExpNode {
    //逻辑与表达式 LAndExp → EqExp | LAndExp '&&' EqExp
    private EqExpNode eqExpNode;
    private Token andToken;
    private LAndExpNode lAndExpNode;

    public LAndExpNode(EqExpNode eqExpNode, Token operator, LAndExpNode lAndExpNode) {
        this.eqExpNode = eqExpNode;
        this.andToken = operator;
        this.lAndExpNode = lAndExpNode;
    }

    public void print() {
        eqExpNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.LAndExp));
        if (andToken != null) {
            IO.ParserOutput(andToken);
            lAndExpNode.print();
        }
    }
}
