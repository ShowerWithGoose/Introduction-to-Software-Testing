package frontend;

import java.util.HashMap;

public class SymbolTable {
    private HashMap<String, Symbol> items;
    private SymbolTable fore_table;

    public SymbolTable(SymbolTable fore_table) {
        this.items = new HashMap<>();
        this.fore_table = fore_table;
    }

    public void addItem(String string, Symbol symbol) {
        items.put(string, symbol);
    }

    public HashMap<String, Symbol> getItems() {
        return items;
    }

    public SymbolTable getFore_table() {
        return fore_table;
    }
}
