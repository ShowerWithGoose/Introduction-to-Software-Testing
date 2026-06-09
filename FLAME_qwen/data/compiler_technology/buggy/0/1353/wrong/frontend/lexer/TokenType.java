package frontend.lexer;

import java.util.regex.Pattern;

/**
 * 词法分析枚举类
 * 每个枚举对象有两个属性：正则表达式(Pattern)与是否贪婪匹配(boolean)
 */
public enum TokenType {

    /* 保留字 */
    MAINTK("main", true),
    CONSTTK("const", true),
    VOIDTK("void", true),
    INTTK("int", true),
    CHARTK("char", true),
    BREAKTK("break", true),
    CONTINUETK("continue", true),
    IFTK("if", true),
    ELSETK("else", true),

    /* 基本函数 */
    FORTK("for", true),
    GETINTTK("getint", true),
    GETCHARTK("getchar", true),
    PRINTFTK("printf", true),
    RETURNTK("return", true),

    /* 标识符 */
    IDENFR("[_A-Za-z][_A-Za-z0-9]*", false),
    INTCON("[0-9]+", false),
    STRCON("\\\"[^\\\"]*\\\"", false),
    CHRCON("\\\'[^\\\']\\\'", false),

    /* 比较符 */
    LEQ("<=", false),
    LSS("<", false),
    GEQ(">=", false),
    GRE(">", false),
    EQL("==", false),
    NEQ("!=", false),

    /* 运算符 & 逻辑运算符 */
    PLUS("\\+", false),
    MINU("-", false),
    MULT("\\*", false),
    DIV("/", false),
    MOD("%", false),
    ASSIGN("=", false),
    NOT("!", false),
    AND("&&", false),
    OR("\\|\\|", false),

    /* 其他符号 */
    SEMICN(";", false),
    COMMA(",", false),
    LPARENT("\\(", false),
    RPARENT("\\)", false),
    LBRACK("\\[", false),
    RBRACK("]", false),
    LBRACE("\\{", false),
    RBRACE("}", false),

    /* 错误符号 */
    ERRORAND("&", false),
    ERROROR("\\|", false);

    private String patternString;
    private boolean isGreed;
    private Pattern pattern;

    TokenType(String patternString, boolean isGreed) {
        this.patternString = patternString;
        this.isGreed = isGreed;
        // 注意添加“^”以保证匹配紧接着的字符串
        if(isGreed) {
            pattern = Pattern.compile("^" + patternString + "(?![_A-Za-z0-9])");
        }else {
            pattern = Pattern.compile("^" + patternString);
        }
    }

    public Pattern getPattern() {
        return pattern;
    }
    public boolean isGreed() {
        return isGreed;
    }
    public String getPatternString() {
        return patternString;
    }

    @Override
    public String toString() {
        return this.name();
    }
}
