package frontend;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Output {
    ArrayList<Token> tokenList = new ArrayList<>();
    public Output(ArrayList<Token> tokenList) {
        this.tokenList = tokenList;
        try (FileWriter writer = new FileWriter("lexer.txt")) {
            for (Token token : tokenList) {
                writer.write(token.getType() + " " + token.getContent() + "\n");
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}
