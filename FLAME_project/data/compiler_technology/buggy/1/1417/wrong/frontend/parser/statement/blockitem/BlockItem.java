package frontend.parser.statement.blockitem;

import frontend.parser.Node;

import java.util.ArrayList;

// BlockItem -> Decl | Stmt
public class BlockItem extends Node {
    public BlockItem(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
