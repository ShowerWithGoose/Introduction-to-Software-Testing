package frontend.lexer;

import java.util.regex.Pattern;

public enum TokenType {

    IDENFR("[A-Za-z_][A-Za-z0-9_]*"),
    INTCON("0|([1-9][0-9]*)"),
    CHRCON("'([ -~]|\\\\['\"\\\\abtnvfn0])'"),
    STRCON("\"([ -~]|\\\\['\"\\\\abtnvfn0])\""),
    //keyWord
    MAINTK("main",true),
    CONSTTK("const",true),
    INTTK("int",true),
    CHARTK("char",true),
    VOIDTK("void",true),
    BREAKTK("break",true),
    CONTINUETK("continue",true),
    IFTK("if",true),
    ELSETK("else",true),
    FORTK("for",true),
    GETINTTK("getint",true),
    GETCHARTK("getchart",true),
    PRINTFTK("print",true),
    RETURNTK("return",true),

    // operator (single char)
    NOT("!"),
    PLUS("\\+"),
    MINU("-"),
    MULT("\\*"),
    DIV("/"),
    MOD("%"),
    LSS("<"),
    GRE(">"),
    ASSIGN("="),
    SEMICN(";"),
    COMMA(","),
    LPARENT("\\("),
    RPARENT("\\)"),
    LBRACK("\\["),
    RBRACK("\\]"),
    LBRACE("\\{"),
    RBRACE("\\}"),
    //operator (double char)
    AND("&&"),
    OR("\\|\\|"),
    LEQ("<="),
    GEQ(">="),
    EQL("=="),
    NEQ("!=")
    ;
    private final String pattern;   // regex pattern

    private final boolean keyword;

    TokenType(String pattern, boolean keyword) {
        this.pattern = pattern;
        this.keyword = keyword;
    }
    TokenType(String pattern) {
        this(pattern, false);
    }
    public Pattern getPattern() {
        return Pattern.compile("^(" + pattern + ")" + (keyword ? "(?![A-Za-z0-9_])" : ""));
    }
}
