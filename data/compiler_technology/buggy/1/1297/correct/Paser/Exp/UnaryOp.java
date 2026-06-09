package Paser.Exp;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

 // UnaryOp → '+' | '−' | '!'
public class UnaryOp extends Node {
    public UnaryOp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
