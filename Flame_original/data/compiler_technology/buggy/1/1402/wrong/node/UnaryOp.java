package node;

import token.Token;

import java.io.IOException;

import static utils.IO.writeParser;

// 单目运算符 UnaryOp → '+' | '−' | '!'
public class UnaryOp {
    private String nodeName;
    private Token plusToken;
    private Token minusToken;
    private Token notToken;

    public UnaryOp(String nodeName, Token plusToken, Token minusToken, Token notToken) {
        this.nodeName = nodeName;
        this.plusToken = plusToken;
        this.minusToken = minusToken;
        this.notToken = notToken;
    }

    public void print() throws IOException {
        if (plusToken != null)
            writeParser(plusToken.toString());
        else if (minusToken != null)
            writeParser(minusToken.toString());
        else
            writeParser(notToken.toString());
        writeParser(nodeName);
    }
}
