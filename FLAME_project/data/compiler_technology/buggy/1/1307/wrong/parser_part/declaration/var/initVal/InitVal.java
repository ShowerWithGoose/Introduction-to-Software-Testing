package parser_part.declaration.var.initVal;

import parser_part.Node;
import parser_part.expression.Computable;
import parser_part.expression.Exp;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class InitVal implements Node {
    private InitValComponent initValComponent;

    public InitVal(InitValComponent initValComponent) {
        this.initValComponent = initValComponent;
    }

    @Override
    public String toString() {
        return initValComponent.toString() + "<InitVal>\n";
    }

    public boolean isArrayInitialValue() {
        return initValComponent instanceof ArrayInitVal;
    }

    public void setDepth(int depth) {
        if (initValComponent instanceof ArrayInitVal) {
            ((ArrayInitVal) initValComponent).setDepth(depth);
        }
    }

    public int getInitVal(SymbolList symbolList) {
        if (initValComponent instanceof Exp exp) {
            return exp.compute(symbolList);
        }
        return -99;
    }

    public ArrayList<Integer> getArrayInitVals(SymbolList symbolList) {
        ArrayList<Integer> arrayInitValList = new ArrayList<>();
        if (initValComponent instanceof ArrayInitVal arrayInitVal) {
            arrayInitValList.add(arrayInitVal.getFirst().compute(symbolList));
            for (Exp exp : arrayInitVal.getInitVals()) {
                arrayInitValList.add(exp.compute(symbolList));
            }
        }
        return arrayInitValList;
    }
}