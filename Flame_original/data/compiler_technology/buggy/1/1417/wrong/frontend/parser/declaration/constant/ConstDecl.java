package frontend.parser.declaration.constant;

import frontend.parser.Node;

import java.util.ArrayList;

public class ConstDecl extends Node {
    public ConstDecl(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
