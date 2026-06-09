package llvm_part.values;

import llvm_part.IrType;
import parser_part.Ident;
import parser_part.declaration.Decl;
import parser_part.declaration.DeclComponent;
import parser_part.declaration.Def;
import parser_part.declaration.constance.ConstDef;
import parser_part.declaration.constance.ConstInitVal;
import parser_part.declaration.var.varDef.VarDef;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class IrGlobalDeclBuilder {
    private Decl decl;
    private SymbolList symbolList;

    public IrGlobalDeclBuilder(Decl decl, SymbolList symbolList) {
        this.decl = decl;
        this.symbolList = symbolList;
    }

    public ArrayList<IrGlobalDecl> buildGlobalDecls() {
        ArrayList<IrGlobalDecl> globalDecls = new ArrayList<>();
        DeclComponent declComponent = decl.getDeclComponent();
        globalDecls.add(toGLobalDecl(declComponent.getFirstDef()));
        for (Def def : declComponent.getDefs()) {
            globalDecls.add(toGLobalDecl(def));
        }
        return globalDecls;
    }

    public IrGlobalDecl toGLobalDecl(Def def) {
        Symbol symbol;
        Symbol.SymbolType symbolType = null;
        Ident ident = def.getIdent();
        int array = -1;
        ArrayList<Integer> initVal = new ArrayList<>();
        if (def instanceof ConstDef constDef) {
            if (constDef.getConstExps().isEmpty()) {
                symbolType = Symbol.SymbolType.ConstInt;
                array = 0;
            } else if (constDef.getConstExps().size() == 1) {
                symbolType = Symbol.SymbolType.ConstIntArray;
                array = 1;
            }
            setConstInitVal(constDef, array, initVal);
        } else if (def instanceof VarDef varDef) {
            if (varDef.getConstExps().isEmpty()) {
                symbolType = Symbol.SymbolType.Int;
                array = 0;
            } else if (varDef.getConstExps().size() == 1) {
                symbolType = Symbol.SymbolType.IntArray;
                array = 1;
            }
            //设置变量初值
            setVarInitVal(varDef, array, initVal);
        }
        symbol = new Symbol(ident.getLineIndex(), ident.getName(), symbolType, array);
        symbol.setInitVal(initVal);
        symbol.setGlobal(true);
        IrType irType = new IrType(IrType.DataType.I32);
        symbolList.addSymbol(symbol);
        boolean isConst = def instanceof ConstDef;
        return new IrGlobalDecl(symbol, irType, isConst);
    }

    public void setConstInitVal(ConstDef constDef, int array, ArrayList<Integer> initVal) {
        ConstInitVal constInitVal = constDef.getConstInitVal();
        if (!constInitVal.isArray() && array == 0) {
            initVal.add(constInitVal.getInitVal(symbolList));
        } else if (constInitVal.isArray() && array == 1) {
            int arrayLength = constDef.getConstExps().get(0).compute(symbolList);
            ArrayList<Integer> arrayInitVal = constInitVal.getArrayInitVals(symbolList);
            for (int i = 0; i < arrayLength; i++) {
                if (i < arrayInitVal.size()) {
                    initVal.add(arrayInitVal.get(i));
                } else {
                    initVal.add(0);
                }
            }
        }
    }

    public void setVarInitVal(VarDef varDef, int array, ArrayList<Integer> initVal) {
        // 形如int a, b[100];的无初始值的情况
        if (!varDef.hasInitVal()) {
            if (array == 0) {
                initVal.add(0);
            } else if (array == 1) {
                int arrayLength = varDef.getConstExps().get(0).compute(symbolList);
                for (int i = 0; i < arrayLength; i++) {
                    initVal.add(0);
                }
            }
        }
        // 形如int a = 0, b[100] = {1,2,3,4};的有初始值的情况
        else if (varDef.hasInitVal()) {
            if (array == 0) {
                initVal.add(varDef.getInitVal(symbolList));
            } else if (array == 1) {
                int arrayLength = varDef.getConstExps().get(0).compute(symbolList);
                ArrayList<Integer> arrayInitVal = varDef.getArrayInitVals(symbolList);
                for (int i = 0; i < arrayLength; i++) {
                    if (i < arrayInitVal.size()) {
                        initVal.add(arrayInitVal.get(i));
                    } else {
                        initVal.add(0);
                    }
                }
            }
        }
    }

}
