package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.parser.Node;

import java.util.ArrayList;

public class IntConst extends Node{
    public IntConst(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
