package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FuncDef {
    private FuncType funcType;
    private Token identifier;
    private Token leftB;
    private ArrayList<FuncFParam> funcFParams = new ArrayList<>();
    private Token rightB;
    private Block block;

    public void setFuncType(FuncType funcType) {
        this.funcType = funcType;
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

    public void setBlock(Block block) {
        this.block = block;
    }

    public void addFuncFPram(FuncFParam funcFParam) {
        funcFParams.add(funcFParam);
    }

    public void output(FileWriter fileWriter) throws IOException {
        funcType.output(fileWriter);
        fileWriter.write(identifier.toString() + "\n");
        fileWriter.write(leftB.toString() + "\n");
        if (!funcFParams.isEmpty()) {
            for (int i = 0;i < funcFParams.size() - 1;i++) {
                funcFParams.get(i).output(fileWriter);
                fileWriter.write("COMMA ,\n");
            }
            funcFParams.get(funcFParams.size() - 1).output(fileWriter);
            fileWriter.write("<FuncFParams>\n");
        }
        fileWriter.write(rightB.toString() + "\n");
        block.output(fileWriter);
        fileWriter.write("<FuncDef>\n");
    }
}
