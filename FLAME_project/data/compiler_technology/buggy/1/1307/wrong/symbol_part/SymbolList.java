package symbol_part;

import java.util.HashMap;
import java.util.LinkedList;

public class SymbolList {
    private HashMap<String, Symbol> symbols;
    private LinkedList<Symbol> symbolLinkedList;

    private SymbolList parent;
    private LinkedList<SymbolList> children;
    private int cycleDepth;
    private final int fieldNumber;
    public static int fieldCounter = 0;

    public SymbolList() {
        symbols = new HashMap<>();
        symbolLinkedList = new LinkedList<>();
        children = new LinkedList<>();
        parent = null;
        cycleDepth = 0;
        fieldCounter++;
        fieldNumber = fieldCounter;
    }

    public SymbolList(SymbolList parent) {
        this.symbols = new HashMap<>();
        symbolLinkedList = new LinkedList<>();
        this.children = new LinkedList<>();
        parent.children.add(this);
        this.parent = parent;
        cycleDepth = parent.cycleDepth;
        fieldCounter++;
        fieldNumber = fieldCounter;
    }

    public static SymbolList sharedSymbolList = new SymbolList();

    public int getFieldNumber() {
        return fieldNumber;
    }

    public void setCycleDepth(int cycleDepth) {
        this.cycleDepth = cycleDepth;
    }


    public void addSymbol(Symbol symbol) {
        symbols.put(symbol.getName(), symbol);
        symbolLinkedList.add(symbol);
    }

    public boolean containSymbol(Symbol symbol) {
        return symbols.containsKey(symbol.getName());
    }

    public boolean containSymbol(String name) {
        return symbols.containsKey(name);
    }

    public Symbol getSymbol(String name) {
        if (symbols.containsKey(name)) {
            return symbols.get(name);
        } else if (parent != null) {
            return parent.getSymbol(name);
        }
        return null;
    }

    public int getCycleDepth() {
        return cycleDepth;
    }

    public boolean hasUndefinedIdent(String name) {
        if (symbols.containsKey(name)) {
            return false;
        }
        if (parent != null) {
            return parent.hasUndefinedIdent(name);
        } else {
            return true;
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Symbol symbol: symbolLinkedList){
            sb.append(symbol.analyzeOutput());
        }
        for (SymbolList symbolList: children){
            sb.append(symbolList.toString());
        }
        return sb.toString();
    }
}
