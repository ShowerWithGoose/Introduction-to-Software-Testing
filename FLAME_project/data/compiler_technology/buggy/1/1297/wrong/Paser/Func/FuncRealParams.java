package Paser.Func;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

// FuncRParams â†’ Exp { ',' Exp }
public class FuncRealParams extends Node {
    public FuncRealParams(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
