package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

// LVal -> Ident [ '[' Exp ']' ]
public class LVal extends Node{
    public LVal(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
