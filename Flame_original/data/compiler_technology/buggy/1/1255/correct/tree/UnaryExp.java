package tree;

import token.Token;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class UnaryExp {
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    private PrimaryExp primaryExp;

    private Token identifier;
    private Token leftB;
    private ArrayList<Exp> funcRParams = new ArrayList<>();
    private Token rightB;

    public void setUnaryOp(UnaryOp unaryOp) {
        this.unaryOp = unaryOp;
    }

    public void setUnaryExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
    }

    public void setPrimaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public void setIdentifier(Token identifier) {
        this.identifier = identifier;
    }

    public void setLeftB(Token leftB) {
        this.leftB = leftB;
    }

    public void addFuncRParam(Exp funcRParam) {
        funcRParams.add(funcRParam);
    }

    public void setRightB(Token rightB) {
        this.rightB = rightB;
    }

    public void output(FileWriter fileWriter) throws IOException {
        if (unaryOp != null) {
            unaryOp.output(fileWriter);
            unaryExp.output(fileWriter);
        } else if (primaryExp != null) {
            primaryExp.output(fileWriter);
        } else if (identifier != null) {
            fileWriter.write(identifier.toString() + "\n");
            fileWriter.write(leftB.toString() + "\n");
            if (!funcRParams.isEmpty()) {
                for (int i = 0;i < funcRParams.size() - 1;i++) {
                    funcRParams.get(i).output(fileWriter);
                    fileWriter.write("COMMA ,\n");
                }
                funcRParams.get(funcRParams.size() - 1).output(fileWriter);
                fileWriter.write("<FuncRParams>\n");
            }
            fileWriter.write(rightB.toString() + "\n");
        }
        fileWriter.write("<UnaryExp>\n");
    }
}
