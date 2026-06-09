package Sym;

import Lexer.Token;

public class Symbol {
    Token Btype; 	// 当前单词所对应的类型

    Token ident;  // 当前单词对应的名字

    Integer scopeId;
    boolean isArray;

    boolean isConst;

    boolean isFunc;


    SymType type;



    public Symbol(Token Btype, Token ident , boolean isConst, boolean isArray, boolean isFunc, Integer scopeId) {
        this.Btype = Btype;
        this.ident = ident;
        this.isArray = isArray;
        this.isConst = isConst;
        this.isFunc = isFunc;
        this.scopeId = scopeId;
        this.type = convert(Btype, isConst, isArray, isFunc);

    }

    public Symbol() {
        this.Btype = null;
        this.ident = null;
        this.isArray = false;
        this.isConst = false;
        this.isFunc = true;
        this.type = null;
    }


    private SymType convert(Token token, boolean isConst, boolean isArray, boolean isFunc) {
        if (!isFunc) {
            if (isArray) {
                if (isConst) {
                    if (token.getType().equals("CHARTK")) {
                        return SymType.ConstCharArray;
                    }
                    if (token.getType().equals("INTTK")) {
                        return SymType.ConstIntArray;
                    }
                } else {
                    if (token.getType().equals("CHARTK")) {
                        return SymType.CharArray;
                    }
                    if (token.getType().equals("INTTK")) {
                        return SymType.IntArray;
                    }
                }
            } else {
                if (isConst) {
                    if (token.getType().equals("CHARTK")) {
                        return SymType.ConstChar;
                    }
                    if (token.getType().equals("INTTK")) {
                        return SymType.ConstInt;
                    }
                } else {
                    if (token.getType().equals("CHARTK")) {
                        return SymType.Char;
                    }
                    if (token.getType().equals("INTTK")) {
                        return SymType.Int;
                    }
                }
            }
        } else {
            if (token.getType().equals("CHARTK")) {
                return SymType.CharFunc;
            }
            if (token.getType().equals("INTTK")) {
                return SymType.IntFunc;
            }
            if (token.getType().equals("VOIDTK")) {
                return SymType.VoidFunc;
            }
        }
        return null;
    }


    public SymType getType() {
        return type;
    }


    public void setScope(Integer scope) {
        this.scopeId = scope;
    }

    private String capitalize(String str) {
        return str.substring(0, 1).toUpperCase() + str.substring(1);
    }

    public Token getIdent() {
        return ident;
    }

    public boolean isConst() {
        return isConst;
    }

    public boolean isArray() {
        return isArray;
    }

    public String toString() {
        return this.scopeId + " " + this.ident.getToken() + " " + this.type + "\n";
    }
}
