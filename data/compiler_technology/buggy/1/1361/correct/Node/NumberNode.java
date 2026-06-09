package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class NumberNode {
    //数值 Number → IntConst
    private Token intConst;

    public NumberNode(Token intConst) {
        this.intConst = intConst;
    }

    public void print() {
        IO.ParserOutput(intConst);
        IO.ParserOutput(Parser.nodeType.get(NodeType.Number));
    }
 }
