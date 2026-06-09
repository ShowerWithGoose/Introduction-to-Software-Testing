package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.primaryexp.LVal;

import java.util.ArrayList;

// ForStmt -> LVal '=' Exp
public class ForStmt extends Node {
    public ForStmt(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
