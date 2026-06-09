package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

// 左值表达式 LVal → Ident ['[' Exp ']']
public class LVal {
    private String nodeName;
    private Token identToken;
    private Token lbrackToken;
    private Exp exp;
    private Token rbrackToken;

    public LVal(String nodeName, Token identToken, Token lbrackToken, Exp exp, Token rbrackToken) {
        this.nodeName = nodeName;
        this.identToken = identToken;
        this.lbrackToken = lbrackToken;
        this.exp = exp;
        this.rbrackToken = rbrackToken;
    }

    public void print() throws IOException {
        writeParser(identToken.toString());
        if(lbrackToken!=null){
            writeParser(lbrackToken.toString());
            exp.print();
            writeParser(rbrackToken.toString());
        }
        writeParser(nodeName);
    }
}
