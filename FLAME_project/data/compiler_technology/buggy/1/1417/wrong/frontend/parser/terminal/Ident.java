package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.parser.Node;

import java.util.ArrayList;

public class Ident extends Node {
    public Ident(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
