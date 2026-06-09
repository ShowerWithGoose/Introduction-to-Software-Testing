package frontend.parser.statement.stmt;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Node;
import frontend.parser.expression.Exp;
import frontend.parser.terminal.StringConst;

import java.util.ArrayList;

// Stmt -> 'printf' '(' StringConst { ',' Exp } ')' ';'
public class StmtPrintf extends Node {
    public StmtPrintf(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
