package node;

import token.Token;

import java.io.IOException;

public class UnaryOpNode {
    // UnaryOp -> '+' | 'âˆ’' | '!'

    private Token token;

    public UnaryOpNode(Token token) {
        this.token = token;
    }

    public Token getToken() {
        return token;
    }
    
    public void print() throws IOException {
        token.print();
        Io.Text.printWord("<UnaryOp>");
    }
    
}
