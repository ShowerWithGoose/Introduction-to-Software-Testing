package parser.node;

import lexer.Token;
import parser.NodeType;

public class NumberNode {
    Token intconTK;
    public NumberNode(Token intconTK) {
        this.intconTK = intconTK;
    }
    public void print() {
        intconTK.print();
        System.out.println(NodeType.Number);
    }
}
