package Fronted.parser.syntax;

import Fronted.lexer.Token;

// FuncFParam â†’ BType Ident ['[' ']'] // k
public class FuncFParam {

    private static final String name = "<FuncFParam>";

    private BType bType = null;

    private Token ident = null;

    private Token lbrack = null;

    private Token rbrack = null;

    public FuncFParam(BType bType, Token ident, Token lbrack, Token rbrack) {
        this.bType = bType;
        this.ident = ident;
        this.lbrack = lbrack;
        this.rbrack = rbrack;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(bType);
        out.append(ident);
        if (lbrack!= null) {
            out.append(lbrack);
            out.append(rbrack);
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getIdent() {
        return ident;
    }

    public void setIdent(Token ident) {
        this.ident = ident;
    }

    public Token getLbrack() {
        return lbrack;
    }

    public void setLbrack(Token lbrack) {
        this.lbrack = lbrack;
    }

    public Token getRbrack() {
        return rbrack;
    }

    public void setRbrack(Token rbrack) {
        this.rbrack = rbrack;
    }

    public BType getBType() {
        return bType;
    }

    public void setBType(BType bType) {
        this.bType = bType;
    }
}
