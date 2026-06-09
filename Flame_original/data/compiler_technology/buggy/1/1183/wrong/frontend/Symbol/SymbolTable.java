package frontend.Symbol;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class SymbolTable {
    private int id; // 符号表序号
    private int level;
    private SymbolTable parentTable;
    private ArrayList<SymbolTable> childTable;
    private ArrayList<Symbol> symbolTable;

    public SymbolTable() {
        this.id = 1;
        this.level = 1;
        this.parentTable = null;
        this.childTable = new ArrayList<>();
        this.symbolTable = new ArrayList<>();
    }

    public SymbolTable(int id, int level, SymbolTable parentTable) {
        this.id = id;
        this.level = level;
        this.parentTable = parentTable;
        this.childTable = new ArrayList<>();
        this.symbolTable = new ArrayList<>();
    }

    public SymbolTable getParentTable() {
        return parentTable;
    }

    public void addChildTable(SymbolTable childTable) {
        this.childTable.add(childTable);
    }

    public ArrayList<SymbolTable> getChildTable() {
        return childTable;
    }

    public ArrayList<Symbol> getSymbolTable() {
        return symbolTable;
    }

    public int getId() {
        return id;
    }

    public boolean isConst(String id) {
        for (Symbol symbol : symbolTable) {
            if (symbol.getId().equals(id) && symbol.isConst()) {
                return true;
            }
            else if (symbol.getId().equals(id)) {
                return false;
            }
        }
        if (parentTable != null) {
            return parentTable.isConst(id);
        }
        else {
            return false;
        }
    }

    public boolean isRedefined(String id) {
        for (Symbol sym : symbolTable) {
            if (sym.getId().equals(id)) {
                return true;
            }
        }
        return false;
    }

    public boolean unDefined(String id) { // 未定义的符号
        for (Symbol sym : symbolTable) {
            if (sym.getId().equals(id)) {
                return false;
            }
        }
        if (parentTable != null) {
            return parentTable.unDefined(id);
        }
        else {
            return true;
        }
    }

    public void addSymbol(Symbol symbol) {
        symbolTable.add(symbol);
    }

    public void print(BufferedWriter writer) {
        if (!symbolTable.isEmpty()) {
            for (Symbol sym : symbolTable) {
                try {
                    writer.write(sym.toString());
                    writer.newLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        for (SymbolTable symTable : childTable) {
            symTable.print(writer);
        }
    }

    public Symbol getSymbol(String id) {
        for (Symbol sym : symbolTable) {
            if (sym.getId().equals(id)) {
                return sym;
            }
        }
        if (parentTable != null) {
            return parentTable.getSymbol(id);
        }
        else {
            return null;
        }
    }
}
