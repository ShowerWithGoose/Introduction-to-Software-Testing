package Paser.Stmt;

import Paser.Node;
import Symbol.SymbolManager;
import Symbol.SymbolTable;
import Type.SyntaxVarType;

import java.util.ArrayList;

// block
public class BlockStmt extends Stmt {
    public BlockStmt(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    @Override
    public void createSymbolTable() {
        super.createSymbolTable();
    }
}
