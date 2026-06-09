package Utils.SymbolTable;

import java.util.*;

import Utils.Token;

public class MainSymbolTable extends SymbolTable {
    public HashMap<String, FuncSymbolTable> funcs = new HashMap<>();

    public MainSymbolTable() { super(null); }

    public void addFunc(Token token, FuncSymbolTable table) throws SymbolAlreadyExistsException {
        String name = (String)token.getValue();
        funcs.put(name, table);
    }
}
