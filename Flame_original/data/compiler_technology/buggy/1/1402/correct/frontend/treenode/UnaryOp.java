package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;

import static frontend.executor.Parser.writeParser;

// 单目运算符 UnaryOp → '+' | '−' | '!'
public class UnaryOp {
    public String nodeName;
    public Token plusToken, minusToken, notToken;

    public UnaryOp(String nodeName, Token plusToken, Token minusToken, Token notToken) {
        this.nodeName = nodeName;
        this.plusToken = plusToken;
        this.minusToken = minusToken;
        this.notToken = notToken;
    }

    public void print() throws IOException {
        if (plusToken != null)
            writeParser(plusToken.getTypeAndContent());
        else if (minusToken != null)
            writeParser(minusToken.getTypeAndContent());
        else
            writeParser(notToken.getTypeAndContent());
        writeParser(nodeName);
    }
}
