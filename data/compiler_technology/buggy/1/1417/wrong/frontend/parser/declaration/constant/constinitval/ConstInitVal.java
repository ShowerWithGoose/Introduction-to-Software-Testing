package frontend.parser.declaration.constant.constinitval;

import frontend.parser.Node;

import java.util.ArrayList;

public class ConstInitVal extends Node {
    public ConstInitVal(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
