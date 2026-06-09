package Utils.SymbolTable;

import java.util.*;

import Utils.Pair;
import Utils.Token;

public class SymbolTable {
    public SymbolTable parent = null;
    public ArrayList<SymbolTable> children = new ArrayList<>();
    protected HashSet<String> symbolNames = new HashSet<>();
    public ArrayList<Pair<Token, SymbolType>> symbols = new ArrayList<>();
    protected static int depth = 0;

    public SymbolTable(SymbolTable parent) {
        this.parent = parent;
        if (parent != null) parent.children.add(this);
    }

    public void addSymbol(Token token, SymbolType type) throws SymbolAlreadyExistsException {
        String name = (String)token.getValue();
        if (symbolNames.contains(name)) throw new SymbolAlreadyExistsException(name);
        symbolNames.add(name);
        symbols.add(new Pair<>(token, type));
    }

    public SymbolType getSymbolType(Token token) throws SymbolNotFoundException {
        String name = (String)token.getValue();
        for (Pair<Token, SymbolType> symbol : symbols)
            if (symbol.first().getValue().equals(name))
                return symbol.second();
        if (parent != null) return parent.getSymbolType(token);
        throw new SymbolNotFoundException(name);
    }

    public enum SymbolType {
        ConstChar,
        ConstInt,
        ConstCharArray,
        ConstIntArray,
        Char,
        Int,
        CharArray,
        IntArray,
        VoidFunc,
        CharFunc,
        IntFunc;

        @Override
        public String toString() { return this.name(); }

        public static SymbolType fromString(String str, boolean isFunc, boolean isConst, boolean isArray) {
            str = str.substring(0, 1) + str.substring(1, str.length() - 2).toLowerCase();
            if (isFunc) str = str + "Func";
            else if (isArray) str = str + "Array";
            if (isConst) str = "Const" + str;
            return SymbolType.valueOf(str);
        }

        public boolean isArray() {
            return this == CharArray || this == IntArray || this == ConstCharArray || this == ConstIntArray;
        }
        public boolean isArray(boolean hasBrackets) {
            if (hasBrackets) return false;
            return this == CharArray || this == IntArray || this == ConstCharArray || this == ConstIntArray;
        }

        public boolean isCharArray() {
            return this == CharArray || this == ConstCharArray;
        }
    }

    @Override
    public String toString() {
        depth++;
        StringBuilder sb = new StringBuilder();
        for (Pair<Token, SymbolType> symbol : symbols)
            sb
            .append(depth)
            .append(" ")
            .append(symbol.first().getValue())
            .append(" ")
            .append(symbol.second())
            .append("\n");
        for (SymbolTable child : children)
            sb.append(child.toString());
        return sb.toString();
    }

    public static class SymbolNotFoundException extends Exception {
        public SymbolNotFoundException(String name) { super("Symbol not found: " + name); }
    }

    public static class SymbolAlreadyExistsException extends Exception {
        public SymbolAlreadyExistsException(String name) { super("Symbol already exists: " + name); }
    }
}
