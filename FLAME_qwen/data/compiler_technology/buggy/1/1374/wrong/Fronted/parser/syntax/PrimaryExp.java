package Fronted.parser.syntax;

import Fronted.lexer.Token;

// PrimaryExp â†’ '(' Exp ')' | LVal | Number | Character// j
public class PrimaryExp {

    private static final String name = "<PrimaryExp>";

    private Token lParent = null;

    private Exp exp = null;

    private Token rParent = null;

    private LVal lVal = null;

    private Number number = null;

    private Character character = null;

    public PrimaryExp(Token lParent, Exp exp, Token rParent) {
        this.lParent = lParent;
        this.exp = exp;
        this.rParent = rParent;
    }

    public PrimaryExp(LVal lVal) {
        this.lVal = lVal;
    }

    public PrimaryExp(Number number) {
        this.number = number;
    }

    public PrimaryExp(Character character) {
        this.character = character;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        if (lParent!= null) {
            out.append(lParent);
            out.append(exp);
            out.append(rParent);
        } else if (lVal!= null) {
            out.append(lVal);
        } else if (number!= null) {
            out.append(number);
        } else if (character!= null) {
            out.append(character);
        }
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getLParent() {
        return lParent;
    }

    public Token getRParent() {
        return rParent;
    }

    public LVal getLVal() {
        return lVal;
    }

    public Number getNumber() {
        return number;
    }

    public Character getCharacter() {
        return character;
    }

    public Exp getExp() {
        return exp;
    }

    public void setLParent(Token lParent) {
        this.lParent = lParent;
    }

    public void setRParent(Token rParent) {
        this.rParent = rParent;
    }

    public void setLVal(LVal lVal) {
        this.lVal = lVal;
    }

    public void setNumber(Number number) {
        this.number = number;
    }

    public void setCharacter(Character character) {
        this.character = character;
    }

    public void setExp(Exp exp) {
        this.exp = exp;
    }
}
