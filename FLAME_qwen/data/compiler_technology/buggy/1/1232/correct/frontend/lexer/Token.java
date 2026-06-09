package frontend.lexer;

public class Token {
    TokenType type;
    String content;
    int lineno;

    public Token(){

    }

    public Token(TokenType type, String content, int lineno) {
        this.type = type;
        this.content = content;
        this.lineno = lineno;
    }

    public TokenType getType() {
        return type;
    }

    public String getContent() {
        return content;
    }

    public int getLineno() {
        return lineno;
    }


    public String toString() {
        return type + " " + content;
    }

    public String getOutput() {
        return type + " " + content + "\n";
    }

    public boolean isStart() {
        if (type.equals(TokenType.IDENFR)) {
            return true;
        } else if (type.equals(TokenType.INTCON)) {
            return true;
        } else if (type.equals(TokenType.CHRCON)) {
            return true;
        } else if (type.equals(TokenType.STRCON)) {
            return true;
        } else if (type.equals(TokenType.NOT)) {
            return true;
        } else if (type.equals(TokenType.PLUS)) {
            return true;
        } else if (type.equals(TokenType.MINU)) {
            return true;
        } else if (type.equals(TokenType.LPARENT)) {
            return true;
        } else {
            return false;
        }
    }
}
