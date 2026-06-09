package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

import java.util.ArrayList;

public class FuncRParamsNode {
    //函数实参表 FuncRParams → Exp { ',' Exp }
    private ArrayList<ExpNode> expNodes;
    private ArrayList<Token> commas;

    public FuncRParamsNode(ArrayList<ExpNode> expNodes, ArrayList<Token> commas) {
        this.expNodes = expNodes;
        this.commas = commas;
    }

    public void print() {
        expNodes.get(0).print();
        for (int i = 1; i < expNodes.size(); i++) {
            IO.ParserOutput(commas.get(i - 1));
            expNodes.get(i).print();
        }
        IO.ParserOutput(Parser.nodeType.get(NodeType.FuncRParams));
    }
}
