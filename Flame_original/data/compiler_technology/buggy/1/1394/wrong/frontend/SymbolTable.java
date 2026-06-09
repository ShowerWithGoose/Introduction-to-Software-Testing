package frontend;

import java.util.HashMap;

public class SymbolTable {
    private int tableLevel;
    private int fatherTableLevel;
    private HashMap<String, Symbol> symbolTable;

    public SymbolTable(int tableLevel, int fatherTableLevel){
        this.tableLevel = tableLevel;
        this.fatherTableLevel = fatherTableLevel;
        symbolTable = new HashMap<String, Symbol>();
    }
    public int getTableLevel(){
        return tableLevel;
    }
    public int getFatherTableLevel(){
        return fatherTableLevel;
    }
}
