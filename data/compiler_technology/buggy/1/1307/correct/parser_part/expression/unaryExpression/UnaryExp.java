package parser_part.expression.unaryExpression;

import parser_part.Node;
import parser_part.expression.Computable;
import symbol_part.Symbol;
import symbol_part.SymbolList;

/**
 * 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
 **/
public class UnaryExp implements Computable {
    private UnaryExpComponent unaryExpComponent;

    public UnaryExp(UnaryExpComponent unaryExpComponent) {
        this.unaryExpComponent = unaryExpComponent;
    }

    @Override
    public String toString() {
        return unaryExpComponent.toString() + "<UnaryExp>\n";
    }

    public int getArray() {
        return unaryExpComponent.getArray();
    }

    @Override
    public Symbol.SymbolType getSymbolType() {
        return unaryExpComponent.getSymbolType();
    }

    @Override
    public int compute(SymbolList symbolList) {
        return unaryExpComponent.compute(symbolList);
    }
}
