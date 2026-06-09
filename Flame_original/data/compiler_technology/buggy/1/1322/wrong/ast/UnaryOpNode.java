package ast;

import IO.IO;
import enum_package.NodeType;
import enum_package.UnaryOpType;
import frontend.Token;
import frontend.Parser;


public class UnaryOpNode {
    // UnaryOp → '+' | '−' | '!'
    public Token token;

    public UnaryOpNode(Token token) {
        this.token = token;
    }

    public void print() {
        IO.write(token.toString());
        IO.write(Parser.nodeTypeLabel.get(NodeType.UnaryOp));
    }
}
