package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.function.param.FuncRParams;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

// UnaryExp -> Ident '(' [FuncRParams] ')'
public class UnaryExpFunc extends Node {
    public UnaryExpFunc(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
