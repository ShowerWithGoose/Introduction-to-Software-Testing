package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class RelExp {
    private AddExp addExp;
    private RelExp relExp;
    private Token sign;

    public void setAddExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public void setRelExp(RelExp relExp) {
        this.relExp = relExp;
    }

    public void setSign(Token sign) {
        this.sign = sign;
    }

    public void output(FileWriter fileWriter) throws IOException {
        addExp.output(fileWriter);
        fileWriter.write("<RelExp>\n");
        if (sign != null) {
            fileWriter.write(sign.toString() + "\n");
            relExp.output(fileWriter);
        }
    }
}
