package frontend.parser.expression;


import frontend.parser.Node;

import java.util.ArrayList;

// ConstExp -> AddExp
public class ConstExp extends Node {
    public ConstExp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
       super(startLine, endLine, name, nodes);
    }
}
