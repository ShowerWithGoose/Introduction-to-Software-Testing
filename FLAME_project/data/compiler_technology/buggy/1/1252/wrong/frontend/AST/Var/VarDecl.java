package frontend.AST.Var;

import frontend.AST.Node;
import frontend.AST.SyntaxVarType;

import java.util.ArrayList;

public class VarDecl extends Node {
    public VarDecl(int startLineNum, int endLineNum,
                   SyntaxVarType type, ArrayList<Node> childNodes) {
        super(startLineNum, endLineNum, type, childNodes);
    }
}
