package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class VarDef {
    private Token identifier;
    private Token leftB;
    private ConstExp constExp;
    private Token rightB;
    private Token equalTk;
    private InitVal initVal;

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

    public void setEqualTk(Token equalTk) {
        this.equalTk = equalTk;
    }

    public void setInitVal(InitVal initVal) {
        this.initVal = initVal;
    }

    public void output(FileWriter fileWriter) throws IOException {
        fileWriter.write(identifier.toString() + "\n");
        if (leftB != null) {
            fileWriter.write(leftB.toString() + "\n");
            constExp.output(fileWriter);
            fileWriter.write(rightB.toString() + "\n");
        }
        if (equalTk != null) {
            fileWriter.write(equalTk.toString() + "\n");
            initVal.output(fileWriter);
        }
        fileWriter.write("<VarDef>\n");
    }
}
