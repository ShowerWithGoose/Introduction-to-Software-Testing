package Paser.Exp;

import Paser.Func.FuncRealParams;
import Paser.Node;
import Paser.TokenNode;
import Symbol.SymbolManager;
import Symbol.ValueType;
import Type.SyntaxVarType;

import java.util.ArrayList;

// UnaryExp â†’ PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
public class UnaryExp extends Node {
    public UnaryExp(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

    public ValueType getValueType() {
        if (children.get(0) instanceof PrimaryExp) {
            return ((PrimaryExp) children.get(0)).getValueType();
        } else if (children.get(0) instanceof TokenNode) {
            if (children.get(2) instanceof FuncRealParams) {
                SymbolManager.checkParams(((TokenNode) children.get(0)).getToken().getDescription(), ((FuncRealParams) children.get(2)), startLine);
            } else {
                SymbolManager.checkParams(((TokenNode) children.get(0)).getToken().getDescription(), null, startLine);
            }
            return SymbolManager.name2valueType(((TokenNode) children.get(0)).getToken().getDescription(), startLine);
        } else if (children.get(0) instanceof UnaryOp) {
            return ((UnaryExp) children.get(1)).getValueType();
        } else {
            System.err.println("UnaryExp getValueType error");
        }
        return null;
    }

    @Override
    public void createSymbolTable() {
        if (children.get(0) instanceof TokenNode) {
            if (children.get(2) instanceof FuncRealParams) {
                SymbolManager.checkParams(((TokenNode) children.get(0)).getToken().getDescription(), ((FuncRealParams) children.get(2)), startLine);
            } else {
                SymbolManager.checkParams(((TokenNode) children.get(0)).getToken().getDescription(), null, startLine);
            }
        }
        super.createSymbolTable();
    }
}
