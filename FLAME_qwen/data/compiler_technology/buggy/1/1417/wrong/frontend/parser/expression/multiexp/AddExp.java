package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.parser.Node;

import java.util.ArrayList;

// AddExp -> MulExp { ('+'|'-') MulExp}
public class AddExp extends Node{
    public AddExp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
