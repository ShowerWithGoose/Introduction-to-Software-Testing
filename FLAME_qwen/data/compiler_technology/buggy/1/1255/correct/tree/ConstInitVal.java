package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ConstInitVal {
    private Token leftB;
    private ArrayList<ConstExp> constExps = new ArrayList<>();
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

    public void addConstExp(ConstExp constExp) {
        constExps.add(constExp);
    }

    public void output(FileWriter fileWriter) throws IOException {
        if (leftB == null && stringConst == null) {
            constExps.get(0).output(fileWriter);
        } else if (stringConst != null) {
            stringConst.output(fileWriter);
        } else {
            fileWriter.write(leftB.toString() + "\n");
            if (!constExps.isEmpty()) {
                for (int i = 0; i < constExps.size() - 1; i++) {
                    constExps.get(i).output(fileWriter);
                    fileWriter.write("COMMA ,\n");
                }
                constExps.get(constExps.size() - 1).output(fileWriter);
            }
            fileWriter.write(rightB.toString() + "\n");
        }
        fileWriter.write("<ConstInitVal>\n");
    }
}
