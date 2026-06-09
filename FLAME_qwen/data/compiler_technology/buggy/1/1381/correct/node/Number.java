package node;

import frontend.Parser;
import frontend.Token;

public class Number {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.Number;
    private int value;

    public Number(Token token) {
        this.value = Integer.parseInt(token.getValue());
    }

    public int getValue() {
        return value;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(value);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
