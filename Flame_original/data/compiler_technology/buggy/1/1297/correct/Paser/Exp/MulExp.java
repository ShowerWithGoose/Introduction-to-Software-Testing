package Paser.Exp;

import Paser.Node;
import Symbol.SymbolManager;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
public class MulExp extends Node {
    public MulExp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public ValueType getValueType() {
        ValueType tmpType = null;
        if (children.get(0) instanceof MulExp) {
            tmpType = ((MulExp) children.get(0)).getValueType();
        } else if (children.get(0) instanceof UnaryExp) {
            tmpType = ((UnaryExp) children.get(0)).getValueType();
        }
        for (int i = 2; i < children.size(); i += 2) {
            ValueType v = ((UnaryExp) children.get(2)).getValueType();
            if (!SymbolManager.valueTypeIsSimilar(tmpType, v)) {
                System.err.println("两个不能相加的元素相乘");
            }
        }
        return tmpType;
    }

}
