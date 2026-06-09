package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class VarDeclNode {
    // VarDecl -> BType VarDef { ',' VarDef } ';'
    private BTypeNode bTypeNode;
    private ArrayList<VarDefNode> varDefNodes;
    private ArrayList<Token> commas;
    private Token semicn;

    public VarDeclNode(BTypeNode bTypeNode, ArrayList<VarDefNode> varDefNodes, ArrayList<Token> commas, Token semicn) {
        this.bTypeNode = bTypeNode;
        this.varDefNodes = varDefNodes;
        this.commas = commas;
        this.semicn = semicn;
    }
    
    public void print() throws IOException {
        bTypeNode.print();
        varDefNodes.get(0).print();
        if (!commas.isEmpty()){
            for (int i=0;i<commas.size();i+=1){
                commas.get(i).print();
                varDefNodes.get(i+1).print();
            }
        }
        semicn.print();
        Io.Text.printWord("<VarDecl>");
    }
}
