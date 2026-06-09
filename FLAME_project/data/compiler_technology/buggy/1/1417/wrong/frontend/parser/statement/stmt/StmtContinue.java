package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.Node;

import java.util.ArrayList;

// Stmt -> 'continue' ';'
public class StmtContinue extends Node {
    public StmtContinue(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
