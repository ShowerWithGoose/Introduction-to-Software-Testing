package frontend.parser.specificUnit;

import frontend.lexer.Token;
import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class Number extends ParseUnit {
    private Token intConst;

    public Number(String name, ArrayList<ParseUnit> subUnits,
                  Token intConst) {
        super(name, subUnits);
        this.intConst = intConst;
    }
}
