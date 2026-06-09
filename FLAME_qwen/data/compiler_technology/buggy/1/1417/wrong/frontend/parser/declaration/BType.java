package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.parser.Node;

import java.util.ArrayList;

// BType -> int | char
public class BType extends Node {
    public BType(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
