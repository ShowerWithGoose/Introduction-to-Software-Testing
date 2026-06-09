package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;

import static frontend.executor.Parser.writeParser;

// 数值 Number → IntConst
public class Number {
    public String nodeName;
    public Token intConstToken;

    public Number(String nodeName, Token intConstToken){
        this.nodeName = nodeName;
        this.intConstToken = intConstToken;
    }

    public void print() throws IOException {
        writeParser(intConstToken.getTypeAndContent());
        writeParser(nodeName);
    }
}
