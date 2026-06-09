package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class BType {
    private Token typeToken;

    public void setTypeToken(Token typeToken) {
        this.typeToken = typeToken;
    }

    public void output(FileWriter fileWriter) throws IOException {
        fileWriter.write(typeToken.toString() + "\n");
    }
}
