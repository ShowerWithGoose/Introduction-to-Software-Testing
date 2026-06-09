package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class VarDefNode {
    // Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal

    private Token ident;
    private Token lToken;
    private Token rToken;
    private ConstExpNode constExpNode;
    private Token assign;
    private InitValNode initValNode;
    public VarDefNode(Token ident, Token lbrackToken, ConstExpNode constExpNode, Token rbrackToken, Token equalToken, InitValNode initValNode){
        this.ident = ident;
        this.lToken = lbrackToken;
        this.constExpNode = constExpNode;
        this.rToken = rbrackToken;
        this.assign = equalToken;
        this.initValNode = initValNode;
    }
    public void print(){
        ident.print();
        if(lToken != null){
            lToken.print();
            constExpNode.print();
            rToken.print();
        }
        if(assign != null){
            assign.print();
            initValNode.print();    
        }
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<VarDef>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
