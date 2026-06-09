package frontend.parser.expression.primaryexp;

import frontend.parser.Node;

import java.util.ArrayList;

// PrimaryExp -> '(' Exp ')' | LVal | Number | Character
public class PrimaryExp extends Node{
    public PrimaryExp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
