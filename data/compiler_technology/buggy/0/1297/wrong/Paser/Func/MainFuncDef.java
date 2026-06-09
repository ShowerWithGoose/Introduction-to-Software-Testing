package Paser.Func;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

public class MainFuncDef extends Node {
    public MainFuncDef(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
