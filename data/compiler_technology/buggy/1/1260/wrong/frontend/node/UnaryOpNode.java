package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class UnaryOpNode {
    Token token;

    public UnaryOpNode(Token token) {
        this.token = token;
    }
    public void print() {
        token.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<UnaryOp>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
