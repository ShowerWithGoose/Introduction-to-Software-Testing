package parser.node;

import lexer.Token;

public class NumberNode {
    Token intconTK;
    public NumberNode(Token intconTK) {
        this.intconTK = intconTK;
    }
    public void print() {
        intconTK.print();
    }
}
