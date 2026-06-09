package frontend;

import java.util.regex.Pattern;

public enum TokenType {
    MAINTK("main"),
    CONSTTK("const"),
    INTTK("int"),
    CHARTK("char"),
    BREAKTK("break"),
    CONTINUETK("continue"),
    IFTK("if"),
    ELSETK("else"),
    FORTK("for"),
    GETINTTK("getint"),
    GETCHARTK("getchar"),
    PRINTFTK("printf"),
    RETURNTK("return"),
    VOIDTK("void"),
    INTCON("[0-9]+"),
    AND("\\&\\&"),
    OR("\\|\\|"),
    PLUS("\\+"),
    MINU("\\-"),
    MULT("\\*"),
    DIV("\\/"),
    MOD("\\%"),
    LEQ("<="),
    LSS("<"),
    GEQ(">="),
    GRE(">"),
    EQL("=="),
    NEQ("!="),
    NOT("!"),
    ASSIGN("="),
    SEMICN(";"),
    COMMA(","),
    LPARENT("\\("),
    RPARENT("\\)"),
    LBRACK("\\["),
    RBRACK("\\]"),
    LBRACE("\\{"),
    RBRACE("\\}"),
    ERROR("[&|]"),
    STRCON("\"[^\"]*\""),
    CHRCON("'[^']*'"),
    IDENFR("[_A-Za-z][_A-Za-z0-9]*");

    private Pattern pattern;

    TokenType(String patternString) {
        this.pattern = Pattern.compile(patternString);
    }

    public Pattern getPattern() {
        return this.pattern;
    }
}