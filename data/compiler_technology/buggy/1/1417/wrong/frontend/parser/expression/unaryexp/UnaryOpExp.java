package frontend.parser.expression.unaryexp;

import frontend.parser.Node;

import java.util.ArrayList;

public class UnaryOpExp extends Node {
    public UnaryOpExp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
