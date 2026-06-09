package parser_part.expression.unaryExpression;

import symbol_part.Symbol;
import symbol_part.SymbolList;

/**
 * UnaryExp -> UnaryOp UnaryExp
 **/
public class UnaryOpExp implements UnaryExpComponent {
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryOpExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public String toString() {
        return unaryOp.toString() + unaryExp.toString();
    }

    @Override
    public int getArray() {
        return unaryExp.getArray();
    }

    @Override
    public int compute(SymbolList symbolList) {
        if (unaryOp.isPlus()){
            return unaryExp.compute(symbolList);
        } else if (unaryOp.isMinus()){
            return -1 * unaryExp.compute(symbolList);
        } else {
            System.err.println("unsupported unaryOp in compute unaryOpExp");
            return -99;
        }
    }

    @Override
    public Symbol.SymbolType getSymbolType() {
        return unaryExp.getSymbolType();
    }
}
