package Node;
import IOcontrol.IO;
import LexParser.Parser;
import java.util.ArrayList;
import Token.*;

public class ConstDeclNode {
    //常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
    private Token constToken;
    private BTypeNode bTypeNode;
    private ArrayList<ConstDefNode> constDefNodes;
    private ArrayList<Token> commas;//逗号
    private Token semicnToken;//分号

    public ConstDeclNode(Token constToken, BTypeNode bTypeNode,
                         ArrayList<ConstDefNode> constDefNodes, ArrayList<Token> commas, Token semicnToken) {
        this.constToken = constToken;
        this.bTypeNode = bTypeNode;
        this.constDefNodes = constDefNodes;
        this.commas = commas;
        this.semicnToken = semicnToken;
    }

    public void print() {
        IO.ParserOutput(constToken);
        bTypeNode.print();
        for (int i = 0;i < constDefNodes.size();i++) {
            if (i >= 1) {
                IO.ParserOutput(commas.get(i - 1));
            }
            constDefNodes.get(i).print();
        }
        IO.ParserOutput(semicnToken);
        IO.ParserOutput(Parser.nodeType.get(NodeType.ConstDecl));
    }

}
