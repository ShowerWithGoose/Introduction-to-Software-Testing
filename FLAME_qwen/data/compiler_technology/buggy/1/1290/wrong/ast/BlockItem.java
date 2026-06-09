package ast;

import semantic.FuncInfo;
import semantic.SymbolTable;

public class BlockItem extends Symbol {

    private boolean returned = false;

    public static Symbol of(String dir, SymbolTable table, FuncInfo info, boolean loop) {
        Symbol symbol;
        BlockItem blockItem = new BlockItem();
        if ((symbol = Decl.of(dir, table)) != null) {
            blockItem.add(symbol);
            return blockItem;
        }
        if ((symbol = Stmt.of(dir, table, info, loop)) != null) {
            blockItem.add(symbol);
            if (((Stmt) symbol).getReturned()) {
                blockItem.returned = true;
            }
            return blockItem;
        }
        return null;
    }

    @Override
    public String toString() {
        return "";
    }

    public boolean isReturned() {
        return returned;
    }

}
