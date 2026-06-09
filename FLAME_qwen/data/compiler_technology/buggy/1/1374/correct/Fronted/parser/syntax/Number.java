package Fronted.parser.syntax;

import Fronted.lexer.Token;

// Number â†’ IntConst
public class Number {

    private static final String name = "<Number>";

    private Token intConst = null;

    public Number(Token intConst) {
        this.intConst = intConst;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(intConst);
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getIntConst() {
        return intConst;
    }

    public void setIntConst(Token intConst) {
        this.intConst = intConst;
    }
}
