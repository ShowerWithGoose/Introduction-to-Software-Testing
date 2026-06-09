package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class InitVal {
    private Token leftB;
    private ArrayList<Exp> exps = new ArrayList<>();
    private Token rightB;
    private StringConst stringConst;

    public void setLeftB(Token leftB) {
        this.leftB = leftB;
    }

    public void setRightB(Token rightB) {
        this.rightB = rightB;
    }

    public void setStringConst(StringConst stringConst) {
        this.stringConst = stringConst;
    }

    public void addExp(Exp exp) {
        exps.add(exp);
    }

    public void output(FileWriter fileWriter) throws IOException {
        if (leftB == null && stringConst == null) {
            exps.get(0).output(fileWriter);
        } else if (stringConst != null) {
            stringConst.output(fileWriter);
        } else {
            fileWriter.write(leftB.toString() + "\n");
            if (!exps.isEmpty()) {
                for (int i = 0; i < exps.size() - 1; i++) {
                    exps.get(i).output(fileWriter);
                    fileWriter.write("COMMA ,\n");
                }
                exps.get(exps.size() - 1).output(fileWriter);
            }
            fileWriter.write(rightB.toString() + "\n");
        }
        fileWriter.write("<InitVal>\n");
    }
}
