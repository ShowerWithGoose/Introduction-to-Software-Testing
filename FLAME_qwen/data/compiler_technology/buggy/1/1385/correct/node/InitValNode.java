package node;


import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class InitValNode {
    //InitVal â†’ Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private ExpNode expNode;
    private Token leftBraceToken;
    private ArrayList<ExpNode> expNodes;
    private ArrayList<Token> commas;
    private Token rightBraceToken;
    private Token stringConst;

    public InitValNode(ExpNode expNode, Token leftBraceToken, ArrayList<ExpNode> expNodes, ArrayList<Token> commas, Token rightBraceToken,Token stringConst) {
        this.expNode = expNode;
        this.leftBraceToken = leftBraceToken;
        this.expNodes = expNodes;
        this.commas = commas;
        this.rightBraceToken = rightBraceToken;
        this.stringConst = stringConst;
    }
    
    public void print() throws IOException {
        if (expNode!=null) {
            expNode.print();
        }
        else if (stringConst!=null) {
            stringConst.print();
        }
        else {
            leftBraceToken.print();
            expNodes.get(0).print();
            if (!commas.isEmpty()) {
                for (int i=0;i<commas.size();i+=1){
                    commas.get(i).print();
                    expNodes.get(i+1).print();
                }
            }
            rightBraceToken.print();
        }
        Io.Text.printWord("<InitVal>");
    }
}
