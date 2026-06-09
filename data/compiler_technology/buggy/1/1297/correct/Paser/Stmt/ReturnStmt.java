package Paser.Stmt;

import Paser.Exp.Exp;
import Paser.Node;
import Symbol.SymbolManager;
import Symbol.SymbolTable;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  'return' [Exp] ';'
public class ReturnStmt extends Stmt {
    public ReturnStmt(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    @Override
    public void createSymbolTable() {
        ValueType v = null;
        if (children.size() == 3) {
            v = ((Exp) children.get(1)).getValueType();
        }
        else {
            v = ValueType.VOID;
        }
        SymbolManager.funcSymbol.setReturnType(v , startLine);
        super.createSymbolTable();
    }
}
