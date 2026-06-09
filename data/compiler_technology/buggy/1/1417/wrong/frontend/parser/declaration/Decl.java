package frontend.parser.declaration;

import frontend.parser.Node;

import java.util.ArrayList;

// Decl -> ConstDecl | VarDecl
public class Decl extends Node {
    public Decl(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
