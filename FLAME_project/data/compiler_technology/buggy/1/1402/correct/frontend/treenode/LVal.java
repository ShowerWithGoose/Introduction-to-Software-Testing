package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;

import static frontend.executor.Parser.writeParser;

// 左值表达式 LVal → Ident ['[' Exp ']']
public class LVal {
    public String nodeName;
    public Token identToken, lbrackToken, rbrackToken;
    public Exp exp;

    public LVal(String nodeName, Token identToken, Token lbrackToken, Exp exp, Token rbrackToken) {
        this.nodeName = nodeName;
        this.identToken = identToken;
        this.lbrackToken = lbrackToken;
        this.exp = exp;
        this.rbrackToken = rbrackToken;
    }

    public void print() throws IOException {
        writeParser(identToken.getTypeAndContent());
        if (lbrackToken != null) {
            writeParser(lbrackToken.getTypeAndContent());
            exp.print();
            writeParser(rbrackToken.getTypeAndContent());
        }
        writeParser(nodeName);
    }
}
