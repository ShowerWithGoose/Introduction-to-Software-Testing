package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.parser.Node;

import java.util.ArrayList;

public class RelExp extends Node {
    public RelExp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
