package node;

import token.Token;

import java.io.IOException;

public class FuncTypeNode {
    // FuncType ->  'void' | 'int' | 'char'

    private Token token;

    public FuncTypeNode(Token token) {
        this.token = token;
    }

    public Token getToken() {
        return token;
    }
    
    public void print() throws IOException {
        token.print();
        Io.Text.printWord("<FuncType>");
    }
    
}
