package frontend.parser.expression;

import frontend.parser.Node;
import frontend.parser.expression.multiexp.LOrExp;

import java.util.ArrayList;

public class Cond extends Node {
    public Cond(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
