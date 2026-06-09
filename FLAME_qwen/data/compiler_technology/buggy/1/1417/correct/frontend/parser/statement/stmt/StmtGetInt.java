package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.expression.primaryexp.LVal;

import java.util.ArrayList;

// Stmt -> LVal '=' 'getInt' '(' ')' ';'
public class StmtGetInt extends Node {
    public StmtGetInt(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
