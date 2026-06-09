package frontend.ast;

import frontend.TokenType;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FuncFParams implements AstNode {
    private final ArrayList<FuncFParam> funcFParams;

    public FuncFParams(ArrayList<FuncFParam> funcFParams) {
        this.funcFParams = funcFParams;
    }

    @Override
    public String getSymbol() {
        return "<FuncFParams>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        funcFParams.get(0).printToFile(bw);
        for (int i = 1; i < funcFParams.size(); i++) {
            bw.write(TokenType.COMMA + " ,\n");
            funcFParams.get(i).printToFile(bw);
        }
        bw.write(getSymbol() + "\n");
    }
}
