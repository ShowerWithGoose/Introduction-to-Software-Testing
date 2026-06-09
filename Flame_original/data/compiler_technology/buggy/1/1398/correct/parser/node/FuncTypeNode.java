package parser.node;

import lexer.Token;
import parser.NodeType;

public class FuncTypeNode {
    Token funcTypeTK;

    public FuncTypeNode(Token funcTypeTK) {
        this.funcTypeTK = funcTypeTK;
    }
    public void print() {
        funcTypeTK.print();
        System.out.println(NodeType.FuncType);
    }
}
