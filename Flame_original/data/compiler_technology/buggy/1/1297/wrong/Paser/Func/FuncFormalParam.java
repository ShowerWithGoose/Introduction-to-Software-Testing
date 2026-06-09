package Paser.Func;

import Paser.Node;
import Paser.TokenNode;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

// FuncFParam â†’ BType Ident ['[' ']']
public class FuncFormalParam extends Node {
    public FuncFormalParam(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public ValueType getBtype() {
        return ((TokenNode)children.get(0)).getToken().getDescription().equals("int") ? ValueType.INT : ValueType.CHAR;
    }

    public String getName() {
        return ((TokenNode)children.get(1)).getToken().getDescription();
    }
}
