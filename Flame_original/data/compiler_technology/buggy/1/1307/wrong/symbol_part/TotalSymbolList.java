package symbol_part;

import java.util.TreeSet;

public class TotalSymbolList {
    private TreeSet<Symbol> symbolTreeSet;

    public TotalSymbolList() {
        this.symbolTreeSet = new TreeSet<>();
    }

    public void addSymbol(Symbol symbol){
        symbolTreeSet.add(symbol);
    }

    public static TotalSymbolList totalSymbolList = new TotalSymbolList();

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Symbol symbol : symbolTreeSet) {
            sb.append(symbol.analyzeOutput());
        }
        return sb.toString();
    }
}
