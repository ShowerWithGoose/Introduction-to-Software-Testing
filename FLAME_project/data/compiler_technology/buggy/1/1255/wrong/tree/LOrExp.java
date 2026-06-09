package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class LOrExp {
    private LAndExp lAndExp;
    private LOrExp lOrExp;
    private Token or;

    public void setlAndExp(LAndExp lAndExp) {
        this.lAndExp = lAndExp;
    }

    public void setlOrExp(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    public void setOr(Token or) {
        this.or = or;
    }

    public void output(FileWriter fileWriter) throws IOException {
        lAndExp.output(fileWriter);
        fileWriter.write("<LOrExp>\n");
        if (or != null) {
            fileWriter.write(or.toString() + "\n");
            lOrExp.output(fileWriter);
        }
    }
}
