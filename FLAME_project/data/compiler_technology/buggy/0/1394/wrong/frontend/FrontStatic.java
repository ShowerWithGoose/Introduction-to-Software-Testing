package frontend;

public class FrontStatic {
    public static boolean isSpecialChar(char c) {
        String regex = "!&|+-*/%<=>;,()[]{}";
        return regex.contains(String.valueOf(c));
    }
    public static boolean isDigit(String word) {
        String regex = "[0-9]+";
        return word.matches(regex);
    }
    public static boolean isChar(String word) {
        String regex = "'.{1,2}'";
        return word.matches(regex);
    }
    public static boolean isString(String word) {
        String regex = "\"[^\"]*\"";
        return word.matches(regex);
    }
}
