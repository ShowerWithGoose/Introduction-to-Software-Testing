package frontend.parser.statement;

import frontend.lexer.Token;
import frontend.parser.Node;
import frontend.parser.statement.blockitem.BlockItem;

import java.util.ArrayList;

// Block -> '{' {BlockItem} '}'
public class Block extends Node {
    public Block(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
