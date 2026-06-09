package Paser.Func;

import Paser.Node;
import Symbol.SymbolManager;
import Symbol.VarSymbol;
import Type.SyntaxVarType;

import java.util.ArrayList;

// FuncFParams â†’ FuncFParam { ',' FuncFParam }
public class FuncFormalParams extends Node {
    public FuncFormalParams(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    @Override
    public void createSymbolTable() {
        for (int i = 0; i < children.size(); i += 2) {
            VarSymbol varSymbol = new VarSymbol(((FuncFormalParam) children.get(i)).getName(), ((FuncFormalParam) children.get(i)).getBtype(),SymbolManager.currentSymbolTable.getDim(), ((FuncFormalParam) children.get(i)).getStartLine());
            SymbolManager.currentSymbolTable.addSymbol(varSymbol);
            SymbolManager.funcSymbol.addParam(((FuncFormalParam) children.get(i)).getBtype());
        }
    }
}
