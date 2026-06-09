package Paser.Exp;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

// LAndExp â†’ EqExp | LAndExp '&&' EqExp
public class LAndExp extends Node{
    public LAndExp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
