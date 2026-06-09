package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

import java.util.ArrayList;

public class FuncFParamsNode {
    //函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
    private ArrayList<FuncFParamNode> funcFParamNodes;
    private ArrayList<Token> commas;

    public FuncFParamsNode(ArrayList<FuncFParamNode> funcFParamNodes, ArrayList<Token> commas) {
        this.funcFParamNodes = funcFParamNodes;
        this.commas = commas;
    }

    public void print() {
        funcFParamNodes.get(0).print();
        for (int i = 1; i < funcFParamNodes.size(); i++) {
            IO.ParserOutput(commas.get(i - 1));
            funcFParamNodes.get(i).print();
        }
        IO.ParserOutput(Parser.nodeType.get(NodeType.FuncFParams));
    }
}
