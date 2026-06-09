package frontend.parser.function.param;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.function.param.FuncFParam;

import java.util.ArrayList;

public class FuncFParams extends Node {
    public FuncFParams(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
