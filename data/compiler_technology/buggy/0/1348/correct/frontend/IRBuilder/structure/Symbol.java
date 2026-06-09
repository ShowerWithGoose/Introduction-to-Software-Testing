package frontend.IRBuilder.structure;

import type.BasicType;
import type.VoidType;

public class Symbol {
    public String name;
    public BasicType type;
    public Value allocValue;
    public int arraySize;
    public boolean isConst;
    public boolean isGlobal;
    public Value initVal;
    public boolean isVoid = false;

    public Symbol(String name, BasicType type, int arraySize, boolean constant, boolean global, Value initVal) {
        this.name = name;
        this.type = type;
        this.arraySize = arraySize;
        this.isConst = constant;
        this.isGlobal = global;
        this.initVal = initVal;
        if (global) {
            this.allocValue = new GlobalVar(name, type);
        } else {
            this.allocValue = null;
        }
    }

    public Symbol(boolean isVoid) {
        this.name = "";
        this.type = new VoidType();
        this.isVoid = isVoid;
    }

}
