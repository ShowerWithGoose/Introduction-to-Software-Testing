package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class EqExp {
    private RelExp relExp;
    private EqExp eqExp;
    private Token sign;

    public void setRelExp(RelExp relExp) {
        this.relExp = relExp;
    }

    public void setEqExp(EqExp eqExp) {
        this.eqExp = eqExp;
    }

    public void setSign(Token sign) {
        this.sign = sign;
    }

    public void output(FileWriter fileWriter) throws IOException {
        relExp.output(fileWriter);
        fileWriter.write("<EqExp>\n");
        if (sign != null) {
            fileWriter.write(sign.toString() + "\n");
            eqExp.output(fileWriter);
        }
    }
}
