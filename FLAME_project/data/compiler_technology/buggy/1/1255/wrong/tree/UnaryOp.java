package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class UnaryOp {
    private Token sign;

    public void setSign(Token sign) {
        this.sign = sign;
    }

    public void output(FileWriter fileWriter) throws IOException {
        fileWriter.write(sign.toString() + "\n");
        fileWriter.write("<UnaryOp>\n");
    }
}
