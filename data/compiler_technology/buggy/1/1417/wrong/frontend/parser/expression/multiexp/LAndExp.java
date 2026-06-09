package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.parser.Node;

import java.util.ArrayList;

public class LAndExp extends Node {
    public LAndExp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
