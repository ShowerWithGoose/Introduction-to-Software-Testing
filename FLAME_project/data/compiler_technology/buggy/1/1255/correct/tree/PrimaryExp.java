package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class PrimaryExp {
    private Token leftB;
    private Exp exp;
    private Token rightB;

    private LVal lVal;

    private Token number;

    private Token character;

    public void setLeftB(Token leftB) {
        this.leftB = leftB;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public void setRightB(Token rightB) {
        this.rightB = rightB;
    }

    public void setlVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setNumber(Token number) {
        this.number = number;
    }

    public void setCharacter(Token character) {
        this.character = character;
    }

    public void output(FileWriter fileWriter) throws IOException {
        if (character != null) {
            fileWriter.write(character.toString() + "\n");
            fileWriter.write("<Character>\n");
        } else if (number != null) {
            fileWriter.write(number.toString() + "\n");
            fileWriter.write("<Number>\n");
        } else if (lVal != null) {
            lVal.output(fileWriter);
        } else {
            fileWriter.write(leftB.toString() + "\n");
            exp.output(fileWriter);
            fileWriter.write(rightB.toString() + "\n");
        }
        fileWriter.write("<PrimaryExp>\n");
    }
}
