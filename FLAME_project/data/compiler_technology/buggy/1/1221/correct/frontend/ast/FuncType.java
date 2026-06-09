package frontend.ast;

import frontend.Token;

import java.io.BufferedWriter;
import java.io.IOException;

public class FuncType implements AstNode {
    private final Token type;

    public FuncType(Token type) {
        this.type = type;
    }

    @Override
    public String getSymbol() {
        return "<FuncType>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        bw.write(type + "\n");
        bw.write(getSymbol() + "\n");
    }
}
