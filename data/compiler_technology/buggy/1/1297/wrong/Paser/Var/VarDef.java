package Paser.Var;

import Paser.Node;
import Paser.TokenNode;
import Type.SyntaxVarType;

import java.util.ArrayList;

// VarDef â†’ Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
public class VarDef extends Node{
    public VarDef(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public String getName() {
        return ((TokenNode)children.get(0)).getName();
    }
}
