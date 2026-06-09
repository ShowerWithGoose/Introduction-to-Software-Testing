package Paser.Stmt;

import Paser.Node;
import Symbol.SymbolManager;
import Symbol.SymbolTable;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
public class ForStmt extends Stmt {
    public ForStmt(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    @Override
    public void createSymbolTable() {
        SymbolManager.setIsCircle();
        super.createSymbolTable();
        SymbolManager.outCircle();
    }
}