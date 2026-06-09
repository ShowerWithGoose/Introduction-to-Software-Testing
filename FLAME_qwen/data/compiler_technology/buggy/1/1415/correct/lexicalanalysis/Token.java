package lexicalanalysis;

public class Token {
    private final Type type;
    private final String content;
    private final int line;

    public Token(Type type, String content, int line) {
        this.type = type;
        this.content = content;
        this.line = line;
    }

    public Type getType() {
        return type;
    }

    public String getContent() {
        return content;
    }

    public int getLine() {
        return line;
    }

    @Override
    public String toString() {
        return type + " " + content;
    }

    public enum Type {
        IDENFR,
        INTCON,
        STRCON,
        CHRCON,
        MAINTK,
        CONSTTK,
        INTTK,
        CHARTK,
        BREAKTK,
        CONTINUETK,
        IFTK,
        ELSETK,
        NOT,
        AND,
        OR,
        FORTK,
        GETINTTK,
        GETCHARTK,
        PRINTFTK,
        RETURNTK,
        PLUS,
        MINU,
        VOIDTK,
        MULT,
        DIV,
        MOD,
        LSS,
        LEQ,
        GRE,
        GEQ,
        EQL,
        NEQ,
        ASSIGN,
        SEMICN,
        COMMA,
        LPARENT,
        RPARENT,
        LBRACK,
        RBRACK,
        LBRACE,
        RBRACE,
    }
}
