package frontend.Symbol;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class SymbolTree {
    private HashMap<String, Symbol> symbols;
    private ArrayList<Symbol> symbolArrayList;
    private ArrayList<SymbolTree> child;
    private SymbolTree parent;

    private int id = 1;

    public SymbolTree() {
        symbols = new HashMap<>();
        symbolArrayList = new ArrayList<>();
        child = new ArrayList<>();
        parent = null;
    }

    public void setParent(SymbolTree parent) {
        this.parent = parent;
    }

    public void addSymbol(Symbol symbol) {
        symbols.put(symbol.getIdent(), symbol);
        symbolArrayList.add(symbol);
    }

    public SymbolTree generateChild(int id) {
        SymbolTree child1 = new SymbolTree();
        child1.setId(id);
        child1.setParent(this);
        child.add(child1);
        return child1;
    }

    public SymbolTree getParent() {
        return parent;
    }

    public void printTree(BufferedWriter writer) throws IOException {
        for (Symbol symbol : symbolArrayList) {
            symbol.print(writer);
        }
        for (SymbolTree symbolTree : child) {
            symbolTree.printTree(writer);
        }
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public boolean checkB(String ident) {
        return symbols.containsKey(ident);
    }

    public boolean checkC(String ident) {
        if (symbols.containsKey(ident)) {
            return true;
        } else {
            if (parent == null) {
                return false;
            } else {
                return parent.checkC(ident);
            }
        }
    }

    public int checkD(String ident) {
        return symbols.get(ident).getParamNum();
    }

    public boolean checkH(String ident) {
        if (symbols.containsKey(ident)) {
            return symbols.get(ident).isConst();
        } else {
            if (parent == null) {
                return false;
            } else {
                return parent.checkH(ident);
            }
        }
    }

    public Symbol getSymbol(String symbol) {
        if (symbols.containsKey(symbol)) {
            return symbols.get(symbol);
        } else {
            return null;
        }
    }

    public Symbol getSymbolAll(String ident) {
        if (symbols.containsKey(ident)) {
            return symbols.get(ident);
        } else {
            if (parent == null) {
                return null;
            } else {
                return parent.getSymbolAll(ident);
            }
        }
    }
}
