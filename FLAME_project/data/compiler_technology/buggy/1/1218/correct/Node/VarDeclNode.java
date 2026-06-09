package Node;

import Token.Token;
import frontend.Parser;

import java.util.ArrayList;

public class VarDeclNode {
    // VarDecl â†’ BType VarDef { ',' VarDef } ';'
    private BTypeNode bTypeNode;
    private ArrayList<VarDefNode> varDefNodes;
    Token semicnToken;
    ArrayList<Token> commas;
    public VarDeclNode(BTypeNode bTypeNode, ArrayList<VarDefNode> varDefNodes, ArrayList<Token> commas, Token semicnToken){
        this.commas = commas;
        this.semicnToken = semicnToken;
        this.bTypeNode = bTypeNode;
        this.varDefNodes = varDefNodes;
    }

    public void print(){
        bTypeNode.print();
        varDefNodes.get(0).print();
        for(int i = 1; i < varDefNodes.size(); i++){
            Parser.getInstance().output(commas.get(i - 1));
            varDefNodes.get(i).print();
        }
        Parser.getInstance().output(semicnToken);
        Parser.getInstance().output(NodeType.VarDecl);
    }

}
