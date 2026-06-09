package frontend.node;

import frontend.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class VarDeclNode {
    private BTypeNode bTypeNode;
    private List<Token> commas;
    private List<VarDefNode> varDefNodes;
    private Token semicnToken;

    public VarDeclNode(BTypeNode bTypeNode, List<Token> commas, List<VarDefNode> varDefNodes, Token semicnToken){
        this.bTypeNode = bTypeNode;
        this.commas = commas;
        this.varDefNodes = varDefNodes;
        this.semicnToken = semicnToken;
    }
    public void print(){
        bTypeNode.print();
        varDefNodes.get(0).print();
        for(int i=1;i<varDefNodes.size();++i){
            commas.get(i-1).print();
            varDefNodes.get(i).print();
        }
        semicnToken.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<VarDecl>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
