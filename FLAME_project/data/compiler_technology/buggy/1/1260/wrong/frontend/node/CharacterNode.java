package frontend.node;

import java.io.FileWriter;
import java.io.IOException;

import frontend.Token;

public class CharacterNode {
    private Token chrConToken;
    public CharacterNode(Token chrConToken){
        this.chrConToken = chrConToken;
    }
    public void print(){
        chrConToken.print();
        try (FileWriter fw = new FileWriter("parser.txt", true)){
            fw.write("<Character>\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
