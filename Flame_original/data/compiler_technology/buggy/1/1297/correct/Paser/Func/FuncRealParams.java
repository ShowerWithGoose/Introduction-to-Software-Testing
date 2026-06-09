package Paser.Func;

import Paser.Exp.Exp;
import Paser.Node;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

// FuncRParams â†’ Exp { ',' Exp }
public class FuncRealParams extends Node {
    public FuncRealParams(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public ArrayList<ValueType> getParamsType() {
        ArrayList<ValueType> params = new ArrayList<>();
        for (int i = 0; i < children.size(); i += 2) {
            params.add(((Exp)children.get(i)).getValueType());
        }
        return params;
    }
}
