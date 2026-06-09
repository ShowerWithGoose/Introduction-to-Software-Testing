package Paser;

import Paser.Stmt.Stmt;
import Paser.Var.ConstDecl;
import Paser.Var.VarDecl;
import Symbol.SymbolManager;
import Symbol.SymbolTable;
import Type.SyntaxVarType;

import java.util.ArrayList;

 // Block â†’ '{' { BlockItem } '}'
public class Block extends Node{
    public Block(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public void createSymbolTable(Boolean isFunction)
    {
        if (isFunction)
        {
            for (Node child : children) {
                child.createSymbolTable();
            }
        }
        else {
            SymbolManager.currentSymbolTable = new SymbolTable(SymbolManager.currentSymbolTable, SymbolManager.Dim++);
            for (Node child : children) {
                child.createSymbolTable();
            }
            SymbolManager.exitScope();
        }
    }

    public void createSymbolTable()
    {
        createSymbolTable(false);
    }

    public SyntaxVarType getLastStmt()
    {
        return ( children.get(children.size() - 2)).getType();

    }
}

