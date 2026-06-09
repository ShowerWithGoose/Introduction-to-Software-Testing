package frontend.parser.specificUnit;

import frontend.lexer.Token;
import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class Character extends ParseUnit {
    private Token charConst;

    public Character(String name, ArrayList<ParseUnit> subUnits,
                     Token charConst) {
        super(name, subUnits);
        this.charConst = charConst;
    }
}
