package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;
public class LAndExp {
    private EqExp eqExp;
    private LAndExp lAndExp;
    private Token and;

    public void setEqExp(EqExp eqExp) {
        this.eqExp = eqExp;
    }

    public void setlAndExp(LAndExp lAndExp) {
        this.lAndExp = lAndExp;
    }

    public void setAnd(Token and) {
        this.and = and;
    }

    public void output(FileWriter fileWriter) throws IOException {
        eqExp.output(fileWriter);
        fileWriter.write("<LAndExp>\n");
        if (and != null) {
            fileWriter.write(and.toString() + "\n");
            lAndExp.output(fileWriter);
        }
    }
}
