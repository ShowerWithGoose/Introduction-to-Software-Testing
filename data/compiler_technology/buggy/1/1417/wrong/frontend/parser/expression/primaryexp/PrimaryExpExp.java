package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.ExpParser;

import java.util.ArrayList;

// PrimaryExp -> '(' Exp ')'
public class PrimaryExpExp extends Node {
    public PrimaryExpExp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
