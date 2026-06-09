package parser_part.function;

import lexer_part.Token;
import parser_part.Node;
import parser_part.block.Block;

import java.util.ArrayList;

public class MainFuncDef implements Node {
    private Token intToken;
    private Token mainToken;
    private Token leftParent;
    private Token rightParent;
    private Block block;

    public MainFuncDef(Token intToken, Token mainToken, Token leftParent, Token rightParent, Block block) {
        this.intToken = intToken;
        this.mainToken = mainToken;
        this.leftParent = leftParent;
        this.rightParent = rightParent;
        this.block = block;
    }

    @Override
    public String toString() {
        return intToken.toString() + mainToken.toString() + leftParent.toString()
                + rightParent.toString() + block.toString() + "<MainFuncDef>\n";
    }
}
