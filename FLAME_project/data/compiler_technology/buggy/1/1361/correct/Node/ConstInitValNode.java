package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

import java.lang.reflect.Array;
import java.util.ArrayList;

public class ConstInitValNode {
    //常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private Token leftBraceToken;
    private ArrayList<ConstExpNode> constExpNodes;
    private ArrayList<Token> commas;
    private Token rightBraceToken;
    private Token stringConst;

    public ConstInitValNode(Token leftBraceToken, ArrayList<ConstExpNode> constExpNodes,
                            ArrayList<Token> commas, Token rightBraceToken, Token stringConst) {
        this.leftBraceToken = leftBraceToken;
        this.constExpNodes = constExpNodes;
        this.commas = commas;
        this.rightBraceToken = rightBraceToken;
        this.stringConst = stringConst;
    }

    public void print() {
        if (stringConst != null) {
            IO.ParserOutput(stringConst);
        }
        else if (leftBraceToken == null) {
            constExpNodes.get(0).print();
        }
        else {
            IO.ParserOutput(leftBraceToken);
            if (constExpNodes.size() > 0) {
                constExpNodes.get(0).print();
                for (int i = 1; i < constExpNodes.size(); i++) {
                    IO.ParserOutput(commas.get(i - 1));
                    constExpNodes.get(i).print();
                }
            }
            IO.ParserOutput(rightBraceToken);
        }
        IO.ParserOutput(Parser.nodeType.get(NodeType.ConstInitVal));
    }
}
