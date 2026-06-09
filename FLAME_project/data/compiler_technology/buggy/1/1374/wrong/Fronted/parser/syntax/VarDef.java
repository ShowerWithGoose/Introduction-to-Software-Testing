package Fronted.parser.syntax;

import Fronted.lexer.Token;

// VarDef â†’ Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
public class VarDef {

    private static final String name = "<VarDef>";

    private Token ident = null;

    private Token lbrack = null;

    private ConstExp constExp = null;

    private Token rbrack = null;

    private Token assign = null;

    private InitVal initVal = null;

    public VarDef(Token ident, Token lbrack, ConstExp constExp, Token rbrack) {
        this.ident = ident;
        this.lbrack = lbrack;
        this.constExp = constExp;
        this.rbrack = rbrack;
    }

    public VarDef(Token ident, Token lbrack, ConstExp constExp, Token rbrack, Token assign, InitVal initVal) {
        this.ident = ident;
        this.lbrack = lbrack;
        this.constExp = constExp;
        this.rbrack = rbrack;
        this.assign = assign;
        this.initVal = initVal;
    }

    public String toString(){
        StringBuilder out = new StringBuilder();
        out.append(ident);
        if(lbrack!= null){
            out.append(lbrack);
            out.append(constExp);
            out.append(rbrack);
        }
        if(assign!= null){
            out.append(assign);
            out.append(initVal);
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getIdent() {
        return ident;
    }

    public Token getLbrack(){
        return lbrack;
    }

    public ConstExp getConstExp() {
        return constExp;
    }

    public Token getRbrack(){
        return rbrack;
    }

    public Token getAssign() {
        return assign;
    }

    public InitVal getInitVal() {
        return initVal;
    }

    public void setIdent(Token ident) {
        this.ident = ident;
    }

    public void setLbrack(Token lbrack) {
        this.lbrack = lbrack;
    }

    public void setConstExp(ConstExp constExp) {
        this.constExp = constExp;
    }

    public void setRbrack(Token rbrack) {
        this.rbrack = rbrack;
    }

    public void setAssign(Token assign) {
        this.assign = assign;
    }

    public void setInitVal(InitVal initVal) {
        this.initVal = initVal;
    }
}
