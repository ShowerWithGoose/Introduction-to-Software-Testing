package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.expression.primaryexp.LVal;

import java.util.ArrayList;

public class StmtGetChar extends Node {
    public StmtGetChar(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
