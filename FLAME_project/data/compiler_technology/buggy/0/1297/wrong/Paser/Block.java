package Paser;

import Type.SyntaxVarType;

import java.util.ArrayList;

public class Block extends Node{
    public Block(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

}

