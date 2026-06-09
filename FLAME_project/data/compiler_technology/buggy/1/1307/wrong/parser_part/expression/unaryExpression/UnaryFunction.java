package parser_part.expression.unaryExpression;

import lexer_part.Token;
import parser_part.function.FuncRParams;
import parser_part.Ident;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class UnaryFunction implements UnaryExpComponent {
    private Ident ident;
    private Token leftParent;
    private FuncRParams funcRParams = null;
    private Token rightParent;
    private int array;
    private Symbol.SymbolType symbolType;

    public UnaryFunction(Ident ident, Token leftParent, FuncRParams funcRParams,
                         Token rightParent, Symbol.SymbolType symbolType) {
        this.ident = ident;
        this.leftParent = leftParent;
        this.funcRParams = funcRParams;
        this.rightParent = rightParent;
        array = -1;
        this.symbolType = symbolType;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(ident.toString());
        sb.append(leftParent.toString());
        if (funcRParams != null) {
            sb.append(funcRParams);
        }
        sb.append(rightParent.toString());
        return sb.toString();
    }

    public void setArray(int array) {
        this.array = array;
    }

    @Override
    public int getArray() {
        return array;
    }

    @Override
    public int compute(SymbolList symbolList) {
        System.err.println("compute unaryFunction");
        return 0;
    }

    @Override
    public Symbol.SymbolType getSymbolType() {
        return symbolType == Symbol.SymbolType.CharFunc ? Symbol.SymbolType.Char :
                symbolType == Symbol.SymbolType.VoidFunc ? Symbol.SymbolType.VoidFunc : Symbol.SymbolType.Int;
    }
}
