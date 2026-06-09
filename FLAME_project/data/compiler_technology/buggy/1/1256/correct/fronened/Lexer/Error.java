package fronened.Lexer;

public class Error {
    private Integer line;
    private String content;
    private char type;

    public Error(Integer line, char type) {
        this.line = line;
        this.type = type;
    }

    public Integer getLine() {
        return line;
    }

    public char getType() {
        return type;
    }

    public String getContent() {
        return content;
    }
}
