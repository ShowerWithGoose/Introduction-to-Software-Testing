package frontend.IRBuilder.structure;

import type.BasicType;
import frontend.syntax.Ast;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Function extends Value {
    public String name;
    public BasicType returnType;
    public Procedure procedure;
    public ArrayList<IRParam> IRParamList;
    public static final HashMap<String, Function> canCallMap = new HashMap<>();

    public Function(Ast.FuncDef funcDef, SymTab preSymTab) {
        name = funcDef.name;
        returnType = funcDef.type;
        SymTab curSymTab = new SymTab(preSymTab);
        canCallMap.put(name, this);
        procedure = new Procedure(returnType, funcDef.paramList, funcDef.block, curSymTab, IRParamList);
    }

    public static Function getFunction(String name) {
        return canCallMap.get(name);
    }
}
