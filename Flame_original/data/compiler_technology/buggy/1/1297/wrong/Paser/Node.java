package Paser;

import Symbol.Symbol;
import Symbol.SymbolTable;
import Type.SyntaxVarType;

import java.util.ArrayList;
import java.util.HashMap;

import Symbol.SymbolChild;

public class Node {
    protected int startLine;
    protected int endLine;
    protected SyntaxVarType type;
    protected ArrayList<Node> children;

    public Node(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        this.startLine = startLine;
        this.endLine = endLine;
        this.type = type;
        this.children = children;
    }

    public int getStartLine() {
        return startLine;
    }

    public int getEndLine() {
        return endLine;
    }

    public SyntaxVarType getType() {
        return type;
    }

    public ArrayList<Node> getChildren() {
        return children;
    }

    public String toString() {
        StringBuffer sb = new StringBuffer();
        ArrayList<Node> childNode = this.getChildren();
        if (childNode == null && this instanceof TokenNode) {
            sb.append(((TokenNode) this).getToken().toString());
            return sb.toString();
        }
        for (Node n : childNode) {
            sb.append(n.toString()).append('\n');
        }
        sb.append('<'+this.getType().toString()+'>');
        return sb.toString();
    }

    // public SymbolChild createSymbolTable(SymbolTable fatherTable, int dim) {
    //     SymbolTable st = new SymbolTable(fatherTable,dim);
    //     for (Node n : children) {
    //          SymbolChild t =  n.createSymbolTable(st,dim+1);
    //         if (t == null) {
    //             continue;
    //         }
    //         else if (t instanceof Symbol){
    //             Symbol s = (Symbol) t;
    //             st.addSymbol(s);
    //         }
    //         else if (t instanceof SymbolTable){
    //             SymbolTable sta = (SymbolTable) t;
    //             st.addChild(sta);
    //         }
    //     }
    //     return st;
    // }

    public void createSymbolTable() {
        for (Node child : children) {
            child.createSymbolTable();
        }

    }
}
