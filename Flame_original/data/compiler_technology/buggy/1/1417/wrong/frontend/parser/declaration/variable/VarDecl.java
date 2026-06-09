package frontend.parser.declaration.variable;

import frontend.parser.Node;

import java.util.ArrayList;

// VarDecl -> BType VarDef { ',' VarDef } ';'
public class VarDecl extends Node {
    public VarDecl(int startLine, int endLine, String name, ArrayList<Node> nodes) {
        super(startLine, endLine, name, nodes);
    }
}
