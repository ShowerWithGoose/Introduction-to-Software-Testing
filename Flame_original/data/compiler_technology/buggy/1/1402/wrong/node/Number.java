package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

// 数值 Number → IntConst
public class Number {
    private String nodeName;
    private Token intConstToken;

    public Number(String nodeName, Token intConstToken){
        this.nodeName = nodeName;
        this.intConstToken = intConstToken;
    }

    public void print() throws IOException {
        writeParser(intConstToken.toString());
        writeParser(nodeName);
    }
}
