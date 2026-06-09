package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class MulExp {
    private UnaryExp unaryExp;
    private MulExp mulExp;
    private Token sign;

    public void setUnaryExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
    }

    public void setMulExp(MulExp mulExp) {
        this.mulExp = mulExp;
    }

    public void setSign(Token sign) {
        this.sign = sign;
    }

    public void output(FileWriter fileWriter) throws IOException {
        unaryExp.output(fileWriter);
        fileWriter.write("<MulExp>\n");
        if (sign != null) {
            fileWriter.write(sign.toString() + "\n");
            mulExp.output(fileWriter);
        }
    }
}
