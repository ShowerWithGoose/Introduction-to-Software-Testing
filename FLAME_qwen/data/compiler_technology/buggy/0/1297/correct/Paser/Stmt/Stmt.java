package Paser.Stmt;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

public class Stmt extends Node {
    public Stmt(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}