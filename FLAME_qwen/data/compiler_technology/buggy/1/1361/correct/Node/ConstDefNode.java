package Node;

import java.lang.reflect.Array;
import java.util.ArrayList;
import IOcontrol.*;
import LexParser.Parser;
import Token.*;

public class ConstDefNode {
    //常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
    private Token ident;
    private Token leftBracket;
    private ConstExpNode constExpNode;
    private Token rightBracket;
    private Token assignToken;
    private ConstInitValNode constInitValNode;

    public ConstDefNode(Token ident, Token leftBracket, ConstExpNode constExpNode,
                        Token rightBracket, Token assignToken, ConstInitValNode constInitValNode) {
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.constExpNode = constExpNode;
        this.rightBracket = rightBracket;
        this.assignToken = assignToken;
        this.constInitValNode = constInitValNode;
    }

    public void print() {
        IO.ParserOutput(ident);
        if (leftBracket != null) {
            IO.ParserOutput(leftBracket);
            constExpNode.print();
            IO.ParserOutput(rightBracket);
        }
        IO.ParserOutput(assignToken);
        constInitValNode.print();
        IO.ParserOutput(Parser.nodeType.get(NodeType.ConstDef));
    }
}
