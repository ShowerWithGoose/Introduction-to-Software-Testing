package Paser.Var;

import Paser.Node;
import Paser.TokenNode;
import Symbol.ConstSymbol;
import Symbol.Symbol;
import Symbol.SymbolManager;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

// ConstDecl â†’ 'const' BType ConstDef { ',' ConstDef } ';'
public class ConstDecl extends Node {
    public ConstDecl(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    @Override
    public void createSymbolTable() {
        ValueType type = ((TokenNode) children.get(1)).getBtype();
        for (int i = 2; i < children.size(); i += 2) {
            ValueType t = type;
            if (((ConstDef) children.get(i)).isArray()) {
                if (type == ValueType.INT) {
                    t = ValueType.INTARRAY;
                } else if (type == ValueType.CHAR) {
                    t = ValueType.CHARARRAY;
                }
            }
            Symbol symbol = new ConstSymbol(((ConstDef) children.get(i)).getName(), t, SymbolManager.currentSymbolTable.getDim(), children.get(i).getStartLine());
            SymbolManager.currentSymbolTable.addSymbol(symbol);
        }
        super.createSymbolTable();
    }
}