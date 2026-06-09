package Paser.Var;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

// VarDecl â†’ BType VarDef { ',' VarDef } ';'
public class VarDecl extends Node {
    public VarDecl(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
