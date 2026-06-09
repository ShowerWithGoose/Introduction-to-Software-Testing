package util;

/**
 * The type Detect char tool.
 *
 * @author
 * @Description： 判断字符
 * @date
 */
public class DetectCharTool {
    /**
     * 判断是否为字母。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isAlpha(char c) {
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }

    /**
     * 判断是否为数字。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isDigit(char c) {
        return (c >= '0' && c <= '9');
    }

    /**
     * 判断是否为字母或下划线。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean is_Alpha(char c) {
        return (isAlpha(c) || (c == '_'));
    }

    /**
     * 判断是否为标识符字符。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isIDENFR(char c) {
        return (is_Alpha(c) || isDigit(c));
    }

    /**
     * 判断是否为单引号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isSingleQuote(char c) {
        return c == '\'';
    }

    /**
     * 判断是否为双引号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isDoubleQuote(char c) {
        return c == '\"';
    }

    /**
     * 判断是否为反斜杠。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isBackslashes(char c) {
        return c == '\\';
    }

    /**
     * 判断是否为小于号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isLss(char c) {
        return c == '<';
    }

    /**
     * 判断是否为大于号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isGre(char c) {
        return c == '>';
    }

    /**
     * 判断是否为等号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isEqual(char c) {
        return c == '=';
    }

    /**
     * 判断是否为感叹号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isExclamation(char c) {
        return c == '!';
    }

    /**
     * 判断是否为与号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isAnd(char c) {
        return c == '&';
    }

    /**
     * 判断是否为或号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isOr(char c) {
        return c == '|';
    }

    /**
     * 判断是否为斜杠。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isDiv(char c) {
        return c == '/';
    }

    /**
     * 判断是否为加号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isPlus(char c) {
        return c == '+';
    }

    /**
     * 判断是否为减号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isMinus(char c) {
        return c == '-';
    }

    /**
     * 判断是否为星号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isMulti(char c) {
        return c == '*';
    }

    /**
     * 判断是否为百分号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isMod(char c) {
        return c == '%';
    }

    /**
     * 判断是否为左括号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isLeftParent(char c) {
        return c == '(';
    }

    /**
     * 判断是否为右括号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isRightParent(char c) {
        return c == ')';
    }

    /**
     * 判断是否为左方括号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isLeftBracket(char c) {
        return c == '[';
    }

    /**
     * 判断是否为右方括号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isRightBracket(char c) {
        return c == ']';
    }

    /**
     * 判断是否为左大括号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isLeftBrace(char c) {
        return c == '{';
    }

    /**
     * 判断是否为右大括号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isRightBrace(char c) {
        return c == '}';
    }

    /**
     * 判断是否为逗号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isComma(char c) {
        return c == ',';
    }

    /**
     * 判断是否为分号。
     *
     * @param c 字符
     * @return 布尔值
     */
    public static boolean isSemi(char c) {
        return c == ';';
    }

}
