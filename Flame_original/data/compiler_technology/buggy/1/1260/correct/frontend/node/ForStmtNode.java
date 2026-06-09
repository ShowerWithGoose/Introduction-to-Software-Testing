package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class ForStmtNode {
    private LValNode lValNode;
    private Token eqToken;
    private ExpNode expNode;
    public ForStmtNode(LValNode lValNode, Token equalToken, ExpNode expNode){
        this.lValNode = lValNode;
        this.eqToken = equalToken;
        this.expNode = expNode;
    }
    public void print(){
        lValNode.print();
        eqToken.print();
        expNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<ForStmt>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
