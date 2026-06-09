package frontend.AST.Var;

import frontend.AST.Node;
import frontend.AST.SyntaxVarType;

import java.util.ArrayList;

public class VarDef extends Node {
    public VarDef(int starLineNum, int endLineNum, SyntaxVarType type, ArrayList<Node> childNodes) {
        super(starLineNum, endLineNum, type, childNodes);
    }
}
