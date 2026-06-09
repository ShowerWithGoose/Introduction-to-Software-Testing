package frontend;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Stack;

public class SymbolTable {
    public int id;      //当前符号表id
    public int fatherId;//外层符号表id
    public HashMap<String, Symbol> symbols = new HashMap<>();

    public SymbolTable(int id, int fatherId) {
        this.id = id;
        this.fatherId = fatherId;
    }



    public boolean addSymbol(Symbol symbol, Stack<SymbolTable> stack) {
        HashMap<String, Symbol> current = stack.peek().symbols;
        if (current.containsKey(symbol.name)) {
            return false;
        } else {
            current.put(symbol.name, symbol);
            return true;
        }
    }

    public Symbol getSymbol(String name, Stack<SymbolTable> stack) {
        for (int i = stack.size() - 1; i >= 0; i--) {
            HashMap<String, Symbol> current = stack.get(i).symbols;
            if (current.containsKey(name)) {
                return current.get(name);
            }
        }
        return null;
    }

    public int getId() {
        return id;
    }

    public List<Symbol> getSymbols(Stack<SymbolTable> stack) {
        List<Symbol> symbols = new ArrayList<>();
        for (SymbolTable current : stack) {
            symbols.addAll(current.symbols.values());
        }
        return symbols;
    }
}
