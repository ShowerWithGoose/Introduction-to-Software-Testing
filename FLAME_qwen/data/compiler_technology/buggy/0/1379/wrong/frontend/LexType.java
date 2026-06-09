package frontend;

public enum LexType {
    IDENFR("ident"),
    INTCON("int const"),
    STRCON("string const"),
    CHRCON("char const"),
    MAINTK("main"),
    CONSTTK("const"),
    INTTK("int"),
    CHARTK("char"),
    BREAKTK("break"),
    CONTINUETK("continue"),
    IFTK("if"),
    ELSETK("else"),
    NOT("!"),
    AND("&&"),
    OR("||"),
    FORTK("for"),
    GETINTTK("getint"),
    GETCHARTK("getchar"),
    PRINTFTK("printf"),
    RETURNTK("return"),
    PLUS("+"),
    MINU("-"),
    VOIDTK("void"),
    MULT("*"),
    DIV("/"),
    MOD("%"),
    LSS("<"),
    LEQ("<="),
    GRE(">"),
    GEQ(">="),
    EQL("=="),
    NEQ("!="),
    ASSIGN("="),
    SEMICN(";"),
    COMMA(","),
    LPARENT("("),
    RPARENT(")"),
    LBRACK("["),
    RBRACK("]"),
    LBRACE("{"),
    RBRACE("}");

    private final String value;

    LexType(String s) {
        value = s;
    }

    @Override
    public String toString() {
        return this.name();
    }

    public LexType find(String s) {
        for (LexType t : LexType.values()) {
            if (t.value.equals(s)) {
                return t;
            }
        }
        return LexType.IDENFR;
    }
}