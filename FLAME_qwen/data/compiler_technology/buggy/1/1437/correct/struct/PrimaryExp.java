package struct;

import token.Token;

/* PrimaryExp â†’ '(' Exp ')' | LVal | Number | Character */
public class PrimaryExp {
    private Token lParentToken;
    private Token rParentToken;
    private Exp exp;
    private LVal lVal;
    private Number number;
    private Character character;

    public PrimaryExp(Token lParentToken, Exp exp, Token rParentToken) {
        this.lParentToken = lParentToken;
        this.exp = exp;
        this.rParentToken = rParentToken;
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

    public Token getLParentToken() {
        return lParentToken;
    }

    public Token getRParentToken() {
        return rParentToken;
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
        StringBuilder sb = new StringBuilder();
        if (lParentToken != null) {
            sb.append(lParentToken.toString());
            sb.append(exp.toString());
            sb.append(rParentToken.toString());
        } else if (lVal != null) {
            sb.append(lVal.toString());
        } else if (number != null) {
            sb.append(number.toString());
        } else {
            sb.append(character.toString());
        }
        sb.append("<PrimaryExp>\n");
        return sb.toString();
    }
}
