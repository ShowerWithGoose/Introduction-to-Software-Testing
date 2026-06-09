package Paser.Exp;

import Paser.Node;
import Paser.TokenNode;
import Reader.Token;
import Symbol.SymbolManager;
import Symbol.SymbolTable;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  LVal â†’ Ident ['[' Exp ']']
public class LValExp extends Node{
    public LValExp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    @Override
    public void createSymbolTable() {
        SymbolManager.hasLval(((TokenNode)children.get(0)).getToken().getDescription(), ((TokenNode)children.get(0)).getToken().getLine());
        super.createSymbolTable();
    }
}
