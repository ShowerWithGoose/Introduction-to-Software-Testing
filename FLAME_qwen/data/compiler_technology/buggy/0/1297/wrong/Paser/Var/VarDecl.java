package Paser.Var;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

public class VarDecl extends Node {
    public VarDecl(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
