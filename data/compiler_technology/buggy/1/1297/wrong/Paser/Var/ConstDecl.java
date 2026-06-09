package Paser.Var;

import Paser.Block;
import Paser.Node;
import Paser.TokenNode;
import Symbol.Symbol;
import Symbol.ConstSymbol;
import Symbol.SymbolManager;
import Type.SyntaxVarType;

import java.util.ArrayList;

//ConstDecl â†’ 'const' BType ConstDef { ',' ConstDef } ';'
public class ConstDecl extends Node {
    public ConstDecl(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    @Override
    public void createSymbolTable() {
        for (int i=1; i<children.size(); i+=3) {
            Symbol symbol = new ConstSymbol(((ConstDef)children.get(i+1)).getName(),((TokenNode)children.get(i)).getBtype(),SymbolManager.currentSymbolTable.getDim(), ((TokenNode)children.get(i)).getStartLine());
            SymbolManager.currentSymbolTable.addSymbol(symbol);

        }

    }
}