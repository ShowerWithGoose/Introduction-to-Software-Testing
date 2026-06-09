package frontend.Lexer;
import java.util.regex.Pattern;

public enum TokenType {
    IDENFR(""),
    INTCON(""),
    STRCON(""),
    CHRCON(""),

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
    PLUS("\\+"),
    MINU("-"),
    VOIDTK("void"),
    MULT("\\*"),
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
    LPARENT("\\("),
    RPARENT("\\)"),
    LBRACK("\\["),
    RBRACK("\\]"),
    LBRACE("\\{"),
    RBRACE("\\}");

    private String value;

    TokenType(){}
    TokenType(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return this.name();
    }

    public static TokenType getType(String token){
        for (TokenType type : TokenType.values()) {
            if (Pattern.matches(type.value, token)) {
                return type;
            }
        }
        return null;
    }
}
