package frontend.ast;

import frontend.TokenType;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Block implements AstNode {
    private final ArrayList<AstNode> blockItems;

    public Block(ArrayList<AstNode> blockItems) {
        this.blockItems = blockItems;
    }

    @Override
    public String getSymbol() {
        return "<Block>";
    }

    @Override
    public void printToFile(BufferedWriter bw) throws IOException {
        bw.write(TokenType.LBRACE + " {\n");
        for (AstNode blockItem : blockItems) {
            blockItem.printToFile(bw);
        }
        bw.write(TokenType.RBRACE + " }\n");
        bw.write(getSymbol() + "\n");
    }
}
