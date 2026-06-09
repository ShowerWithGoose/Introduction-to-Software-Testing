package Paser.Stmt;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  'if' '(' Cond ')' Stmt [ 'else' Stmt ]
public class IfStmt extends Stmt {
    public IfStmt(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
