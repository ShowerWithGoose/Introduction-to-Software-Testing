package Node;

import IOcontrol.IO;
import LexParser.Parser;
import Token.Token;

import java.util.ArrayList;

public class VarDeclNode {
    //变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // i
    private BTypeNode bTypeNode;
    private ArrayList<VarDefNode> varDefNodes;
    private ArrayList<Token> commas;
    private Token semicn;

    public VarDeclNode(BTypeNode bTypeNode, ArrayList<VarDefNode> varDefNodes,
                       ArrayList<Token> commas, Token semicn) {
        this.bTypeNode = bTypeNode;
        this.varDefNodes = varDefNodes;
        this.commas = commas;
        this.semicn = semicn;
    }


    public void print() {
        bTypeNode.print();
        varDefNodes.get(0).print();
        for (int i = 1; i < varDefNodes.size(); i++) {
            IO.ParserOutput(commas.get(i - 1));
            varDefNodes.get(i).print();
        }
        IO.ParserOutput(semicn);
        IO.ParserOutput(Parser.nodeType.get(NodeType.VarDecl));
    }
}
