package parser_part.expression.primaryExpression;

import lexer_part.Token;
import parser_part.expression.Exp;
import symbol_part.Symbol;
import symbol_part.SymbolList;

public class ParentExp implements PrimaryExpComponent {
    private Token leftParent;
    private Exp exp;
    private Token rightParent;

    public ParentExp(Token leftParent, Exp exp, Token rightParent) {
        this.leftParent = leftParent;
        this.exp = exp;
        this.rightParent = rightParent;
    }

    @Override
    public int getArray() {
        return exp.getArray();
    }

    @Override
    public String toString() {
        return leftParent.toString() + exp.toString() + rightParent.toString();
    }

    @Override
    public int compute(SymbolList symbolList) {
        return exp.compute(symbolList);
    }

    @Override
    public Symbol.SymbolType getSymbolType() {
        return exp.getSymbolType();
    }
}
