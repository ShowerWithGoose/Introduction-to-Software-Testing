package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.statement.Block;

import java.util.ArrayList;

public class MainFuncDef extends Node {
    public MainFuncDef(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
