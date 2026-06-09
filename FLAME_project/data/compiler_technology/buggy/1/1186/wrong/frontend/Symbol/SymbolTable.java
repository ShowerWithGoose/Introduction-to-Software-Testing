package frontend.Symbol;

import java.util.ArrayList;
import java.util.Map;
import java.util.Stack;

public class SymbolTable {
    Stack<SymbolLayer> scopes;
    int scopeNum;
    private ArrayList<Symbol> symbolList;

    public SymbolTable(ArrayList<Symbol> symbolList) {
        this.scopes = new Stack<>();
        this.scopeNum = 1;
        this.symbolList = symbolList;
        enterNewScope();
    }

    public void addSymbol(String name, String type) {
        int currentNum = scopes.peek().getNum();
        Symbol symbol = new Symbol(name, type, currentNum);
        // System.out.println(symbol.toString());
        symbolList.add(symbol);
        scopes.peek().addSymbol(name, symbol);
    }

    public boolean layerLookUpSymbol(String name) {
        Map<String, Symbol> symbols = scopes.peek().getSymbols();
        return symbols.containsKey(name); // 真有错
    }

    public boolean allLookUpSymbol(String name) {
        for (SymbolLayer symbolLayer : scopes) {
            Map<String, Symbol> symbols = symbolLayer.getSymbols();
            if (symbols.containsKey(name) && symbols.get(name).getType().contains("Const")) {
                return true; // 真有错
            }
        }
        return false;
    }

    public void enterNewScope() {
        SymbolLayer symbolLayer = new SymbolLayer(scopeNum);
        scopes.push(symbolLayer);
        scopeNum++;
    }

    public void exitScope() {
        scopes.pop();
    }

}
