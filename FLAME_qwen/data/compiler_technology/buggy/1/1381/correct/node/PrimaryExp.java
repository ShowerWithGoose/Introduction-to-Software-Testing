package node;

import frontend.Parser;

public class PrimaryExp {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.PrimaryExp;
    private Exp exp;
    private LVal lVal;
    private Number number;
    private Character character;

    public PrimaryExp(Exp exp) {
        this.exp = exp;
        this.lVal = null;
        this.number = null;
        this.character = null;
    }

    public PrimaryExp(LVal lVal) {
        this.lVal = lVal;
        this.exp = null;
        this.number = null;
        this.character = null;
    }

    public PrimaryExp(Number number) {
        this.number = number;
        this.lVal = null;
        this.exp = null;
        this.character = null;
    }

    public PrimaryExp(Character character) {
        this.character = character;
        this.lVal = null;
        this.exp = null;
        this.number = null;
    }

    public Exp getExp() {
        return exp;
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

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        if (exp != null) ret.append("\n").append(exp);
        else if (lVal != null) ret.append("\n").append(lVal);
        else if (number != null) ret.append("\n").append(number);
        else ret.append("\n").append(character);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
