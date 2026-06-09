package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class LVal {
    private int dimension;
    private Token identifier;
    private Token leftB;
    private Exp exp;
    private Token rightB;

    public void setDimension(int dimension) {
        this.dimension = dimension;
    }

    public void setIdentifier(Token identifier) {
        this.identifier = identifier;
    }

    public void setLeftB(Token leftB) {
        this.leftB = leftB;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }

    public void setRightB(Token rightB) {
        this.rightB = rightB;
    }

    public void output(FileWriter fileWriter) throws IOException {
        fileWriter.write(identifier.toString() + "\n");
        if (dimension == 1) {
            fileWriter.write(leftB.toString() + "\n");
            exp.output(fileWriter);
            fileWriter.write(rightB.toString() + "\n");
        }
        fileWriter.write("<LVal>\n");
    }
}
