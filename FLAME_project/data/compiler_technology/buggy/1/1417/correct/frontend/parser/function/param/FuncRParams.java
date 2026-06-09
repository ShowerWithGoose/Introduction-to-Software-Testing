package frontend.parser.function.param;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.expression.Exp;

import java.util.ArrayList;

// FuncRParams -> Exp { ',' Exp }
public class FuncRParams extends Node{
    public FuncRParams(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
