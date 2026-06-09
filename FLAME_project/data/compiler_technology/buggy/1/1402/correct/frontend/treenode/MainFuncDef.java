package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;

import static frontend.executor.Parser.writeParser;

// MainFuncDef → 'int' 'main' '(' ')' Block
public class MainFuncDef {
    public String nodeName;
    public Token intToken, mainToken, lparentToken, rparentToken;
    public Block block;

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
        writeParser(intToken.getTypeAndContent());
        writeParser(mainToken.getTypeAndContent());
        writeParser(lparentToken.getTypeAndContent());
        writeParser(rparentToken.getTypeAndContent());
        block.print();
        writeParser(nodeName);
    }
}
