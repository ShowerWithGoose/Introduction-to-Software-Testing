package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.expression.primaryexp.LVal;

import java.util.ArrayList;

// Stmt -> LVal '=' Exp ';'
public class StmtAssign extends Node {
    public StmtAssign(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }

}
