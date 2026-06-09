package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class FuncFParam {
    private int dimension;
    private BType bType;
    private Token identifier;
    private Token leftB;
    private Token rightB;

    public void setDimension(int dimension) {
        this.dimension = dimension;
    }

    public void setbType(BType bType) {
        this.bType = bType;
    }

    public void setIdentifier(Token identifier) {
        this.identifier = identifier;
    }

    public void setLeftB(Token leftB) {
        this.leftB = leftB;
    }


    public void setRightB(Token rightB) {
        this.rightB = rightB;
    }

    public void output(FileWriter fileWriter) throws IOException {
        bType.output(fileWriter);
        fileWriter.write(identifier.toString() + "\n");
        if (dimension == 1) {
            fileWriter.write(leftB.toString() + "\n");
            fileWriter.write(rightB.toString() + "\n");
        }
        fileWriter.write("<FuncFParam>\n");
    }
}
