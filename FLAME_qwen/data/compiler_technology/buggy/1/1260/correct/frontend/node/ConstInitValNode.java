package frontend.node;

import frontend.Lexer;
import frontend.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
// ConstInitVal â†’ ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
public class ConstInitValNode {
    private ConstExpNode constExpNode;
    private Token leftBraceToken;
    private List<ConstExpNode> constExpNodes;
    private List<Token> commas;
    private Token rightBraceToken;
    private Token strToken;
    public ConstInitValNode(ConstExpNode constExpNode, Token lBraceToken, List<ConstExpNode> constExpNodes, List<Token> commas, Token rBraceToken, Token strconToken){
        this.constExpNode = constExpNode;
        this.leftBraceToken = lBraceToken;
        this.constExpNodes = constExpNodes;
        this.commas = commas;
        this.rightBraceToken = rBraceToken;
        this.strToken = strconToken;
    }
    public void print() {
        if (constExpNode != null) {
            constExpNode.print();
        } else if(strToken != null){
            strToken.print();
        } else{
            leftBraceToken.print();
            if (!constExpNodes.isEmpty()) {
                constExpNodes.get(0).print();
                for (int i = 1; i < constExpNodes.size(); i++) {
                    commas.get(i-1).print();
                    constExpNodes.get(i).print();
                }
            }
            rightBraceToken.print();
        }
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<ConstInitVal>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }

}
