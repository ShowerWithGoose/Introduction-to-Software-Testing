package Paser.Func;

import Paser.Block;
import Paser.Node;
import Paser.TokenNode;
import Symbol.FuncSymbol;
import Symbol.SymbolManager;
import Symbol.SymbolTable;
import Type.SyntaxVarType;

import java.util.ArrayList;

import static Symbol.ValueType.VOID;

// FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
public class FuncDef extends Node {
    public FuncDef(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public void createSymbolTable() {
        FuncSymbol funcSymbol = new FuncSymbol(((TokenNode) children.get(1)).getToken().getDescription(), ((FuncType) children.get(0)).getFuncType(), SymbolManager.currentSymbolTable.getDim(), this.startLine);
        SymbolManager.currentSymbolTable.addSymbol(funcSymbol);
        SymbolManager.currentSymbolTable = new SymbolTable(SymbolManager.currentSymbolTable, SymbolManager.Dim++);
        SymbolManager.funcSymbol = funcSymbol;
        if (children.size() == 6) {
            ((FuncFormalParams) children.get(3)).createSymbolTable();
            ((Block) children.get(5)).createSymbolTable(true);
            if ( ((Block) children.get(5)).getLastStmt() != SyntaxVarType.RETURN_STMT && funcSymbol.getType() != VOID) {
                SymbolManager.err += endLine + " g\n";// 函数缺少返回语句
            }
        } else {
            ((Block) children.get(4)).createSymbolTable(true);
            if ( ((Block) children.get(4)).getLastStmt() != SyntaxVarType.RETURN_STMT && funcSymbol.getType() != VOID) {
                SymbolManager.err += endLine + " g\n";// 函数缺少返回语句
            }
        }

        SymbolManager.exitScope(true, this.endLine);
    }
}
