package Fronted.parser.syntax;

import Fronted.lexer.Token;

// Character â†’ CharConst
public class Character {

    private static final String name = "<Character>";

    private Token charConst = null;

    public Character(Token charConst) {
        this.charConst = charConst;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(charConst);
        out.append(name).append("\n");
        return out.toString();
    }

    public Token getCharConst() {
        return charConst;
    }

    public void setCharConst(Token charConst) {
        this.charConst = charConst;
    }
}
