package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class StringConst {
    private Token string;

    public void setString(Token string) {
        this.string = string;
    }

    public void output(FileWriter fileWriter) throws IOException {
        fileWriter.write(string.toString() + "\n");
    }
}
