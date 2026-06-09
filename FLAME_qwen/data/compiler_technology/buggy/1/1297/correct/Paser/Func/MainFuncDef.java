package Paser.Func;

import Paser.Block;
import Paser.Node;
import Symbol.FuncSymbol;
import Symbol.SymbolManager;
import Symbol.SymbolTable;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

import static Symbol.ValueType.VOID;

// MainFuncDef → 'int' 'main' '(' ')' Block
public class MainFuncDef extends Node {
    public MainFuncDef(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    @Override
    public void createSymbolTable() {
        SymbolManager.funcSymbol = new FuncSymbol("main", ValueType.INT, SymbolManager.currentSymbolTable.getDim(), startLine);
        SymbolManager.currentSymbolTable = new SymbolTable(SymbolManager.currentSymbolTable, SymbolManager.Dim++);
        // SymbolManager.topTable = SymbolManager.currentSymbolTable;
        // SymbolManager.currentSymbolTable.addSymbol(SymbolManager.funcSymbol);
        ((Block) children.get(4)).createSymbolTable(true);
        if ( ((Block) children.get(4)).getLastStmt() != SyntaxVarType.RETURN_STMT && SymbolManager.funcSymbol.getType() != VOID) {
            SymbolManager.err += endLine + " g\n";// 函数缺少返回语句
        }
        SymbolManager.exitScope(true, endLine);
    }
}
