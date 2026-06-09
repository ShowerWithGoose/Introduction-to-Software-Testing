package frontend;

import java.io.FileWriter;
import java.io.IOException;

public class Token {
    private TokenType type;
    private  String word;
    private long value;

    private int lineNum;

    public Token(TokenType type,String word,long value,int lineNum) {
        this.type = type;
        this.word = word;
        this.value = value;
        this.lineNum = lineNum;
    }
    public TokenType getType() {
        return type;
    }
    public String getWord() {
        return word;
    }
    public long getValue() {
        return value;
    }
    public int getLineNum() {return lineNum;}

    public void print(FileWriter stdWriter) throws IOException {
        stdWriter.write(String.format("%s %s\n",type.toString(), word, lineNum));
    }
}
