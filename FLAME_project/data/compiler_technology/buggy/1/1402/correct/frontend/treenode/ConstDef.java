package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;

import static frontend.executor.Parser.writeParser;


// 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
public class ConstDef {
    public String nodeName;
    public Token identToken, lbrackToken, rbrackToken, assignToken;
    public ConstExp constExp;
    public ConstInitval constInitval;

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
        writeParser(identToken.getTypeAndContent());
        if (lbrackToken != null) {
            writeParser(lbrackToken.getTypeAndContent());
            constExp.print();
            writeParser(rbrackToken.getTypeAndContent());
        }
        writeParser(assignToken.getTypeAndContent());
        constInitval.print();
        writeParser(nodeName);
    }
}
