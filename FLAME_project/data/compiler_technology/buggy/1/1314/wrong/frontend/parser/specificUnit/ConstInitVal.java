package frontend.parser.specificUnit;

import frontend.lexer.Token;
import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class ConstInitVal extends ParseUnit {
    private ArrayList<ConstExp> constExps;
    private Token stringConst;

    public ConstInitVal(String name, ArrayList<ParseUnit> subUnits,
                        ArrayList<ConstExp> constExps, Token stringConst) {
        super(name, subUnits);
        this.constExps = constExps;
        this.stringConst = stringConst;
    }
}
