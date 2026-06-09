package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class NumberNode {
    Token token;
    public NumberNode(Token token) {
        this.token = token;
    }
    public void print() {
        token.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<Number>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
