package Paser;

import Paser.Func.FuncDef;
import Paser.Func.MainFuncDef;
import Symbol.FuncSymbol;
import Symbol.SymbolManager;
import Symbol.SymbolTable;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

// CompUnit â†’ {Decl} {FuncDef} MainFuncDef
public class CompUnit extends Node {
    public CompUnit(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    @Override
    public void createSymbolTable() {
        SymbolManager.currentSymbolTable = new SymbolTable(null,SymbolManager.Dim++);
        SymbolManager.topTable = SymbolManager.currentSymbolTable;
        for (Node child : children) {
            if (child instanceof FuncDef) {
                ((FuncDef) child).createSymbolTable();
            } else if (child instanceof MainFuncDef) {
                // SymbolManager.funcSymbol = new FuncSymbol("main", ValueType.INT, 1, startLine);
                // SymbolManager.currentSymbolTable.addSymbol(SymbolManager.funcSymbol);
                ((MainFuncDef) child).createSymbolTable();
            } else {
                child.createSymbolTable();
            }
        }
    }
}
