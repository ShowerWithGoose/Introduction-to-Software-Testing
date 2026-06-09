package Paser.Stmt;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

public class BreakStmt extends Stmt {
    public BreakStmt(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
