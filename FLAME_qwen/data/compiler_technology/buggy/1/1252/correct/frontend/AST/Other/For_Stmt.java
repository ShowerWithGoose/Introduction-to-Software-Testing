package frontend.AST.Other;

import frontend.AST.Node;
import frontend.AST.SyntaxVarType;

import java.util.ArrayList;

public class For_Stmt extends Node {
    public For_Stmt (int startLineNum, int endLineNum, SyntaxVarType type,
                    ArrayList<Node> childNodes) {
        super(startLineNum, endLineNum, type, childNodes);
    }
}
