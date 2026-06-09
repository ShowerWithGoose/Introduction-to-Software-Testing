package Paser.Exp;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

// EqExp â†’ RelExp | EqExp ('==' | '!=') RelExp
public class EqExp extends Node {
    public EqExp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
