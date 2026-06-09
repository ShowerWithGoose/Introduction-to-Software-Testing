package Paser.Exp;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

// Cond â†’ LOrExp
public class CondExp extends Node{
    public CondExp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
