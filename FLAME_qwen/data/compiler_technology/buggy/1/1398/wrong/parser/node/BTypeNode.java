package parser.node;

import lexer.Token;

public class BTypeNode {
    Token bTypeTK;

    public BTypeNode(Token bTypeToken) {
        this.bTypeTK = bTypeToken;
    }

    public void print() {
        bTypeTK.print();
    }
}
