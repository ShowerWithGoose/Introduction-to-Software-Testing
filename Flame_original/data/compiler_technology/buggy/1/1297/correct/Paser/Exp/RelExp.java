package Paser.Exp;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

// RelExp â†’ AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
public class RelExp extends Node {
    public RelExp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
