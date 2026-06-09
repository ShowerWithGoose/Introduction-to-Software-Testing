package frontend.parser.terminal;

import frontend.parser.Node;

import java.util.ArrayList;

public class StringConst extends Node {
    public StringConst(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
