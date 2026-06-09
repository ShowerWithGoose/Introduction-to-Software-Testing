package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class FuncFParamNode {
    //函数形参 FuncFParam → BType Ident ['[' ']'] // k
    private BTypeNode bTypeNode;
    private Token ident;
    private Token leftBracket;
    private Token rightBracket;

    public FuncFParamNode(BTypeNode bTypeNode, Token ident, Token leftBracket, Token rightBracket) {
        this.bTypeNode = bTypeNode;
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.rightBracket = rightBracket;
    }

    public void print() {
        bTypeNode.print();
        IO.ParserOutput(ident);
        if (leftBracket != null) {
            IO.ParserOutput(leftBracket);
            IO.ParserOutput(rightBracket);
        }
        IO.ParserOutput(Parser.nodeType.get(NodeType.FuncFParam));
    }
}
