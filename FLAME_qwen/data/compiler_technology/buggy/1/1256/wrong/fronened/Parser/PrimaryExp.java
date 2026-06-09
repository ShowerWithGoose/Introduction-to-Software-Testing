package fronened.Parser;

import fronened.Lexer.Error;
import fronened.Lexer.ErrorList;
import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class PrimaryExp {
    private Token lParent;
    private Exp exp;
    private Token rParent;
    private LVal lVal;
    private Number number;
    private Character character;

    public PrimaryExp(Token lParent, Exp exp, Token rParent, LVal lVal, Number number, Character character) {
        this.lParent = lParent;
        this.exp = exp;
        this.rParent = rParent;
        this.lVal = lVal;
        this.number = number;
        this.character = character;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        if (lParent != null) {
            sb.append(lParent.print());
        }
        if (exp != null) {
            sb.append(exp.print());
        }
        if (rParent != null) {
            sb.append(rParent.print());
        }
        if (lVal != null) {
            sb.append(lVal.print());
        }
        if (number != null) {
            sb.append(number.print());
        }
        if (character != null) {
            sb.append(character.print());
        }
        sb.append("<PrimaryExp>\n");
        return sb.toString();
    }

    public static PrimaryExp parse(TokenIterator iterator) {
        Token lParent = null;
        Exp exp = null;
        Token rParent = null;
        LVal lVal = null;
        Number number = null;
        Character character = null;
        Token token = iterator.next();
        if (token.getType().equals(Token.Type.LPARENT)) {
            lParent = token;
            exp = Exp.parse(iterator);
            token = iterator.next();
            if (token.getType().equals(Token.Type.RPARENT)) {
                rParent = token;
            }
            else {
                iterator.back();
                Error error = new Error(iterator.now_line(), 'j');
                ErrorList.addError(error);
            }
        }
        else if (token.getType().equals(Token.Type.IDENFR)) {
            iterator.back();
            lVal = LVal.parse(iterator);
        }
        else if (token.getType().equals(Token.Type.INTCON)) {
            iterator.back();
            number = Number.parser(iterator);
        }
        else if (token.getType().equals(Token.Type.CHRCON)) {
            iterator.back();
            character = Character.parser(iterator);
        }
        return new PrimaryExp(lParent, exp, rParent, lVal, number, character);
    }
}
