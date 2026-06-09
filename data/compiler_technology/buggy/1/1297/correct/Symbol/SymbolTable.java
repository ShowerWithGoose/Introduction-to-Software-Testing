package Symbol;

import java.util.ArrayList;

public class SymbolTable implements SymbolChild {
    private ArrayList<Symbol> symbols;
    private int dim = 1;
    private ArrayList<SymbolTable> children;
    private SymbolTable fatherTable;
    private ArrayList<SymbolChild> symbolChildren = new ArrayList<>();

    public SymbolTable(SymbolTable fatherTable, int dim) {
        this.fatherTable = fatherTable;
        this.dim = dim;
        this.symbols = new ArrayList<>();
        this.children = new ArrayList<>();
    }

    public void addSymbol(Symbol symbol) {
        symbols.add(symbol);
        symbolChildren.add(symbol);
    }

    public void addChild(SymbolTable table) {
        symbolChildren.add(table);
        children.add(table);
    }

    public void setSymbols(ArrayList<Symbol> symbols) {
        this.symbols = symbols;
    }

    public ArrayList<Symbol> getSymbols() {
        return symbols;
    }

    public void setTable(ArrayList<SymbolTable> tables) {
        this.children = tables;
    }

    public String toString() {
        StringBuffer sb = new StringBuffer();
        for (Symbol s : symbols) {
            sb.append(s.toString());
        }
        for (SymbolTable t : children) {
            sb.append(t.toString());
        }
        return sb.toString();
    }

    public SymbolTable getFatherTable() {
        return fatherTable;
    }


    public int getDim() {
        return dim;
    }
}
