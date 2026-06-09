package frontend.parser.function.param;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.declaration.BType;
import frontend.parser.terminal.Ident;

import java.util.ArrayList;

// FuncFParam -> BType Ident [ '[' ']' ]
public class FuncFParam extends Node {
    public FuncFParam(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
