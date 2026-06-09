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

    public LexType getType() {
        return type;
    }

    public int getLineNum() {
        return lineNum;
    }

    public void printOut() {
        try {
            FileWriter fileWriter = new FileWriter("parser.txt", true);
            fileWriter.write(type + " " + token + "\n");
            fileWriter.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
