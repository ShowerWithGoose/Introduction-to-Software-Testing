package Symbol;

import Paser.CompUnit;
import Paser.Node;

import java.util.ArrayList;

public class SymbolManager {
    public static FuncSymbol funcSymbol = null;
    // public static int currentLevel = 0;
    private Node root;
    public static String ans = "";
    // public static ArrayList<Symbol> symbols = new ArrayList<>();
    public static SymbolTable currentSymbolTable = null;
    public static String err = "";
    public static SymbolTable topTable = null;


    public SymbolManager(Node root) {
        this.root = root;
    }

    public void buildSymbolTable() {
        ((CompUnit)root).createSymbolTable();
    }

    // 跳出当前符号表
    public static void exitScope(Boolean isFunction, int line) {
        // 递归删除符号表，从最后开始，所有的与当前层级相同的符号表都会被删除，直到读到与当前层级不同的符号表
        // 使用迭代器删除
        if (isFunction) {
            funcSymbol.checkReturn(line);
            funcSymbol = null;
        }
        currentSymbolTable.getFatherTable().addChild(currentSymbolTable);
        currentSymbolTable = currentSymbolTable.getFatherTable();
    }

    public static void exitScope() {
        currentSymbolTable.getFatherTable().addChild(currentSymbolTable);
        currentSymbolTable = currentSymbolTable.getFatherTable();
    }

    public static boolean hasName(String name) {
        SymbolTable tmpTable = currentSymbolTable;
        while (tmpTable != null) {
            ArrayList<Symbol> symbols = currentSymbolTable.getSymbols();
            for (int i = 0; i < symbols.size(); i++) {
                if (symbols.get(i).getName().equals(name)) {
                    return true;
                }
            }

            tmpTable = tmpTable.getFatherTable();
        }
        return false;
    }

    public static boolean hasNameInSameDim(String name) {
        ArrayList<Symbol> symbols = currentSymbolTable.getSymbols();
        for (int i = 0; i < symbols.size(); i++) {
            if (symbols.get(i).getName().equals(name)) {
                return true;
            }
        }
        return false;
    }

    public static Boolean hasLval(String name, int line) {
        SymbolTable tmpTable = currentSymbolTable;
        while (tmpTable != null) {
            ArrayList<Symbol> symbols = currentSymbolTable.getSymbols();
            for (int i = 0; i < symbols.size(); i++) {
                if (symbols.get(i).getName().equals(name)) {
                    if (symbols.get(i) instanceof ConstSymbol) {
                        err = line + " a\n";
                        return false;
                    } else {
                        return true;
                    }
                }
            }
            tmpTable = tmpTable.getFatherTable();
        }
        err = line + " c\n";
        return false;
    }
}
