package Utils.SymbolTable;

import Utils.*;

public class LoopSymbolTable extends SymbolTable {
    public LoopSymbolTable(SymbolTable parent) { super(parent); }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Pair<Token, SymbolType> symbol : symbols)
            sb
            .append(depth)
            .append(" ")
            .append(symbol.first().getValue())
            .append(" ")
            .append(symbol.second())
            .append("\n");
        for (SymbolTable child : children) sb.append(child.toString());
        return sb.toString();
    }
}
