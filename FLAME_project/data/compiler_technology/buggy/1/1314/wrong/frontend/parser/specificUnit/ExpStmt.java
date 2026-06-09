package frontend.parser.specificUnit;

import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class ExpStmt extends Stmt {
    private Exp exp;

    public ExpStmt(String name, ArrayList<ParseUnit> subUnits,
                   Exp exp) {
        super(name, subUnits);
        this.exp = exp;
    }
}
