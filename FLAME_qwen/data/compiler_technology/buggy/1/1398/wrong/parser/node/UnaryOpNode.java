package parser.node;

import lexer.Token;

public class UnaryOpNode {
    Token unaryOpTK;

    public UnaryOpNode(Token unaryOpTK) {
        this.unaryOpTK = unaryOpTK;
    }
    public void print() {
        unaryOpTK.print();
    }
}
