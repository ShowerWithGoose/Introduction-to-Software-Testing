package frontend.GrammaticalElements.expression;

import frontend.GrammaticalElements.terminal.Character;
import frontend.GrammaticalElements.terminal.Number;
import frontend.Token;

public class PrimaryExp {
    private final String name = "<PrimaryExp>";
    private Token leftParen;
    private Exp exp;
    private Token rightParen;
    private LVal lVal;
    private Number number;
    private Character character;

    public PrimaryExp(Token leftParen, Exp exp, Token rightParen) {
        this.leftParen = leftParen;
        this.exp = exp;
        this.rightParen = rightParen;
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
        StringBuilder sb = new StringBuilder();
        if (leftParen != null) {
            sb.append(leftParen.toString());
            sb.append(exp.toString());
            sb.append(rightParen.toString());
        } else if (lVal != null) {
            sb.append(lVal.toString());
        } else if (number != null) {
            sb.append(number.toString());
        } else {
            sb.append(character.toString());
        }
        sb.append(this.name).append('\n');
        return sb.toString();
    }
}
