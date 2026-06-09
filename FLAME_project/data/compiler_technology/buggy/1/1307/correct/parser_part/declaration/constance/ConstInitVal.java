package parser_part.declaration.constance;

import parser_part.FormatString;
import parser_part.Node;
import parser_part.declaration.var.initVal.ArrayInitVal;
import parser_part.declaration.var.initVal.InitVal;
import parser_part.expression.ConstExp;
import parser_part.expression.Exp;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class ConstInitVal implements Node {
    private ConstInitValComponent constInitValComponent;

    public ConstInitVal(ConstInitValComponent constInitValComponent) {
        this.constInitValComponent = constInitValComponent;
    }

    @Override
    public String toString() {
        return constInitValComponent.toString() + "<ConstInitVal>\n";
    }

    public boolean isArrayInitialValue() {
        return constInitValComponent instanceof ArrayConstInitVal;
    }

    public void setDepth(int depth) {
        if (constInitValComponent instanceof ArrayConstInitVal) {
            ((ArrayConstInitVal) constInitValComponent).setDepth(depth);
        }
    }

    public int getInitVal(SymbolList symbolList) {
        if (constInitValComponent instanceof Exp exp) {
            return exp.compute(symbolList);
        }
        return -99;
    }

    public ArrayList<Integer> getArrayInitVals(SymbolList symbolList) {
        ArrayList<Integer> arrayInitValList = new ArrayList<>();
        if (constInitValComponent instanceof ArrayConstInitVal arrayConstInitVal) {
            arrayInitValList.add(arrayConstInitVal.getFirst().compute(symbolList));
            for (ConstExp constExp : arrayConstInitVal.getConstInitVals()) {
                arrayInitValList.add(constExp.compute(symbolList));
            }
        }
        return arrayInitValList;
    }

    public boolean isArray() {
        return constInitValComponent instanceof ArrayConstInitVal ||
                constInitValComponent instanceof FormatString;
    }

}
