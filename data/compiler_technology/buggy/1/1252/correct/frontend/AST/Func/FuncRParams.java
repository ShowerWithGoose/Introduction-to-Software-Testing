package frontend.AST.Func;

import frontend.AST.Node;
import frontend.AST.SyntaxVarType;

import java.util.ArrayList;

public class FuncRParams extends Node {
    public FuncRParams (int starLineNum, int endLineNum, SyntaxVarType type, ArrayList<Node> childNodes) {
        super(starLineNum, endLineNum, type, childNodes);
    }
}
