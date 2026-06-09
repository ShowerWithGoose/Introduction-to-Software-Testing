package frontend;

import java.util.regex.Pattern;
public enum LexType {
    SEMICN(";", false),
    COMMA(",", false),
    LPARENT("\\(", false),
    RPARENT("\\)", false),
    LBRACK("\\[", false),
    RBRACK("\\]", false),
    LBRACE("\\{", false),
    RBRACE("\\}", false),
    IFTK("if", true),
    ELSETK("else", true),
    FORTK("for", true),
    INTTK("int", true),
    CHARTK("char", true),
    PRINTFTK("printf", true),
    RETURNTK("return", true),
    CONSTTK("const", true),
    BREAKTK("break", true),
    CONTINUETK("continue", true),
    GETINTTK("getint", true),
    GETCHARTK("getchar", true),
    VOIDTK("void", true),
    MAINTK("main", true),
    INTCON("[0-9]+", false),
    STRCON("\\\"([^\\\"\\n]|\\n)*\\\"", false),
    CHRCON("'(?:\\\\a|\\\\v|\\\\\\\\|\\\\b|\\\\f|\\\\0|\\\\t|\\\\\"|\\\\n|\\\\'|\\s)'", false),
    IDENFR("[_A-Za-z][_A-Za-z0-9]*", false),
    PLUS("\\+", false),
    MINU("-", false),
    MULT("\\*", false),
    DIV("/", false),
    MOD("%", false),
    LEQ("<=", false),
    LSS("<", false),
    GEQ(">=", false),
    GRE(">", false),
    EQL("==", false),
    NEQ("!=", false),
    ASSIGN("=", false),
    NOT("!", false),
    AND("&&", false),
    OR("\\|\\|", false),
    a("[&\\|]", false);

    private final Pattern pattern;

    LexType(String string, boolean needGreedy) {
        if (!needGreedy) {
            this.pattern = Pattern.compile("^" + string);
        }
        else {
            this.pattern = Pattern.compile("^" + string + "(?![_A-Za-z0-9])");
        }
    }

    public Pattern getPattern() {
        return pattern;
    }
}
