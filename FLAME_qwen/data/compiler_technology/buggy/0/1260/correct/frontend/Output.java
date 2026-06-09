package frontend;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Output {
    ArrayList<Token> tokenList;
    public Output(ArrayList<Token> tokenList) throws IOException {
        this.tokenList = tokenList;
        try (FileWriter fw = new FileWriter("lexer.txt")){
            for (Token token : tokenList) {
                fw.write(token.getType() + " " + token.getContent() + "\n");
            }
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
