package frontend.ast;

import frontend.Token;
import frontend.TokenType;

import java.io.BufferedWriter;
import java.io.IOException;

public class FuncDef implements AstNode {
    private final FuncType funcType;
    private final Token ident;
    private final FuncFParams funcFParams;
    private final Block block;

    public FuncDef(FuncType type, Token ident, FuncFParams funcFParams, Block block) {
        funcType = type;
        this.ident = ident;
        this.funcFParams = funcFParams;
        this.block = block;
    }

    public FuncDef(FuncType type, Token ident, Block block) {
        funcType = type;
        this.ident = ident;
        this.funcFParams = null;
        this.block = block;
    }

    @Override
    public String getSymbol() {
        return "<FuncDef>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        funcType.printToFile(bw);
        bw.write(ident + "\n");
        bw.write(TokenType.LPARENT + " (\n");
        if (funcFParams != null) {
            funcFParams.printToFile(bw);
        }
        bw.write(TokenType.RPARENT + " )\n");
        block.printToFile(bw);
        bw.write(getSymbol() + "\n");
    }
}
