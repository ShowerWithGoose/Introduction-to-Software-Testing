package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.expression.Cond;

import java.util.ArrayList;

// Stmt -> 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
public class StmtFor extends Node {
    public StmtFor(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
