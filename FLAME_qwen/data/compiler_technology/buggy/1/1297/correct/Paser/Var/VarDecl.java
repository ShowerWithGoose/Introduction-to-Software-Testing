package Paser.Var;

import Paser.Node;
import Paser.TokenNode;
import Symbol.Symbol;
import Symbol.ValueType;
import Type.SyntaxVarType;
import Symbol.VarSymbol;
import Symbol.SymbolManager;

import java.util.ArrayList;

// VarDecl â†’ BType VarDef { ',' VarDef } ';'
public class VarDecl extends Node {
    public VarDecl(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public void createSymbolTable()
    {
        ValueType type =  ((TokenNode)children.get(0)).getBtype();

        for (int i=1; i<children.size(); i+=2) {
            ValueType t = type;
            if (((VarDef)children.get(i)).isArray())
            {
                if (type == ValueType.INT)
                {
                    t = ValueType.INTARRAY;
                }
                else if (type == ValueType.CHAR)
                {
                    t = ValueType.CHARARRAY;
                }
            }
            Symbol symbol = new VarSymbol(((VarDef)children.get(i)).getName(),t, SymbolManager.currentSymbolTable.getDim(), children.get(i).getStartLine());
            SymbolManager.currentSymbolTable.addSymbol(symbol);
        }
        super.createSymbolTable();
    }
}
