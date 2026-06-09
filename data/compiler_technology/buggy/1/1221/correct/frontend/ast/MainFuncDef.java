package frontend.ast;

import frontend.TokenType;

import java.io.BufferedWriter;
import java.io.IOException;

public class MainFuncDef implements AstNode {
    private final Block block;

    public MainFuncDef(Block block) {
        this.block = block;
    }

    @Override
    public String getSymbol() {
        return "<MainFuncDef>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        bw.write(TokenType.INTTK + " int\n");
        bw.write(TokenType.MAINTK + " main\n");
        bw.write(TokenType.LPARENT + " (\n");
        bw.write(TokenType.RPARENT + " )\n");
        block.printToFile(bw);
        bw.write(getSymbol() + "\n");
    }
}
