package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

// FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
public class FuncDef {
    private String nodeName;
    private FuncType funcType;
    private Token identToken;
    private Token lparentToken;
    private FuncFParams funcFParams;
    private Token rparentToken;
    private Block block;

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
        writeParser(identToken.toString());
        writeParser(lparentToken.toString());
        if(funcFParams!=null)
            funcFParams.print();
        writeParser(rparentToken.toString());
        block.print();
        writeParser(nodeName);
    }
}
