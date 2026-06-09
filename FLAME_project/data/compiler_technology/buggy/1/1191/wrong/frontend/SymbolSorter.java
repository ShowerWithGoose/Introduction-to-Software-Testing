package frontend;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class SymbolSorter {
    public static void sortSymbolsByScope(ArrayList<Symbol> symbols) {
        Collections.sort(symbols, new Comparator<Symbol>() {
            @Override
            public int compare(Symbol s1, Symbol s2) {
                return Integer.compare(s1.getScope(), s2.getScope());
            }
        });
    }
}

