package node;

import frontend.Parser;
import frontend.Token;

public class Character {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.Character;
    private String value;

    public Character(Token token) {
        this.value = token.getValue();
    }

    public String getValue() {
        return value;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append(value);
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
