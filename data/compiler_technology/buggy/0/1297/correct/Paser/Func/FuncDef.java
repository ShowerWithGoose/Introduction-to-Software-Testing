package Paser.Func;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

public class FuncDef extends Node {
    public FuncDef(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
