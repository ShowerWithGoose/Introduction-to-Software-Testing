package frontend.AST.Exp;

import frontend.AST.Node;
import frontend.AST.SyntaxVarType;

import java.util.ArrayList;

public class ConstExp extends Node {
    public ConstExp (int starLineNum, int endLineNum, SyntaxVarType type, ArrayList<Node> childNodes) {
        super(starLineNum, endLineNum, type, childNodes);
    }
}
