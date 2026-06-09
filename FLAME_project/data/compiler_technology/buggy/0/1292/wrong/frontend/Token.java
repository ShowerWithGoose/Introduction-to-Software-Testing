package frontend;

import frontend.LexType;

import java.io.FileWriter;
import java.io.IOException;

public class Token {
    private String token;
    private int lineNum;
    private LexType type;

    public Token(String token, int lineNum, LexType type) {
        this.token = token;
        this.lineNum = lineNum;
        this.type = type;
    }

    public void printOut() {
        try {
            FileWriter fileWriter = new FileWriter("lexer.txt", true);
            fileWriter.write(type + " " + token + "\n");
            fileWriter.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
