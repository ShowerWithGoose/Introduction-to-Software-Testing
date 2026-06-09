package parser_part.expression;

import parser_part.Node;
import symbol_part.Symbol;
import symbol_part.SymbolList;

public interface Computable extends Node {
    int compute(SymbolList symbolList);
    Symbol.SymbolType getSymbolType();
}
