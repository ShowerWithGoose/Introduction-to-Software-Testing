package symbol_part;

import error_part.Error;
import parser_part.declaration.var.initVal.InitVal;

import java.util.ArrayList;
import java.util.Objects;

public class Symbol implements Comparable {
    private int lineIndex;
    private String name;
    private SymbolType symbolType;
    private ArrayList<Integer> value;
    private int array; // 0 -> 无数组  1 -> 一维数组 2 -> 二维数组
    // 函数symbol专用，统计用到的symbol数量
    private ArrayList<Symbol> paramSymbols;
    private ArrayList<Integer> initVal; // 数组初值
    //private ArrayList<Character> charInitVal; // char型数组初值
    private boolean isGlobal;
    private int fieldNumber;

    public Symbol(int lineIndex, String name, SymbolType symbolType, int array) {
        this.name = name;
        this.symbolType = symbolType;
        this.lineIndex = lineIndex;
        this.array = array;
        this.paramSymbols = new ArrayList<>();
        isGlobal = false;
        fieldNumber = -1;
    }

    public void setFieldNumber(int fieldNumber) {
        this.fieldNumber = fieldNumber;
    }

    public void setGlobal(boolean global) {
        isGlobal = global;
    }

    public int getLineIndex() {
        return lineIndex;
    }

    public String getName() {
        return name;
    }

    public SymbolType getSymbolType() {
        return symbolType;
    }

    public int getArray() {
        return array;
    }

    public void addFuncParamSymbol(Symbol symbol) {
        paramSymbols.add(symbol);
    }

    public ArrayList<Symbol> getParamSymbols() {
        return paramSymbols;
    }

    public ArrayList<Integer> getInitVal() {
        return initVal;
    }

    public void setInitVal(ArrayList<Integer> initVal) {
        this.initVal = initVal;
    }

    @Override
    public String toString() {
        if (isGlobal) {
            return "@" + name;
        } else {
            return "";
        }
    }

    @Override
    public int compareTo(Object o) {
        return this.fieldNumber - ((Symbol) o).fieldNumber;
    }

    public String analyzeOutput() {
        return fieldNumber + " " + name + " " + symbolType + "\n";
    }

    public enum SymbolType {
        ConstChar, ConstInt, ConstCharArray, ConstIntArray,
        Char, Int, CharArray, IntArray,
        VoidFunc, CharFunc, IntFunc;

        public boolean isFunc() {
            return this == VoidFunc || this == IntFunc || this == CharFunc;
        }

        public boolean isArray() {
            return this == CharArray || this == IntArray;
        }

        public boolean isConst() {
            return this == ConstChar || this == ConstInt || this == ConstCharArray || this == ConstIntArray;
        }

        public SymbolType ignoreConst(){
            if (this == ConstChar){
                return Char;
            }
            else if (this == ConstInt){
                return Int;
            }
            else if (this == ConstCharArray){
                return CharArray;
            }
            else if (this == ConstIntArray){
                return IntArray;
            } else {
                return this;
            }
        }
    }
}
