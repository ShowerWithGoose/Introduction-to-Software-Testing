package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;

public class MainFuncDef {
    private Token intTk;
    private Token mainTk;
    private Token leftB;
    private Token rightB;
    private Block block;

    public void setIntTk(Token intTk) {
        this.intTk = intTk;
    }

    public void setMain(Token mainTk) {
        this.mainTk = mainTk;
    }

    public void setLeftB(Token leftB) {
        this.leftB = leftB;
    }

    public void setRightB(Token rightB) {
        this.rightB = rightB;
    }

    public void setBlock(Block block) {
        this.block = block;
    }

    public void output(FileWriter fileWriter) throws IOException {
        fileWriter.write(intTk.toString() + "\n");
        fileWriter.write(mainTk.toString() + "\n");
        fileWriter.write(leftB.toString() + "\n");
        fileWriter.write(rightB.toString() + "\n");
        block.output(fileWriter);
        fileWriter.write("<MainFuncDef>\n");
    }
}
