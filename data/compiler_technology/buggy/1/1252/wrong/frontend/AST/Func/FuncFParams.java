package frontend.AST.Func;

import frontend.AST.Node;
import frontend.AST.SyntaxVarType;

import java.util.ArrayList;

public class FuncFParams extends Node {
    public FuncFParams (int starLineNum, int endLineNum, SyntaxVarType type, ArrayList<Node> childNodes) {
        super(starLineNum, endLineNum, type, childNodes);
    }
}
