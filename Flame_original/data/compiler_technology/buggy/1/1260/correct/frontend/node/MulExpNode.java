package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class MulExpNode {
    private UnaryExpNode unaryExpNode;
    private Token opToken;
    private MulExpNode mulExpNode;
    public MulExpNode(UnaryExpNode unaryExpNode, Token opToken, MulExpNode mulExpNode){
        this.unaryExpNode = unaryExpNode;
        this.opToken = opToken;
        this.mulExpNode = mulExpNode;
    }
    public void print() {
        unaryExpNode.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<MulExp>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
        if (opToken != null) {
            opToken.print();
            mulExpNode.print();
        }
    }

}
