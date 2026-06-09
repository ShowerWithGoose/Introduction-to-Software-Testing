package frontend.AST.Var;

import frontend.AST.Node;
import frontend.AST.SyntaxVarType;

import java.util.ArrayList;

public class InitVal extends Node {
    public InitVal(int startLineNum, int endLineNum, SyntaxVarType type, ArrayList<Node> childNodes) {
        super(startLineNum, endLineNum, type, childNodes);
    }
}
