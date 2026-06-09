package frontend.parser.expression.primaryexp;

import frontend.parser.Node;
import frontend.parser.terminal.IntConst;

import java.util.ArrayList;

public class Number extends Node {

    public Number(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
