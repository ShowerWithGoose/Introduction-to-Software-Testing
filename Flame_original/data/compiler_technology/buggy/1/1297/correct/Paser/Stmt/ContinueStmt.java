package Paser.Stmt;

import Paser.Node;
import Symbol.SymbolManager;
import Type.SyntaxVarType;

import java.util.ArrayList;

// 'continue' ';'
public class ContinueStmt extends Stmt {
    public ContinueStmt(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public void createSymbolTable() {
        super.createSymbolTable();
        if (!SymbolManager.isInCircle()) {
            SymbolManager.err += startLine + " m\n";// 在非循环块使用break和continue语句
        }
    }
}
