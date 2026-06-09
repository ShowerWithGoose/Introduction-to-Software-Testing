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
    private boolean isCorrect;

    public Token(Type type, String content, int lineCnt) {
        this.type = type;
        this.content = content;
        this.lineCnt = lineCnt;
        this.isCorrect = true;
    }

    public void setIsCorrect(boolean isCorrect) {
        this.isCorrect = isCorrect;
    }

    public boolean getIsCorrect() {
        return isCorrect;
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
