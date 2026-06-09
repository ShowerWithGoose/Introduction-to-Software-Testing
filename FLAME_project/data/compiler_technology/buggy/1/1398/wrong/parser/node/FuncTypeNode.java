package parser.node;

import lexer.Token;

public class FuncTypeNode {
    Token funcTypeTK;

    public FuncTypeNode(Token funcTypeTK) {
        this.funcTypeTK = funcTypeTK;
    }
    public void print() {
        funcTypeTK.print();
    }
}
