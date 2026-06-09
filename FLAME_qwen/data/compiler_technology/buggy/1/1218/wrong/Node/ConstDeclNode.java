package Node;

import frontend.Parser;

import java.util.ArrayList;

import Token.*;
public class ConstDeclNode {
    // ConstDecl â†’ 'const' BType ConstDef { ',' ConstDef } ';'
    private BTypeNode bTypeNode;
    private ArrayList<ConstDefNode> constDefNodes;
    Token constToken;
    ArrayList<Token> commas;
    Token semicnToken;
    public ConstDeclNode(Token constToken, BTypeNode bTypeNode, ArrayList<ConstDefNode> constDefNodes, ArrayList<Token> commas, Token semicnToken){
        this.constToken = constToken;
        this.bTypeNode = bTypeNode;
        this.constDefNodes = constDefNodes;
        this.commas = commas;
        this.semicnToken = semicnToken;
    }

    public void print(){
        Parser.getInstance().output(constToken);
        bTypeNode.print();
        constDefNodes.get(0).print();
        for(int i = 1; i < constDefNodes.size(); i++){
            Parser.getInstance().output(commas.get(i - 1));
            constDefNodes.get(i).print();
        }
        Parser.getInstance().output(semicnToken);
        Parser.getInstance().output(NodeType.ConstDecl);
    }
}
