package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class ConstDef {
    private Token identifier;
    private Token leftB;
    private ConstExp constExp;
    private Token rightB;
    private Token eqTk;
    private ConstInitVal constInitVal;

    public void setIdentifier(Token identifier) {
        this.identifier = identifier;
    }

    public void setLeftB(Token leftB) {
        this.leftB = leftB;
    }

    public void setConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void setRightB(Token rightB) {
        this.rightB = rightB;
    }

    public void setEqTk(Token eqTk) {
        this.eqTk = eqTk;
    }

    public void setConstInitVal(ConstInitVal constInitVal) {
        this.constInitVal = constInitVal;
    }

    public void output(FileWriter fileWriter) throws IOException {
        fileWriter.write(identifier.toString() + "\n");
        if (leftB != null) {
            fileWriter.write(leftB.toString() + "\n");
            constExp.output(fileWriter);
            fileWriter.write(rightB.toString() + "\n");
        }
        fileWriter.write(eqTk.toString() + "\n");
        constInitVal.output(fileWriter);
        fileWriter.write("<ConstDef>\n");
    }
}
