package node;

import token.Token;

import java.io.IOException;

public class BTypeNode {
    // BType -> 'int' | 'char'
    private Token token;

    public BTypeNode(Token token) {
        this.token = token;
    }
    
    public void print() throws IOException {
        token.print();
    }
}
