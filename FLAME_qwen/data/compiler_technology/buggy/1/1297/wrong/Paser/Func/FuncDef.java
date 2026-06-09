package Paser.Func;

import Paser.Block;
import Paser.Node;
import Paser.TokenNode;
import Symbol.FuncSymbol;
import Symbol.SymbolManager;
import Symbol.SymbolTable;
import Type.SyntaxVarType;

import java.util.ArrayList;

// FuncDef â†’ FuncType Ident '(' [FuncFParams] ')' Block
public class FuncDef extends Node {
    public FuncDef(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public void createSymbolTable() {

        FuncSymbol funcSymbol = new FuncSymbol(((TokenNode) children.get(1)).getToken().getDescription(), ((FuncType) children.get(0)).getFuncType(),SymbolManager.currentSymbolTable.getDim(), this.startLine);
        SymbolManager.currentSymbolTable.addSymbol(funcSymbol);
        SymbolManager.currentSymbolTable = new SymbolTable(SymbolManager.currentSymbolTable, SymbolManager.currentSymbolTable.getDim() + 1);
        SymbolManager.funcSymbol = funcSymbol;
        ((FuncFormalParams)children.get(4)).createSymbolTable();
        ((Block) children.get(6)).createSymbolTable(true);
        SymbolManager.exitScope(true,this.endLine);
    }
}
