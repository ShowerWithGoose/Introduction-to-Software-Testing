package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;

import static frontend.executor.Parser.writeParser;


// FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
public class FuncDef {
    public String nodeName;
    public FuncType funcType;
    public Token identToken, lparentToken, rparentToken;
    public FuncFParams funcFParams;
    public Block block;

    public FuncDef(String nodeName, FuncType funcType, Token identToken, Token lparentToken, FuncFParams funcFParams, Token rparentToken, Block block) {
        this.nodeName = nodeName;
        this.funcType = funcType;
        this.identToken = identToken;
        this.lparentToken = lparentToken;
        this.funcFParams = funcFParams;
        this.rparentToken = rparentToken;
        this.block = block;
    }

    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    public void print() throws IOException {
        funcType.print();
        writeParser(identToken.getTypeAndContent());
        writeParser(lparentToken.getTypeAndContent());
        if (funcFParams != null)
            funcFParams.print();
        writeParser(rparentToken.getTypeAndContent());
        block.print();
        writeParser(nodeName);
    }
}
