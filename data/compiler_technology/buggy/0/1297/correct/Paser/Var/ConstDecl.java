package Paser.Var;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

public class ConstDecl extends Node {
    public ConstDecl(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}