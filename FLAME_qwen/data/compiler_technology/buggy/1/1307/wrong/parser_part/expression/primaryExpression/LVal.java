package parser_part.expression.primaryExpression;

import java.util.ArrayList;
import java.util.HashMap;

import lexer_part.Token;
import parser_part.Ident;
import parser_part.expression.Computable;
import parser_part.expression.Exp;
import symbol_part.Symbol;
import symbol_part.SymbolList;

public class LVal implements PrimaryExpComponent, Computable {
    private String name;
    private Ident ident;
    private ArrayList<Token> leftBrackets; //  '['
    private ArrayList<Exp> exps;
    private ArrayList<Token> rightBrackets; //  ']'
    private Symbol.SymbolType symbolType = null;
    private int dimension;

    private boolean isAssign;
    private boolean isGlobal;
    private boolean undefined;
    private HashMap<Symbol.SymbolType, Symbol.SymbolType> array2Int;

    public LVal(Ident ident, ArrayList<Token> leftBrackets, ArrayList<Exp> exps, ArrayList<Token> rightBrackets) {
        this.ident = ident;
        this.leftBrackets = leftBrackets;
        this.exps = exps;
        this.rightBrackets = rightBrackets;
        this.name = "<LVal>";
        this.isAssign = false;
        isGlobal = false;
        undefined = false;
        array2Int = new HashMap<>();
        array2Int.put(Symbol.SymbolType.ConstCharArray, Symbol.SymbolType.ConstChar);
        array2Int.put(Symbol.SymbolType.ConstIntArray, Symbol.SymbolType.ConstInt);
        array2Int.put(Symbol.SymbolType.CharArray, Symbol.SymbolType.Char);
        array2Int.put(Symbol.SymbolType.IntArray, Symbol.SymbolType.Int);
    }

    public boolean isGlobal() {
        return isGlobal;
    }

    public void setAssign(boolean assign) {
        isAssign = assign;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(ident.toString());
        int len = exps.size();
        for (int i = 0; i < len; i++) {
            sb.append(leftBrackets.get(i));
            sb.append(exps.get(i));
            sb.append((rightBrackets.get(i)));
        }
        sb.append(name).append("\n");
        return sb.toString();
    }

    public void setSymbolType(Symbol.SymbolType symbolType) {
        this.symbolType = symbolType;
    }

    public Symbol.SymbolType getSymbolType() {
        if (symbolType.isArray() && !leftBrackets.isEmpty()) {
            return array2Int.get(symbolType);
        } else {
            return symbolType;
        }
    }

    public int getLineIndex() {
        return ident.getLineIndex();
    }

    @Override
    public int getArray() {
        if (isUndefined()) {
            return -1;
        }
        if (symbolType.isArray()) {
            dimension = 1;
        } else if (!symbolType.isFunc()) {
            dimension = 0;
        }
        return dimension - leftBrackets.size();
    }

    public boolean isConstVar() {
        return symbolType != null && symbolType.isConst();
    }

    @Override
    public int compute(SymbolList symbolList) {
        Symbol symbol = symbolList.getSymbol(ident.getName());
        int arrayIndex = exps.isEmpty() ? 0 : exps.get(0).compute(symbolList);
        return symbol.getInitVal().get(arrayIndex);
    }

    public void setUndefined(boolean undefined) {
        this.undefined = undefined;
    }

    public boolean isUndefined() {
        return undefined;
    }

}
