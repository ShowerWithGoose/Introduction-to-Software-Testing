package ast;

import semantic.SymbolTable;

public class Decl extends Symbol {

    public static Symbol of(String dir, SymbolTable table) {
        Symbol symbol;
        if ((symbol = ConstDecl.of(table)) != null) {
            Decl decl = new Decl();
            decl.add(symbol);
            return decl;
        }
        if ((symbol = VarDecl.of(table)) != null) {
            Decl decl = new Decl();
            decl.add(symbol);
            return decl;
        }
        return null;
    }

    @Override
    public String toString() {
        return "";
    }



}
