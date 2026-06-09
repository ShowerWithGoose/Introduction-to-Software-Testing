package frontend.parser.statement.stmt;

import frontend.parser.Node;

import java.util.ArrayList;

public class Stmt extends Node {
    public Stmt(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
