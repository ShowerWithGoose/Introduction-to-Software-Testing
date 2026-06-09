package struct;

import token.Token;

/* Number â†’ IntConst */
public class Number {
    private final Token intConst;

    public Number(Token intConst) {
        this.intConst = intConst;
    }

    public Token getIntConst() {
        return intConst;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(intConst.toString());
        sb.append("<Number>\n");
        return sb.toString();
    }
}
