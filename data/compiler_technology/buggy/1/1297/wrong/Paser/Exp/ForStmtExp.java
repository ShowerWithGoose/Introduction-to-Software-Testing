package Paser.Exp;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  ForStmt â†’ LVal '=' Exp
public class ForStmtExp extends Node{
    public ForStmtExp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
