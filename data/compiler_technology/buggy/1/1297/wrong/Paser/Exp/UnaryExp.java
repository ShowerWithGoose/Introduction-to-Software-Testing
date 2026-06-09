package Paser.Exp;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

//UnaryExp â†’ PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
public class UnaryExp extends Node{
    public UnaryExp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
