package Lexical;

/**
 * @author
 * @Description: 词法分析检查工具
 * @date 2024/9/22 13:59
 */
public class CheckTools {
    public static boolean isAlpha(int ch) {
        return (ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A');
    }

    public static boolean isDigit(int ch) {
        return (ch <= '9' && ch >= '0');
    }

    public static boolean isLegalAscii(int ch) {
        return (ch >= 32 && ch <= 126 && ch != '"' && ch != '\\' && ch != '\'');
    }

    public static boolean isTranversableAscii(int ch) {
        return ch == 'a' || ch == 'b' || ch == 't'
                || ch == 'f' || ch == 'n' || ch == 'v'
                || ch == '"' || ch == '\\' || ch == '\''
                || ch == '0';
    }
}
