package Paser.Var;

import Paser.Node;
import Paser.TokenNode;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  ConstDef â†’ Ident [ '[' ConstExp ']' ] '=' ConstInitVal
public class ConstDef extends Node {
    public ConstDef(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public String getName() {
        return ((TokenNode)children.get(0)).getName();
    }


}
