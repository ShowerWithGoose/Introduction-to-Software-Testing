package Paser.Exp;

import Paser.Node;
import Paser.TokenNode;
import Symbol.SymbolManager;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  LVal → Ident ['[' Exp ']']
public class LValExp extends Node {
    public LValExp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    @Override
    public void createSymbolTable() {
        Boolean isArray = children.size() == 4;
        SymbolManager.hasLval(((TokenNode) children.get(0)).getToken().getDescription(), ((TokenNode) children.get(0)).getToken().getLine());
        super.createSymbolTable();
    }

    public ValueType getValueType() {
        if (children.size() == 1) {
            return SymbolManager.name2valueType(((TokenNode) children.get(0)).getToken().getDescription(), startLine);
        } else {
            ValueType v = SymbolManager.name2valueType(((TokenNode) children.get(0)).getToken().getDescription(), startLine);
            if (v == ValueType.INTARRAY) {
                return ValueType.INT;
            } else if (v == ValueType.CHARARRAY) {
                return ValueType.CHAR;
            } else {
                System.err.println("在非数组内取值");
                return null;
            }
        }
    }
}
