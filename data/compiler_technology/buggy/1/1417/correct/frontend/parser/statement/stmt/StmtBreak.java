package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.Node;

import java.util.ArrayList;

// Stmt -> 'break' ';'
public class StmtBreak extends Node {
    public StmtBreak(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
