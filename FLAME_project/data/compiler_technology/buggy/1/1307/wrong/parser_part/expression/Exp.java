package parser_part.expression;

import parser_part.declaration.var.initVal.InitValComponent;
import parser_part.expression.binaryExpression.AddExp;
import symbol_part.Symbol;
import symbol_part.SymbolList;

public class Exp implements InitValComponent, Computable {
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String toString() {
        return addExp.toString() + "<Exp>\n";
    }

    public int getArray() {
        return addExp.getArray();
    }

    @Override
    public Symbol.SymbolType getSymbolType() {
        return addExp.getSymbolType();
    }

    @Override
    public int compute(SymbolList symbolList) {
        return addExp.compute(symbolList);
    }
}
