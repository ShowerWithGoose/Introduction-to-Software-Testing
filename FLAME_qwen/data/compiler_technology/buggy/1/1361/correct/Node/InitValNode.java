package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

import java.util.ArrayList;

public class InitValNode {
    //变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private Token leftBraceToken;
    private ArrayList<ExpNode> expNodes;
    private ArrayList<Token> commas;
    private Token rightBraceToken;
    private Token stringConst;

    public InitValNode(Token leftBraceToken, ArrayList<ExpNode> expNodes,
                       ArrayList<Token> commas, Token rightBraceToken,Token stringConst) {
        this.leftBraceToken = leftBraceToken;
        this.expNodes = expNodes;
        this.commas = commas;
        this.rightBraceToken = rightBraceToken;
        this.stringConst = stringConst;
    }

    public void print() {
        if (stringConst != null) {
            IO.ParserOutput(stringConst);
        }
        // leftBracket 为空代表是第一种情况
        else if (leftBraceToken == null) {
            expNodes.get(0).print();
        }
        else {
            IO.ParserOutput(leftBraceToken);
            if (expNodes.size() > 0) {
                for (int i = 0;i < expNodes.size();i++) {
                    expNodes.get(i).print();
                    if (i < expNodes.size() - 1) {
                        IO.ParserOutput(commas.get(i));
                    }
                }
            }
            IO.ParserOutput(rightBraceToken);
        }
        IO.ParserOutput(Parser.nodeType.get(NodeType.InitVal));
    }
}
