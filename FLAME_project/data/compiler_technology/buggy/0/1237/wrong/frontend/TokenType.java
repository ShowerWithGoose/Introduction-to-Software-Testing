package frontend;

import java.util.regex.Pattern;

/**
 * 枚举类用于定义编译器的词法单元类型 (TokenType)。
 * 每个词法单元包含两个属性：
 * - 是否进行贪婪匹配 (boolean isGreed)
 * - 正则表达式规则 (Pattern pattern)
 */
public enum TokenType {


    /* ---------- 保留字 ---------- */
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


    /* ---------- 标识符和常量 (Identifiers and Constants) ---------- */
    IDENFR(false, "[_A-Za-z][_A-Za-z0-9]*"),  // 标识符
    INTCON(false, "[0-9]+"),                  // 整数常量
    STRCON(false, "\\\"[^\\\"]*\\\""),        // 字符串常量
    CHRCON(false, "'[^']'"),                  // 字符常量



    /* ---------- 比较运算符 ---------- */

    LEQ(false, "<="),                         // 小于等于号
    GEQ(false, ">="),                         // 大于等于号
    EQL(false, "=="),                         // 等于号
    NEQ(false, "!="),                         // 不等于号
    LSS(false, "<"),                          // 小于号
    GRE(false, ">"),                          // 大于号

    /* ---------- 算术运算符 ---------- */
    PLUS(false, "\\+"),  // 加号
    MINU(false, "-"),    // 减号
    MULT(false, "\\*"),  // 乘号
    DIV(false, "/"),     // 除号
    MOD(false, "%"),     // 取模

    /* ---------- 逻辑运算符 ---------- */
    NOT(false, "!"),     // 逻辑非
    AND(false, "&&"),    // 逻辑与
    OR(false, "\\|\\|"), // 逻辑或

    /* ---------- 赋值和分隔符  ---------- */
    ASSIGN(false, "="),  // 赋值号
    SEMICN(false, ";"),  // 分号
    COMMA(false, ","),   // 逗号

    /* ---------- 括号 ---------- */
    LPARENT(false, "\\("),  // 左小括号
    RPARENT(false, "\\)"),  // 右小括号
    LBRACK(false, "\\["),   // 左中括号
    RBRACK(false, "\\]"),   // 右中括号
    LBRACE(false, "\\{"),   // 左大括号
    RBRACE(false, "\\}");   // 右大括号



    private final boolean isGreed;    // 是否贪婪匹配
    private final String patternString;  // 原始正则表达式字符串
    private final Pattern pattern;    // 编译后的正则表达式

    /**
     * TokenType 枚举的构造函数。
     *
     * @param isGreed 是否贪婪匹配
     * @param patternString 正则表达式字符串
     */
    TokenType(boolean isGreed, String patternString) {
        this.isGreed = isGreed;
        this.patternString = patternString;
        // 若为贪婪匹配，添加非数字和字母结尾的规则，确保优先匹配完整关键字。
        String regexPrefix = "^" + this.patternString;
        if (this.isGreed) {
            this.pattern = Pattern.compile(regexPrefix + "(?![_A-Za-z0-9])");
        } else {
            this.pattern = Pattern.compile(regexPrefix);
        }
    }

    /**
     * 获取正则表达式模式。
     *
     * @return 返回编译后的正则表达式 (Pattern)
     */
    public Pattern getPattern() {
        return this.pattern;
    }

    /**
     * 获取贪婪匹配标识。
     *
     * @return 返回是否进行贪婪匹配 (boolean)
     */
    public boolean isGreed() {
        return this.isGreed;
    }

    /**
     * 获取正则表达式字符串。
     *
     * @return 返回正则表达式字符串 (String)
     */
    public String getPatternString() {
        return this.patternString;
    }

    @Override
    public String toString() {
        return this.name();
    }
}
