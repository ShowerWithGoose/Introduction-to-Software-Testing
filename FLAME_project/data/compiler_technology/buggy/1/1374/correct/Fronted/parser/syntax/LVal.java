package Fronted.parser.syntax;

import Fronted.lexer.Token;

// LVal â†’ Ident ['[' Exp ']'] // k
public class LVal {

    private static final String name = "<LVal>";

    private Token ident = null;

    private Token lbrack = null;

    private Exp exp = null;

    private Token rbrack = null;

    public LVal(Token ident, Token lbrack, Exp exp, Token rbrack) {
        this.ident = ident;
        this.lbrack = lbrack;
        this.exp = exp;
        this.rbrack = rbrack;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(ident);
        if (lbrack!= null) {
            out.append(lbrack);
            out.append(exp);
            if (rbrack!= null) {
                out.append(rbrack);
            }
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getIdent() {
        return ident;
    }

    public Token getLbrack() {
        return lbrack;
    }

    public Exp getExp() {
        return exp;
    }

    public Token getRbrack() {
        return rbrack;
    }

    public void setLbrack(){
        this.lbrack = lbrack;
    }

    public void setRbrack(){
        this.rbrack = rbrack;
    }

    public void setExp(){
        this.exp = exp;
    }

    public void setIdent(){
        this.ident = ident;
    }

}
