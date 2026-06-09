package frontend.lexer;

import java.util.regex.Pattern;

/**
 * @author
 * 单词类别枚举类
 * 单词类别码即为枚举类的类名
 * 贪婪匹配反而是为了能够精准匹配
 */
public enum TokenType {
    /* ---------- specific elements begin ---------- */
    MAINTK(true, "main"),
    CONSTTK(true, "const"),
    INTTK(true, "int"),
    CHARTK(true, "char"),
    BREAKTK(true, "break"),
    CONTINUETK(true, "continue"),
    IFTK(true, "if"),
    ELSETK(true, "else"),
    FORTK(true, "for"),
    GETINTTK(true, "getint"),
    GETCHARTK(true, "getchar"),
    PRINTFTK(true, "printf"),
    RETURNTK(true, "return"),
    VOIDTK(true, "void"),
    /* ---------- specific elements end ---------- */
    /* ----------- begin ---------- */
    IDENFR(false, "[_A-Za-z][_A-Za-z0-9]*"),
    INTCON(false, "[0-9]+"),
    STRCON(false, "\\\"[^\\\"]*\\\""), // TODO
    CHRCON(false, "'(\\\\[abtnvf0]|\\\\'|\\\\\"|\\\\\\\\|[^'\\\n])'"), // 前一部分：除了单引号，反斜杠和换行符以外的所有字符 后一部分：匹配所有的转义字符
    /* ---------- end ---------- */
    /* ----------- comparison operation begin ---------- */
    LEQ(false, "<="),
    LSS(false, "<"),
    GEQ(false, ">="),
    GRE(false, ">"),
    EQL(false, "=="),
    NEQ(false, "!="),
    /* ---------- comparison operation end ---------- */
    /* ---------- arithmetic operation begin ---------- */
    PLUS(false, "\\+"),
    MINU(false, "-"),
    MULT(false, "\\*"),
    DIV(false, "/"),
    MOD(false, "%"),
    /* ---------- arithmetic operation end ---------- */
    /* ---------- logical operation begin ---------- */
    NOT(false, "!"),
    AND(false, "&&"),
    OR(false, "\\|\\|"),
    /* ---------- logical operation end ---------- */
    ASSIGN(false, "="),
    SEMICN(false, ";"),
    COMMA(false, ","),
    /* ---------- brackets begin ---------- */
    LPARENT(false, "\\("),
    RPARENT(false, "\\)"),
    LBRACK(false, "\\["),
    RBRACK(false, "]"),
    LBRACE(false, "\\{"),
    RBRACE(false, "}");
    /* ---------- brackets end ---------- */

    private boolean isGreed; // 是否采用精准匹配
    private String patternString; // 匹配字符串
    private Pattern pattern; // 匹配的正则表达式

    TokenType(boolean isGreed, String patternString) {
        this.isGreed = isGreed;
        this.patternString = patternString;
        /* 需要在每个正则表达式前添加^，以保证匹配的是紧接着的字符串 */
        if (this.isGreed) {
            this.pattern = Pattern.compile("^" + this.patternString + "(?![_A-Za-z0-9])");
        } else {
            this.pattern = Pattern.compile("^" + this.patternString);
        }
    }

    public Pattern getPattern() {
        return this.pattern;
    }

    public boolean getIsGreed() {
        return this.isGreed;
    }

    public String getPatternString() {
        return this.patternString;
    }

    @Override
    public String toString() {
        return this.name();
    }
}
