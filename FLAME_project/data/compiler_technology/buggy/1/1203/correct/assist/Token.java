package assist;

public class Token{
    public enum Type{IDENFR, INTCON, STRCON, CHRCON, MAINTK,CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK,
        ELSETK, NOT, AND, OR, FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, PLUS, MINU, VOIDTK, MULT,
        DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN, SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK,
        LBRACE, RBRACE, ERROR
    }
    private Type type;
    private String value;
    private int lineNo;

    public Token() {
    }

    public Token setToken(Type type, String value, int lineNo) {
        this.type = type;
        this.value = value;
        this.lineNo = lineNo;
        return this;
    }

    public Type getType() {
        return type;
    }

    public String getValue() {
        return value;
    }

    public int getLineNo() {
        return lineNo+1;
    }

    @Override
    public String toString() {
        return (type.name() + " " + value + "\n");
    }
}
