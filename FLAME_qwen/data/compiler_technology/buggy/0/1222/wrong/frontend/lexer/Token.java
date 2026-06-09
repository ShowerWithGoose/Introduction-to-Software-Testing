package frontend.lexer;

public class Token {
    private int lineno;
    private LexType lexType;
    private String content;
    private int number;

    Token(int lineno, LexType lexType, String content) {
        this.lineno = lineno;
        this.lexType = lexType;
        this.content = content;
    }

    Token(int lineno, LexType lexType, String content, int number) {
        this.lineno = lineno;
        this.lexType = lexType;
        this.content = content;
        this.number = number;
    }

    Token() {
    }

    public String getContent() {
        return content;
    }

    public LexType getLexType() {
        return lexType;
    }

    public int getLineno() {
        return lineno;
    }

    public int getNumber() {
        return number;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public void setLexType(LexType lexType) {
        this.lexType = lexType;
    }

    public void setLineno(int lineno) {
        this.lineno = lineno;
    }

    public void setNumber(int number) {
        this.number = number;
    }
}
