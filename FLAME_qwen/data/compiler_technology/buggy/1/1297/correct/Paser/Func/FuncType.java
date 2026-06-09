package Paser.Func;

import Paser.Node;
import Paser.TokenNode;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

// FuncType â†’ 'void' | 'int' | 'char
public class FuncType extends Node {

    public FuncType(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public ValueType getFuncType() {
        if (((TokenNode)this.getChildren().get(0)).getToken().getDescription().equals("void")) {
            return ValueType.VOID;
        } else if (((TokenNode)this.getChildren().get(0)).getToken().getDescription().equals("int")) {
            return ValueType.INT;
        } else if (((TokenNode)this.getChildren().get(0)).getToken().getDescription().equals("char")) {
            return ValueType.CHAR;
        }
        System.err.println("FuncType error");
        return null;
    }
}
