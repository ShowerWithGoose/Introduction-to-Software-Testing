package frontend.node;

import frontend.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ConstDeclNode {
    private Token constToken;
    private BTypeNode bTypeNode;
    private List<ConstDefNode> constDefNodes;
    private List<Token> commas;
    private Token semicaToken;
    public ConstDeclNode(Token constToken, BTypeNode bTypeNode, List<ConstDefNode> constDefNodes, List<Token> commas, Token semicaToken){
        this.constToken = constToken;
        this.bTypeNode = bTypeNode;
        this.constDefNodes = constDefNodes;
        this.commas = commas;
        this.semicaToken = semicaToken;
    }
    public void print(){
        constToken.print();
        bTypeNode.print();
        constDefNodes.get(0).print();
        for (int i = 1; i < constDefNodes.size(); i++) {
            commas.get(i - 1).print();
            constDefNodes.get(i).print();
        }
        semicaToken.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<ConstDecl>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
