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
        if (((TokenNode)children.get(0)).getToken().getDescription().equals("int")) {
            if (children.size() == 2) {
                return ValueType.INT;
            } else {
                return ValueType.INTARRAY;
            }
        } else if (((TokenNode)children.get(0)).getToken().getDescription().equals("char")) {
            if (children.size() == 2) {
                return ValueType.CHAR;
            } else {
                return ValueType.CHARARRAY;
            }
        } else {
            System.err.println("Invalid type");
            return ValueType.VOID;
        }
    }

    public String getName() {
        return ((TokenNode)children.get(1)).getToken().getDescription();
    }


}
