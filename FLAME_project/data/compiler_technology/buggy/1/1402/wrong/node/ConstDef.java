package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

// 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
public class ConstDef {
    private String nodeName;
    private Token identToken;
    private Token lbrackToken;
    private ConstExp constExp;
    private Token rbrackToken;
    private Token assignToken;
    private ConstInitval constInitval;

    public ConstDef(String nodeName, Token identToken, Token lbrackToken, ConstExp constExp, Token rbrackToken, Token assignToken, ConstInitval constInitval) {
        this.nodeName = nodeName;
        this.identToken = identToken;
        this.lbrackToken = lbrackToken;
        this.constExp = constExp;
        this.rbrackToken = rbrackToken;
        this.assignToken = assignToken;
        this.constInitval = constInitval;
    }

    // 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    public void print() throws IOException {
        writeParser(identToken.toString());
        if (lbrackToken != null) {
            writeParser(lbrackToken.toString());
            constExp.print();
            writeParser(rbrackToken.toString());
        }
        writeParser(assignToken.toString());
        constInitval.print();
        writeParser(nodeName);
    }
}
