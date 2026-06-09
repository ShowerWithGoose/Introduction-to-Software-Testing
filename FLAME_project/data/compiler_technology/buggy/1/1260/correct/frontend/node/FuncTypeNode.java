package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class FuncTypeNode {
    private Token token;

    public FuncTypeNode(Token token) {
        this.token = token;
    }
    public void print() {
        token.print();
       try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<FuncType>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
