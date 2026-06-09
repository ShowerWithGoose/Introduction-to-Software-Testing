package Paser;

import Paser.Func.FuncDef;
import Paser.Func.MainFuncDef;
import Symbol.SymbolManager;
import Symbol.SymbolTable;
import Type.SyntaxVarType;

import java.util.ArrayList;

// CompUnit â†’ {Decl} {FuncDef} MainFuncDef
public class CompUnit extends Node {
    public CompUnit(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    @Override
    public void createSymbolTable() {
        SymbolManager.currentSymbolTable = new SymbolTable(null,1);
        SymbolManager.topTable = SymbolManager.currentSymbolTable;
        for (Node child : children) {
            if (child instanceof FuncDef) {
                ((FuncDef) child).createSymbolTable();
            } else if (child instanceof MainFuncDef) {
                ((MainFuncDef) child).createSymbolTable();
            } else {
                child.createSymbolTable();
            }
        }
    }
}
