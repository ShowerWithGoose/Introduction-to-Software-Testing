package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Node;
import frontend.parser.expression.Exp;

import java.util.ArrayList;

// Stmt -> [ Exp ] ';'
public class StmtExp extends Node {
    public StmtExp(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
