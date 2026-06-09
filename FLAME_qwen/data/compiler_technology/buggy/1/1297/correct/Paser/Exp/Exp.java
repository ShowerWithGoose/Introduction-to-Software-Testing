package Paser.Exp;

import Paser.Node;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

// Exp â†’ AddExp
public class Exp extends Node{
    public Exp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public ValueType getValueType() {
        return ((AddExp)children.get(0)).getValueType();
    }
}
