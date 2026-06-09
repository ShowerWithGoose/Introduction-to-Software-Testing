package frontend.semantic;

import java.util.ArrayList;

public class SymbolTable {
    public int id; 		// 当前符号表的id。
    public int parentId; 	// 外层符号表的id。
    public ArrayList<Symbol> directory = new ArrayList<>();

    public SymbolTable(int id, int parentId) {
        this.id = id;
        this.parentId = parentId;
    }

    public int getId() {
        return id;
    }

    public int getParentId() {
        return parentId;
    }

    public Symbol addAndReturnSymbol(String name, Type type, BType btype, boolean isConst) {
        Symbol symbol;
        if (type == Type.FUNC) {
            symbol = new FuncSymbol(id, name, btype, isConst);
        } else if (type == Type.VAR) {
            symbol = new VarSymbol(id,  name, btype, isConst);
        } else {
            symbol = new ArraySymbol(id, name, btype, isConst);
        }
        directory.add(symbol);
        return symbol;
    }

    public Symbol getSymbol(String name) {
        for (Symbol symbol : directory) {
            if (symbol.getName().equals(name)) {
                return symbol;
            }
        }
        return null;
    }

    public ArrayList<Symbol> getSymbols() {
        return directory;
    }
}