package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class LOrExpNode {
    //逻辑或表达式 LOrExp → LAndExp | LOrExp '||' LAndExp
    private LAndExpNode lAndExpNode;
    private Token orToken;
    private LOrExpNode lOrExpNode;

    public LOrExpNode(LAndExpNode lAndExpNode, Token operator, LOrExpNode lOrExpNode) {
        this.lAndExpNode = lAndExpNode;
        this.orToken = operator;
        this.lOrExpNode = lOrExpNode;
    }

    public void print() {
        lAndExpNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.LOrExp));
        if (orToken != null) {
            IO.ParserOutput(orToken);
            lOrExpNode.print();
        }
    }
}
