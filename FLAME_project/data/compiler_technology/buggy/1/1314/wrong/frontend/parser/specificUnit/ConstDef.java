package frontend.parser.specificUnit;

import frontend.lexer.Token;
import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class ConstDef extends ParseUnit {
    private Token ident;
    private boolean isArray;
    private ConstInitVal constInitVal;

    public ConstDef(String name, ArrayList<ParseUnit> subUnits,
                    Token ident, boolean isArray, ConstInitVal constInitVal) {
        super(name, subUnits);
        this.ident = ident;
        this.isArray = isArray;
        this.constInitVal = constInitVal;
    }

    public Token getIdent() {
        return ident;
    }

    public boolean isArray() {
        return isArray;
    }
}
