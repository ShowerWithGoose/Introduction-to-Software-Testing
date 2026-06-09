package Paser.Exp;

import Paser.Node;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  MulExp â†’ UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
public class MulExp extends Node{
    public MulExp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
