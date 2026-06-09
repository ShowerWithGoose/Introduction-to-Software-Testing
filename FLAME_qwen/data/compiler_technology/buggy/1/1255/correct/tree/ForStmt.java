package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class ForStmt {
    private LVal lVal;
    private Token equalTk;
    private Exp exp;

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setEqualTk(Token equalTk) {
        this.equalTk = equalTk;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public void output(FileWriter fileWriter) throws IOException {
        lVal.output(fileWriter);
        fileWriter.write(equalTk.toString() + "\n");
        exp.output(fileWriter);
        fileWriter.write("<ForStmt>\n");
    }
}
