package frontend.parser.specificUnit;

import frontend.lexer.Token;
import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class VarDef extends ParseUnit {
    private Token ident;
    private boolean isArray;
    private InitVal initVal;

    public VarDef(String name, ArrayList<ParseUnit> subUnits,
                  Token ident, boolean isArray, InitVal initVal) {
        super(name, subUnits);
        this.ident = ident;
        this.isArray = isArray;
        this.initVal = initVal;
    }

    public Token getIdent() {
        return ident;
    }

    public boolean isArray() {
        return isArray;
    }
}
