package parser_part.expression.primaryExpression;

import parser_part.expression.unaryExpression.UnaryExpComponent;
import symbol_part.Symbol;
import symbol_part.SymbolList;

public class PrimaryExp implements UnaryExpComponent {
    private PrimaryExpComponent primaryExpComponent;

    @Override
    public Symbol.SymbolType getSymbolType() {
        return primaryExpComponent.getSymbolType();
    }

    public PrimaryExp(PrimaryExpComponent primaryExpComponent) {
        this.primaryExpComponent = primaryExpComponent;
    }

    @Override
    public String toString() {
        return primaryExpComponent.toString() + "<PrimaryExp>\n";
    }

    public int getArray() {
        return primaryExpComponent.getArray();
    }

    @Override
    public int compute(SymbolList symbolList) {
        return primaryExpComponent.compute(symbolList);
    }
}
