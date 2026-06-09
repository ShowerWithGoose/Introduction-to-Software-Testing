package parser.node;

import lexer.Token;
import parser.NodeType;

public class UnaryOpNode {
    Token unaryOpTK;

    public UnaryOpNode(Token unaryOpTK) {
        this.unaryOpTK = unaryOpTK;
    }
    public void print() {
        unaryOpTK.print();
        System.out.println(NodeType.UnaryOp);
    }
}
