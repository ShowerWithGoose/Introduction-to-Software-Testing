package frontend;

import frontend.SymbolPackage.Symbol;

import java.util.ArrayList;
import java.util.HashMap;

public class SymbolTable {
    private int id;//当前符号表的编号
    private int fatherId;//外一层符号表的编号, 若为0则表明当前符号表处在最外层
    private ArrayList<Symbol> directory;

    public SymbolTable(int id, int fatherId) {
        this.id = id;
        this.fatherId = fatherId;
        this.directory = new ArrayList<>();
    }

    public void addSymbol(Symbol symbol) {
        this.directory.add(symbol);
    }

    public boolean isEmpty() {
        return directory.isEmpty();
    }

    public ArrayList<Symbol> getDirectory() {
        return directory;
    }

    public boolean isContainIdent(String name) {
        for (Symbol symbol : this.directory) {
            if (symbol.getName().equals(name)) {
                return true;
            }
        }
        return false;
    }

    public int getFatherId() {
        return fatherId;
    }
}
