package parser_part.expression.primaryExpression;

import symbol_part.Symbol;
import symbol_part.SymbolList;

public class Number implements PrimaryExpComponent {
    private NumberComponent numberComponent;

    public Number(NumberComponent numberComponent) {
        this.numberComponent = numberComponent;
    }

    @Override
    public String toString() {
        return numberComponent.toString() + "<Number>\n";
    }

    @Override
    public int getArray() {
        return 0;
    }

    @Override
    public Symbol.SymbolType getSymbolType() {
        return Symbol.SymbolType.Int;
    }

    public int compute(SymbolList symbolList){
        return numberComponent.compute();
    }
}
