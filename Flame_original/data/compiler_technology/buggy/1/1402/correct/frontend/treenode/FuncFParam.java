package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;

import static frontend.executor.Parser.writeParser;


// 函数形参 FuncFParam → BType Ident ['[' ']']
public class FuncFParam {
    public String nodeName;
    public BType bType;
    public Token identToken, lbrack, rbrack;

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
        writeParser(identToken.getTypeAndContent());
        if (lbrack != null) {
            writeParser(lbrack.getTypeAndContent());
            writeParser(rbrack.getTypeAndContent());
        }
        writeParser(nodeName);
    }
}

