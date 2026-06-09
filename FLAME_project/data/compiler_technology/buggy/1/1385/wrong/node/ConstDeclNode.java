package node;
import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ConstDeclNode {
    // ConstDecl -> 'const' BType ConstDef { ',' ConstDef } ';'
    private Token constToken;
    private BTypeNode bTypeNode;
    private ArrayList<ConstDefNode> constDefNodes;
    private ArrayList<Token> commas;
    private Token semicnToken;

    public ConstDeclNode(Token constToken, BTypeNode bTypeNode, ArrayList<ConstDefNode> constDefNodes, ArrayList<Token> commas, Token semicnToken) {
        this.constToken = constToken;
        this.bTypeNode = bTypeNode;
        this.constDefNodes = constDefNodes;
        this.commas = commas;
        this.semicnToken = semicnToken;
    }
    
    public void print() throws IOException {
        constToken.print();
        bTypeNode.print();
        if (constDefNodes.size()==1) {
            constDefNodes.get(0).print();
        }
        else {
            for (int i = 0;i<constDefNodes.size()-1;i+=1) {
                constDefNodes.get(i).print();
                commas.get(i).print();
            }
            constDefNodes.get(constDefNodes.size()-1).print();
        }
        semicnToken.print();
        Io.Text.printWord("<ConstDecl>");
    }
    
}
