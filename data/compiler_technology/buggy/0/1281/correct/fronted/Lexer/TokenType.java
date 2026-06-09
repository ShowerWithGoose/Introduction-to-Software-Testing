package fronted.Lexer;

/**
 * @author
 * @Description:
 * @date 2024/9/24 14:30
 */
public enum TokenType {
    IDENFR("ident"),
    INTCON("int const"),
    STRCON("string"),
    CHRCON("char const"),
    CHARTK("char"),
    MAINTK("main"),
    CONSTTK("const"),
    INTTK("int"),
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

    TokenType(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return name();
    }
}
