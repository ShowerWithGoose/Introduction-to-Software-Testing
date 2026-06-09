package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.parser.Node;

import java.util.ArrayList;

public class CharConst extends Node {
    public CharConst(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
