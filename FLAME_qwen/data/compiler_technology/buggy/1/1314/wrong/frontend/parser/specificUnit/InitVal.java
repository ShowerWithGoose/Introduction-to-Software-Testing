package frontend.parser.specificUnit;

import frontend.lexer.Token;
import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class InitVal extends ParseUnit {
    private ArrayList<Exp> exps;
    private Token stringConst;

    public InitVal(String name, ArrayList<ParseUnit> subUnits,
                   ArrayList<Exp> exps, Token stringConst) {
        super(name, subUnits);
        this.exps = exps;
        this.stringConst = stringConst;
    }
}
