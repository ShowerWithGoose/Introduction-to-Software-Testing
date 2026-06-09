package frontend.ast;

import frontend.Token;

import java.io.BufferedWriter;
import java.io.IOException;

public class Number implements AstNode {
    private final Token intConst;

    public Number(Token intConst) {
        this.intConst = intConst;
    }

    @Override
    public String getSymbol() {
        return "<Number>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        bw.write(intConst + "\n");
        bw.write(getSymbol() + "\n");
    }

    @Override
    public String toString() {
        return intConst.toString();
    }
}
