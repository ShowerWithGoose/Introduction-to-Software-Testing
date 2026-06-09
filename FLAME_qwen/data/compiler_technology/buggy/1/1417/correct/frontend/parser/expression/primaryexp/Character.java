package frontend.parser.expression.primaryexp;

import frontend.parser.Node;
import frontend.parser.terminal.CharConst;

import java.util.ArrayList;

// Character -> CharConst
public class Character extends Node {
    public Character(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
