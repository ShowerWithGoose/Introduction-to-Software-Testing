package frontend.ast;

import frontend.Token;

import java.io.BufferedWriter;
import java.io.IOException;

public class Character implements AstNode {
    private final Token charConst;

    public Character(Token charConst) {
        this.charConst = charConst;
    }

    @Override
    public String getSymbol() {
        return "<Character>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        bw.write(charConst + "\n");
        bw.write(getSymbol() + "\n");
    }
}
