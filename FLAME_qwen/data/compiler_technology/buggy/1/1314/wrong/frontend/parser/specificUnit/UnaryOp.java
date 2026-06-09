package frontend.parser.specificUnit;

import frontend.lexer.Token;
import frontend.parser.ParseUnit;

import java.util.ArrayList;

public class UnaryOp extends ParseUnit {
    private Token op;

    public UnaryOp(String name, ArrayList<ParseUnit> subUnits, Token op) {
        super(name, subUnits);
        this.op = op;
    }
}
