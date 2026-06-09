package Paser.Var;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

public class ConstDef extends Node {
    public ConstDef(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

}
