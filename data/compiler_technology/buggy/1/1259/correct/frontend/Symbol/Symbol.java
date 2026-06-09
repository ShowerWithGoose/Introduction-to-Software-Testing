package frontend.Symbol;

import frontend.Lexer.Token;
import frontend.Parser.GrammarTreeNode;

public class Symbol
{
    private int id;
    private int tableID;
    private Token token;
    private SymbolType symbolType;
    private SymbolExtend symbolExtend;
    private boolean constant;

    //<editor-fold> desc=构造函数
    //single var
    public Symbol(Token token, SymbolType symbolType, GrammarTreeNode node, boolean constant) {
        this.id = id;
        this.tableID = tableID;
        this.token = token;
        this.symbolType = symbolType;
        this.constant = constant;
        if(symbolType == SymbolType.CharVar || symbolType == SymbolType.ConstChar){
            this.symbolExtend = new SingleCharVar(node);
        }
        else{
            this.symbolExtend = new SingleIntVar(node);
        }

    }

    //array
    public Symbol(Token token, SymbolType symbolType, GrammarTreeNode valueNode,GrammarTreeNode sizeNode, boolean constant) {
        this.id = id;
        this.tableID = tableID;
        this.token = token;
        this.symbolType = symbolType;
        this.constant = constant;
        if(symbolType == SymbolType.CharArray ||symbolType == SymbolType.ConstCharArray){
            this.symbolExtend = new ArrayCharVar(valueNode, sizeNode);
        }
        else{
            this.symbolExtend = new ArrayIntVar(valueNode, sizeNode);
        }
    }


    public Symbol(Token token, SymbolType symbolType, MyType returnType, MyType[] paramTypes) {
        this.id = id;
        this.tableID = tableID;
        this.token = token;
        this.symbolType = symbolType;
        this.constant = false;
        this.symbolExtend = new Func(returnType, paramTypes);
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setTableID(int tableID) {
        this.tableID = tableID;
    }

    //</editor-fold>

    //<editor-fold> desc=校验
    public boolean isConstant() {
        return constant;
    }

    public boolean isFunc() {
        return symbolType.equals(SymbolType.CharFunc) || symbolType.equals(SymbolType.IntFunc) || symbolType.equals(SymbolType.VoidFunc);
    }

    public boolean isArray() {
        return symbolType.equals(SymbolType.CharArray) || symbolType.equals(SymbolType.IntArray) ||
                symbolType.equals(SymbolType.ConstCharArray) || symbolType.equals(SymbolType.ConstIntArray);
    }

    public boolean isSingleVar(){
        return symbolType.equals(SymbolType.CharVar) || symbolType.equals(SymbolType.IntVar)
                || symbolType.equals(SymbolType.ConstChar) || symbolType.equals(SymbolType.ConstInt);
    }
    //</editor-fold>


    public int getId() {
        return id;
    }

    public int getTableID() {
        return tableID;
    }

    public Token getToken() {
        return token;
    }

    public SymbolType getSymbolType() {
        return symbolType;
    }

    public SymbolExtend getSymbolExtend() {
        return symbolExtend;
    }
}


