package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class ConstDefNode {
    private Token ident;
    private Token lToken;
    private ConstExpNode constExpNode;
    private Token rbrackToken;
    private Token equalToken;
    private ConstInitValNode constInitValNode;
    public ConstDefNode(Token ident, Token lbrackToken, ConstExpNode constExpNode, Token rbrackToken, Token equalToken, ConstInitValNode constInitValNode){
        this.ident = ident;
        this.lToken = lbrackToken;
        this.constExpNode = constExpNode;
        this.rbrackToken = rbrackToken;
        this.equalToken = equalToken;
        this.constInitValNode = constInitValNode;
    }
    public void print(){
        ident.print();
        if(lToken != null){
            lToken.print();
            constExpNode.print();
            rbrackToken.print();
        }
        equalToken.print();
        constInitValNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<ConstDef>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
