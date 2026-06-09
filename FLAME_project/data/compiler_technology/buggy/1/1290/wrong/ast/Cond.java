package ast;

import semantic.SymbolTable;

public class Cond extends Symbol {

    public static Symbol of(SymbolTable table) {
        Symbol cond = new Cond();
        Symbol symbol;
        if ((symbol = LOrExp.of(table)) == null) {
            return null;
        }
        cond.add(symbol);
        return cond;
    }

}
