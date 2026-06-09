package frontend.Lexer;

import java.io.Serializable;

public class Token implements Serializable {
    private LexType tokenType;
    private String value;
    private int line;

    public Token(LexType tokenType, String value, int line) {
        this.tokenType = tokenType;
        this.value = value;
        this.line = line;
    }

    public Token() {
    }

    public LexType getTokenType() {
        return tokenType;
    }

    public void setTokenType(LexType tokenType) {
        this.tokenType = tokenType;
    }

    public String getValue() {
        return value;
    }

    public void setValue(String value) {
        this.value = value;
    }

    public int getLineNumber() {
        return line;
    }

    public void setLine(int line) {
        this.line = line;
    }
}
