package Paser.Stmt;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
public class ForStmt extends Stmt {
    public ForStmt(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}