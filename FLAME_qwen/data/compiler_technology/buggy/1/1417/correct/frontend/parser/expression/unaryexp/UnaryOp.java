package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.parser.Node;

import java.util.ArrayList;

public class UnaryOp extends Node {
    public UnaryOp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
