package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ConstInitValNode {
    // ConstInitVal â†’ ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private ConstExpNode constExpNode;
    private Token leftBraceToken;
    private ArrayList<ConstExpNode> constExpNodes;
    private ArrayList<Token> commas;
    private Token rightBraceToken;
    private Token stringConst;

    public ConstInitValNode(ConstExpNode constExpNode, Token leftBraceToken, ArrayList<ConstExpNode> constExpNodes, ArrayList<Token> commas, Token rightBraceToken,Token stringConst) {
        this.constExpNode = constExpNode;
        this.leftBraceToken = leftBraceToken;
        this.constExpNodes = constExpNodes;
        this.commas = commas;
        this.rightBraceToken = rightBraceToken;
        this.stringConst = stringConst;
    }
    
    public void print() throws IOException {
        if (constExpNode!=null) {
            constExpNode.print();
        }
        else if (stringConst!=null) {
            stringConst.print();
        }
        else {
            leftBraceToken.print();
            if (!constExpNodes.isEmpty()) {
                constExpNodes.get(0).print();
                for (int i = 0;i<commas.size();i+=1){
                    commas.get(i).print();
                    constExpNodes.get(i+1).print();
                }
            }
            rightBraceToken.print();
        }
        Io.Text.printWord("<ConstInitVal>");
    }

}
