package struct;

import token.Token;

/* Character â†’ CharConst */
public class Character {
    private final Token charConst;

    public Character(Token charConst) {
        this.charConst = charConst;
    }

    public Token getCharConst() {
        return charConst;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(charConst.toString());
        sb.append("<Character>\n");
        return sb.toString();
    }
}
