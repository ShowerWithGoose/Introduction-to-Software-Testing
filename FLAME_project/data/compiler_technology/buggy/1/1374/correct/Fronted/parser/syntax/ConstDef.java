package Fronted.parser.syntax;

import Fronted.lexer.Token;

// ConstDef â†’ Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
public class ConstDef {

    private static final String name = "<ConstDef>";

    private Token ident = null; // Ident

    private Token lbrack = null; // '['

    private ConstExp constExp = null; // ConstExp

    private Token rbrack = null; // ']'

    private Token assign = null; // '='

    private ConstInitVal constInitVal = null; // ConstInitVal

    public ConstDef(Token ident, Token lbrack, ConstExp constExp, Token rbrack, Token assign, ConstInitVal constInitVal) {
        this.ident = ident;
        this.lbrack = lbrack;
        this.constExp = constExp;
        this.rbrack = rbrack;
        this.assign = assign;
        this.constInitVal = constInitVal;
    }

    public String toString(){
        StringBuilder out = new StringBuilder();
        out.append(ident);
        if(lbrack!= null){
            out.append(lbrack);
            out.append(constExp);
            out.append(rbrack);
        }
        out.append(assign);
        out.append(constInitVal);
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getIdent() {
        return ident;
    }

    public Token getLbrack(){
        return lbrack;
    }

    public Token getRbrack(){
        return rbrack;
    }

    public Token getAssign(){
        return assign;
    }

    public ConstExp getConstExp(){
        return constExp;
    }

    public ConstInitVal getConstInitVal(){
        return constInitVal;
    }

    public void setIdent(Token ident) {
        this.ident = ident;
    }

    public void setLbrack(Token lbrack) {
        this.lbrack = lbrack;
    }

    public void setRbrack(Token rbrack) {
        this.rbrack = rbrack;
    }

    public void setAssign(Token assign) {
        this.assign = assign;
    }

    public void setConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void setConstInitVal(ConstInitVal constInitVal) {
        this.constInitVal = constInitVal;
    }
}
