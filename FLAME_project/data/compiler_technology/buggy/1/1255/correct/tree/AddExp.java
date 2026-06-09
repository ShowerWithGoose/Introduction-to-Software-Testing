package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class AddExp {
    private MulExp mulExp;
    private AddExp addExp;
    private Token sign;

    public void setMulExp(MulExp mulExp) {
        this.mulExp = mulExp;
    }

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public void setSign(Token sign) {
        this.sign = sign;
    }

    public void output(FileWriter fileWriter) throws IOException {
        mulExp.output(fileWriter);
        fileWriter.write("<AddExp>\n");
        if (sign != null) {
            fileWriter.write(sign.toString() + "\n");
            addExp.output(fileWriter);
        }
    }
}
