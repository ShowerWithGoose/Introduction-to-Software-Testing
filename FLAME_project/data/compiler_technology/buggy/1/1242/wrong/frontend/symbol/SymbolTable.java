package frontend.symbol;

import frontend.Category.TokenList;
import frontend.Error.Error;
import frontend.Error.ErrorMap;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class SymbolTable {
    private static HashMap<Integer,ArrayList<Symbol>> symbolTable = new HashMap<>();

    private static HashMap<Integer, HashMap<String,Symbol>> symbolName = new HashMap<>();


    public static void AddSymbol(Symbol symbol) {
        if (symbolTable.containsKey(symbol.GetScope())) {
            if (symbolName.get(symbol.GetScope()).containsKey(symbol.GetName())) {
                ErrorMap.AddError(new Error(symbol.GetLine(),'b'));
                return;
            }
            symbolTable.get(symbol.GetScope()).add(symbol);
            symbolName.get(symbol.GetScope()).put(symbol.GetName(),symbol);
        } else {
            ArrayList symbolList = new ArrayList<>();
            symbolList.add(symbol);
            symbolTable.put(symbol.GetScope(),symbolList);
            HashMap<String,Symbol> nameSet = new HashMap<>();
            nameSet.put(symbol.GetName(),symbol);
            symbolName.put(symbol.GetScope(),nameSet);
        }
    }

    public static void AddSymbolToFirst(Symbol symbol) {
        if (symbolTable.containsKey(symbol.GetScope())) {
            if (symbolName.get(symbol.GetScope()).containsKey(symbol.GetName())) {
                ErrorMap.AddError(new Error(symbolName.get(symbol.GetScope()).get(symbol.GetName()).GetLine(),'b'));
                symbolName.get(symbol.GetScope()).get(symbol.GetName()).SetLine(symbol.GetLine());
                return;
            }
            symbolTable.get(symbol.GetScope()).add(0,symbol);
            symbolName.get(symbol.GetScope()).put(symbol.GetName(),symbol);
        } else {
            ArrayList symbolList = new ArrayList<>();
            symbolList.add(0,symbol);
            symbolTable.put(symbol.GetScope(),symbolList);
            HashMap<String,Symbol> nameSet = new HashMap<>();
            nameSet.put(symbol.GetName(),symbol);
            symbolName.put(symbol.GetScope(),nameSet);
        }
    }

    public static boolean HaveDefine(int scope,String name) {
        if (symbolName.containsKey(scope)) {
            if (symbolName.get(scope).containsKey(name)) {
                return true;
            }
        }
        return false;
    }

    public static SymbolType Type(int scope,String name) {
        return symbolName.get(scope).get(name).GetType();
    }

    public static int GetParamsNumber(int scope,String name) {
        return ((FuncSymbol)symbolName.get(scope).get(name)).GetParamsNumber();
    }

    public static ArrayList<SymbolType> GetParamsType(int scope,String name) {
        return ((FuncSymbol)symbolName.get(scope).get(name)).GetparamsType();
    }
    public static void Print() {
        try {
            BufferedWriter symbol = new BufferedWriter(new FileWriter("symbol.txt"));
            for (int i = 1;i <= TokenList.GetScopeNumber();i++) {
                if (symbolTable.containsKey(i)) {
                    for (int j = 0;j < symbolTable.get(i).size();j++) {
                        symbol.write(symbolTable.get(i).get(j).toString() + "\n");
                    }
                }
            }
            symbol.flush();
        } catch (IOException e) {
            System.out.println("can not find symbol.txt");
        }
    }
}
