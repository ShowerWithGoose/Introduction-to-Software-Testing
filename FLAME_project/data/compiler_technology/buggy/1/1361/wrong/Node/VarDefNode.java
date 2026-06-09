package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

import java.util.ArrayList;

public class VarDefNode {
    //变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
    private Token ident;
    private Token leftBracket;
    private ConstExpNode constExpNode;
    private Token rightBracket;
    private Token assign;
    private InitValNode initValNode;

    public VarDefNode(Token ident,Token leftBracket, ConstExpNode constExpNode,
                      Token rightBracket, Token assign, InitValNode initValNode) {
        this.ident = ident;
        this.leftBracket = leftBracket;
        this.constExpNode = constExpNode;
        this.rightBracket = rightBracket;
        this.assign = assign;
        this.initValNode = initValNode;
    }

    public void print() {
        IO.ParserOutput(ident);
        if (leftBracket != null) {
            IO.ParserOutput(leftBracket);
            constExpNode.print();
            IO.ParserOutput(rightBracket);
        }
        if (initValNode != null) {
            IO.ParserOutput(assign);
            initValNode.print();
        }
        IO.ParserOutput(Parser.nodeType.get(NodeType.VarDef));
    }
}
