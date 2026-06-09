package fronened.Lexer;

public class Token {
    public enum Type {
        IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK, ELSETK,
        NOT, AND, OR, FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, PLUS, MINU, VOIDTK, MULT, DIV, MOD,
        LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN, SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE, NULL
    }

    private final Type type;

    private final Integer line;

    public Type getType() {
        return type;
    }

    public String getContent() {
        return content;
    }

    private final String content;

    public Token(Type type, Integer line, String content) {
        this.type = type;
        this.line = line;
        this.content = content;
    }

    public Integer getLine() {
        return line;
    }

    public String print() {
        return this.getType() + " " + this.getContent() + "\n";
    }
}
