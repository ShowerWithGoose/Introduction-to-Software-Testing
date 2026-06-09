package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.expression.Exp;

import java.util.ArrayList;

// Stmt -> 'return' [Exp] ';'
public class StmtReturn extends Node {
    public StmtReturn(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
