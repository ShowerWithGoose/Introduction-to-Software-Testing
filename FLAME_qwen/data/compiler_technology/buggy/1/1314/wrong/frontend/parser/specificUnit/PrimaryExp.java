package frontend.parser.specificUnit;

import frontend.lexer.Word;
import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class PrimaryExp extends ParseUnit {
    private Exp exp;
    private LVal lVal;
    private Number number;
    private Character character;

    public PrimaryExp(String name, ArrayList<ParseUnit> subUnits,
                      Exp exp, LVal lVal, Number number, Character character) {
        super(name, subUnits);
        this.exp = exp;
        this.lVal = lVal;
        this.number = number;
        this.character = character;
    }

    public Param getParam() {
        if (exp != null) {
            return exp.getParam();
        } else if (lVal != null) {
            return lVal.getParam();
        } else if (number != null) {
            return new Param(Word.INTTK, false);
        } else {
            return new Param(Word.CHARTK, false);
        }
    }
}
