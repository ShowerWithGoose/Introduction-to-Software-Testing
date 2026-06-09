package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.parser.Node;

import java.util.ArrayList;

// LOrExp -> LAndExp { '||' LAndExp }
public class LOrExp extends Node {
    public LOrExp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
