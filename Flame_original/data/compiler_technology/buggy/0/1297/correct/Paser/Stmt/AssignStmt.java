package Paser.Stmt;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

public class AssignStmt extends Stmt {
    public AssignStmt(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
