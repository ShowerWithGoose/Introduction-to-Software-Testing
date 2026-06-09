package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

public class LValNode {
    //左值表达式 LVal → Ident ['[' Exp ']'] // k
    private Token ident;
    private Token leftBracket;
    private ExpNode exp;
    private Token rightBracket;

    public LValNode(Token ident, Token leftBracket, ExpNode exp, Token rightBracket) {
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.exp = exp;
        this.rightBracket = rightBracket;
    }

    public void print() {
        IO.ParserOutput(ident);
        if (leftBracket != null) {
            IO.ParserOutput(leftBracket);
            exp.print();
            IO.ParserOutput(rightBracket);
        }
        IO.ParserOutput(Parser.nodeType.get(NodeType.LVal));
    }
}
