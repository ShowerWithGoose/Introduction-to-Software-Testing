package frontend.Symbol;


import frontend.IOManager;

import java.util.*;

public class SymbolTable
{
    private int id;
    private final Map<String,Symbol> symbols;
    private final SymbolTable pre;
    private final List<SymbolTable> next;

    public SymbolTable(int id, SymbolTable parent){
        this.id = id;
        this.symbols = new LinkedHashMap<>();
        this.pre = parent;
        this.next = new ArrayList<>();
    }

    public void AddChild(SymbolTable child){
        this.next.add(child);
    }

    public SymbolTable GetParent(){
        return this.pre;
    }

    public void AddSymbol(String name,Symbol symbol){
        if(!hasSymbol(name)){
            this.symbols.put(name,symbol);
        }
        else{
            //TODO ERROR
        }
    }

    public int getId() {
        return id;
    }

    public boolean hasSymbol(String name){
        return symbols.containsKey(name);
    }

    public Symbol GetSymbol(String name){
        return symbols.get(name);
    }

    public List<SymbolTable> getChildren() {
        return next;
    }

    public void PrintSymbols(){
        for (String name : symbols.keySet()) {
            Symbol symbol = symbols.get(name);
            IOManager.Write(symbol.getTableID() + " " + name + " " + symbol.getSymbolType().toString(), true);
        }
    }
}
