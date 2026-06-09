package Symbol;

import Paser.CompUnit;
import Paser.Func.FuncRealParams;
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
    public static int isCircle = 0;
    public static int Dim = 1;
    public static Boolean canChange = Boolean.FALSE;


    public SymbolManager(Node root) {
        this.root = root;
        ((CompUnit) root).createSymbolTable();
    }

    // 跳出当前符号表
    public static void exitScope(Boolean isFunction, int line) {
        // 递归删除符号表，从最后开始，所有的与当前层级相同的符号表都会被删除，直到读到与当前层级不同的符号表
        // 使用迭代器删除
        if (isFunction) {
            // funcSymbol.checkReturn(line);
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
            ArrayList<Symbol> symbols = tmpTable.getSymbols();
            for (int i = 0; i < symbols.size(); i++) {
                if (symbols.get(i).getName().equals(name)) {
                    return true;
                }
            }
            tmpTable = tmpTable.getFatherTable();
        }
        return false;
    }

    public static Boolean checkParams(String name, FuncRealParams funcRParams, int line) {
        SymbolTable tmpTable = currentSymbolTable;
        FuncSymbol funcSymbol = null;
        while (tmpTable != null) {
            ArrayList<Symbol> symbols = tmpTable.getSymbols();
            for (int i = 0; i < symbols.size(); i++) {
                if (symbols.get(i).getName().equals(name)) {
                    funcSymbol = (FuncSymbol) symbols.get(i);
                    break;
                }
            }
            tmpTable = tmpTable.getFatherTable();
        }

        if (funcSymbol == null) {
            err += line + " c\n";// 函数未定义
            return false;
        }

        if (funcRParams == null) {
            if (!funcSymbol.getParams().isEmpty()) {
                err += line + " b\n";// 函数参数个数不匹配
                return false;
            }
            return true;
        }
        ArrayList<ValueType> params = funcSymbol.getParams();
        ArrayList<ValueType> children = funcRParams.getParamsType();
        if (params.size() != children.size()) {
            err += line + " d\n";// 函数参数个数不匹配
            return false;
        }
        for (int i = 0; i < params.size(); i++) {
            if (!valueTypeIsSimilar(params.get(i), children.get(i))) {
                err += line + " e\n";// 函数参数类型不匹配
                return false;
            }
        }
        return true;
    }

    public static ValueType name2valueType(String name,int line) {
        SymbolTable tmpTable = currentSymbolTable;
        while (tmpTable != null) {
            ArrayList<Symbol> symbols = tmpTable.getSymbols();
            for (int i = 0; i < symbols.size(); i++) {
                if (symbols.get(i).getName().equals(name)) {
                    return symbols.get(i).getType();
                }
            }
            tmpTable = tmpTable.getFatherTable();
        }
        err += line + " c\n";
        return null;
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
            ArrayList<Symbol> symbols = tmpTable.getSymbols();
            for (int i = 0; i < symbols.size(); i++) {
                if (symbols.get(i).getName().equals(name)) {
                    if (symbols.get(i) instanceof ConstSymbol && !canChange) {
                        err += line + " h\n";
                        return false;
                    } else {
                        return true;
                    }
                }
            }
            tmpTable = tmpTable.getFatherTable();
        }
        err += line + " c\n";
        return false;
    }

    public static Boolean valueTypeIsSimilar(ValueType v1, ValueType v2) {
        if (
                (v1 == ValueType.CHARARRAY && v2 == ValueType.INTARRAY) || (v1 == ValueType.INTARRAY && v2 == ValueType.CHARARRAY)
        ) {
            return Boolean.FALSE;
        }
        if (v1.isArray() != v2.isArray()) {
            return Boolean.FALSE;
        }
        return true;
    }

    public static void setIsCircle() {
        isCircle++;
    }

    public static void outCircle() {
        isCircle--;
    }

    public static Boolean isInCircle() {
        return isCircle == 1;
    }
}
