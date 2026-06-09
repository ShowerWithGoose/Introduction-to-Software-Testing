package frontend.parser.declaration.variable.initval;

import frontend.parser.Node;

import java.util.ArrayList;

public class InitVal extends Node {

    public InitVal(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }

}
