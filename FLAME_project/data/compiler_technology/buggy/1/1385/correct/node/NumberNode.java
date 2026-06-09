package node;

import token.Token;

import java.io.IOException;

public class NumberNode {
    // Number -> IntConst

    private Token intConst;

    public NumberNode(Token intConst) {
        this.intConst = intConst;
    }
    
    public void print() throws IOException {
        intConst.print();
        Io.Text.printWord("<Number>");
    }
    
}
