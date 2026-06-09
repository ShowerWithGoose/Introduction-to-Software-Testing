package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

// 函数形参 FuncFParam → BType Ident ['[' ']']
public class FuncFParam {
    private String nodeName;
    private BType bType;
    private Token identToken;
    private Token lbrack;
    private Token rbrack;

    public FuncFParam(String nodeName, BType bType, Token identToken, Token lbrack, Token rbrack) {
        this.nodeName = nodeName;
        this.bType = bType;
        this.identToken = identToken;
        this.lbrack = lbrack;
        this.rbrack = rbrack;
    }

    // 函数形参 FuncFParam → BType Ident ['[' ']']
    public void print() throws IOException {
        bType.print();
        writeParser(identToken.toString());
        if (lbrack != null) {
            writeParser(lbrack.toString());
            writeParser(rbrack.toString());
        }
        writeParser(nodeName);
    }
}

