package frontend.parser.function.functype;

import frontend.lexer.Token;
import frontend.parser.Node;

import java.util.ArrayList;

public class FuncType extends Node {
    public FuncType(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
