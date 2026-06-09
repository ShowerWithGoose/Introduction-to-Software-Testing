package frontend.IRBuilder.structure;

import frontend.syntax.Ast;
import type.BasicType;
import type.IntType;
import type.PointerType;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class SymTab extends Value {
    public HashMap<String, Symbol> symbolMap = new HashMap<>();
    public SymTab preSymTab;

    public SymTab() {
    }

    public SymTab(SymTab preSymTab) {
        this.preSymTab = preSymTab;
    }

    public void addSymbol(Symbol symbol) {
        if (symbolMap.containsKey(symbol.name)) {
            throw new RuntimeException("相同作用域内的重名对象");
        }
        symbolMap.put(symbol.name, symbol);
    }

    public Symbol getSymbol(String name) {
        if (symbolMap.containsKey(name)) {
            return symbolMap.get(name);
        }
        if (preSymTab != null) {
            return preSymTab.getSymbol(name);
        }
        throw new RuntimeException("未找到符号");
    }

    public List<Symbol> parseSymbolsForDecl(Ast.Decl decl) {
        ArrayList<Symbol> declSymList = new ArrayList<>();
        boolean constant = decl.isConst;
        for (Ast.ValueDef varDef : decl.valueDefList) {
            String name = varDef.name;
            if (symbolMap.containsKey(name)) {
                throw new RuntimeException("重名对象");
            }
            Value initVal;
            Ast.ValueInitVal initValAst = varDef.valueInitVal;
            if (initValAst != null) {
                initVal = createInitValWithInit(decl.type, varDef.exp, initValAst);
            } else if (varDef.exp != null) {
                initVal = new ArrayInitVal(decl.type, -1, false);
            } else if (preSymTab == null/*全局符号表*/) {
                initVal = new ConstInt(0);
            } else {
                initVal = null;
            }
            BasicType basicType = varDef.exp == null ? decl.type : new PointerType(decl.type);
            Symbol symbol = new Symbol(name, basicType, varDef.exp == null ? -1 : varDef.exp.getConstInt(this).value, constant, preSymTab == null, initVal);
            declSymList.add(symbol);
            if (preSymTab == null) {
                addSymbol(symbol);
            }
        }
        return declSymList;
    }

    public Value createInitValWithInit(BasicType type, Ast.Exp index, Ast.ValueInitVal initValAst) {
        if (initValAst.isNoStringArray) {
            ArrayInitVal arrayInitVal = new ArrayInitVal(type, initValAst.valueList.size(), true);
            for (Ast.Exp exp : initValAst.valueList) {
                arrayInitVal.initValueList.add(dealNoArrayOrStringInitVal(type, exp));
            }
            return arrayInitVal;
        } else if (initValAst.isString) {
            ArrayInitVal arrayInitVal = new ArrayInitVal(type, initValAst.stringConst.string.length() - 2, true);
            for (int i = 1; i < initValAst.stringConst.string.length() - 1; i++) {
                arrayInitVal.initValueList.add(new ConstChar(initValAst.stringConst.string.charAt(i)));
            }
            return arrayInitVal;
        } else {
            Ast.Exp exp = initValAst.valueList.get(0);
            if (exp.checkConst(this)) {
                return exp.getConstInt(this);
            } else {
                return new InitExp(exp);
            }
        }
    }

    public Value dealNoArrayOrStringInitVal(BasicType type, Ast.Exp exp) {
        if (exp.checkConst(this)) {
            return exp.getConstInt(this);
        } else {
            return new InitExp(exp);
        }

    }
}

