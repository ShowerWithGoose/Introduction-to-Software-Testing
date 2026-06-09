package frontend;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class FrontStatic {
    public static Set<String> keyword = new HashSet<>(
            Set.of("int", "char", "void", "const", "return", "if", "else",
                    "for", "break", "continue", "main","getint","getchar","printf")
    );

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
    public static boolean isIdent(String word) {
        if(keyword.contains(word)){
            return false;
        }
        String regex = "[a-zA-Z_][a-zA-Z0-9_]*";
        return word.matches(regex);
    }
}
