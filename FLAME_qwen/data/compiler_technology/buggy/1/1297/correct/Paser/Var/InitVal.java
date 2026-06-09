package Paser.Var;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

// InitVal â†’ Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
public class InitVal extends Node {
    public InitVal(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
