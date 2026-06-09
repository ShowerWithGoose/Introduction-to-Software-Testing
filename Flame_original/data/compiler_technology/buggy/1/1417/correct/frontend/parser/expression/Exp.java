package frontend.parser.expression;

import frontend.parser.Node;

import java.util.ArrayList;

public class Exp extends Node {
    public Exp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
