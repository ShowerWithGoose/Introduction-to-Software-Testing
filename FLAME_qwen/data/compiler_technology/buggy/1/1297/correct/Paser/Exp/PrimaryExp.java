package Paser.Exp;

import Paser.Node;
import Symbol.SymbolManager;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  PrimaryExp â†’ '(' Exp ')' | LVal | Number | Character
public class PrimaryExp extends Node {
    public PrimaryExp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public ValueType getValueType() {
        if (children.get(0) instanceof LValExp) {

            ValueType v = ((LValExp) children.get(0)).getValueType();

            return v;
        } else if (children.get(0) instanceof Number) {
            return ValueType.INT;
        } else if (children.get(0) instanceof Character) {
            return ValueType.CHAR;
        } else if (children.get(1) instanceof Exp) {
            return ((Exp) children.get(1)).getValueType();
        } else {
            System.err.println("PrimaryExp getValueType error");
        }
        return null;
    }

    @Override
    public void createSymbolTable() {
        if (children.get(0) instanceof LValExp) {
            SymbolManager.canChange = true;
            ((LValExp) children.get(0)).createSymbolTable();
            SymbolManager.canChange = false;
        } else {
            super.createSymbolTable();
        }
    }
}
