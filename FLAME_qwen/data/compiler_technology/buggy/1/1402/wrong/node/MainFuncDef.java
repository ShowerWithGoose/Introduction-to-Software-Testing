package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

// MainFuncDef → 'int' 'main' '(' ')' Block
public class MainFuncDef {
    private String nodeName;
    private Token intToken;
    private Token mainToken;
    private Token lparentToken;
    private Token rparentToken;
    private Block block;

    public MainFuncDef(String nodeName, Token intToken, Token mainToken, Token lparentToken, Token rparentToken, Block block) {
        this.nodeName = nodeName;
        this.intToken = intToken;
        this.mainToken = mainToken;
        this.lparentToken = lparentToken;
        this.rparentToken = rparentToken;
        this.block = block;
    }

    // MainFuncDef → 'int' 'main' '(' ')' Block
    public void print() throws IOException {
        writeParser(intToken.toString());
        writeParser(mainToken.toString());
        writeParser(lparentToken.toString());
        writeParser(rparentToken.toString());
        block.print();
        writeParser(nodeName);
    }
}
