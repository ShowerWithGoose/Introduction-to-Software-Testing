package parser_part.expression;

import parser_part.declaration.constance.ConstInitValComponent;
import parser_part.expression.binaryExpression.AddExp;
import symbol_part.Symbol;
import symbol_part.SymbolList;

public class ConstExp implements ConstInitValComponent,Computable {
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String toString() {
        return addExp.toString() + "<ConstExp>\n";
    }

    @Override
    public int compute(SymbolList symbolList) {
        return addExp.compute(symbolList);
    }

    @Override
    public Symbol.SymbolType getSymbolType() {
        return addExp.getSymbolType();
    }
}
