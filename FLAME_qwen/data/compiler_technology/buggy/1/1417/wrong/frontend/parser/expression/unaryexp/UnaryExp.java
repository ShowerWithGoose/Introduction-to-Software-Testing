package frontend.parser.expression.unaryexp;

import frontend.parser.Node;

import java.util.ArrayList;

public class UnaryExp extends Node{
    public UnaryExp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
