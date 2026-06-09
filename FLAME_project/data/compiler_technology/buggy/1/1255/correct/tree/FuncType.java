package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class FuncType {
    private Token type;

    public void setType(Token type) {
        this.type = type;
    }

    public void output(FileWriter fileWriter) throws IOException {
        fileWriter.write(type.toString() + "\n");
        fileWriter.write("<FuncType>\n");
    }
}
