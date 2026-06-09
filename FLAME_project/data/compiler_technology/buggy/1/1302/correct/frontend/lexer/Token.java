package frontend.lexer;

import frontend.tree.Node;

public class Token extends Node {
    private final LexType type;
    private final String value;
    private final int lineNum;

    public Token(LexType type, String value, int lineNum) {
        this.type = type;
        this.value = value;
        this.lineNum = lineNum;
    }

    public LexType getLexType() {
        return type;
    }

    public String getValue() {
        return value;
    }

    public int getLineNum() {
        return lineNum;
    }

    @Override
    public String toString() {
        return lineNum + ": " + type + " " + value;
    }
}
