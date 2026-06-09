package frontend;

public class Token {
    public enum Type {
        IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK,
        INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK, ELSETK,
        NOT, AND, OR, FORTK, GETINTTK, GETCHARTK, PRINTFTK,
        RETURNTK, PLUS, MINU, VOIDTK, MULT, DIV, MOD,
        LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN, SEMICN,
        COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE
    }

    private final Type type;
    private final String content;
    private final int lineCnt;

    public Token(Type type, String content, int lineCnt) {
        this.type = type;
        this.content = content;
        this.lineCnt = lineCnt;
    }

    public Type getType() {
        return type;
    }

    public String getContent() {
        return content;
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
