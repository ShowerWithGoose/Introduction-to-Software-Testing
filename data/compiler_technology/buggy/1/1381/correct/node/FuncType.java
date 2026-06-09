package node;

import frontend.Parser;
import frontend.Token;

public class FuncType {
    private Parser.SyntaxType nodeType = Parser.SyntaxType.FuncType;
    private Token.TokenType type;

    public FuncType(Token.TokenType type) {
        this.type = type;
    }

    public Token.TokenType getType() {
        return type;
    }

    public String toString() {
        StringBuilder ret = new StringBuilder("<" + nodeType + ">");
        ret.append("\n").append("<").append(type).append(">");
        ret.append("\n<").append(nodeType).append("> <END>");
        return ret.toString();
    }
}
