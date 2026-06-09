package mainSys.Tools;

import static java.lang.Character.*;
import static mainSys.StaticValues.*;

public class ParseTool {
    public static boolean isEnd() {
        return pos >= sourceCode.length();
    }

    public static void movePos(int i) {
        pos += i;
    }
    public static void movePos() {
        pos++;
    }

    public static char getChar() {
        if (pos >= sourceCode.length()) return '\0';
        return sourceCode.charAt(pos);
    }

    public static char moveAndGetChar() {
        pos++;
        return getChar();
    }

    public static char getCharAndMove() {
        char c = getChar();
        pos++;
        return c;
    }

    public static boolean compareWordAndMovePos(String word) {
        int i = 0;
        while (i < word.length()) {
            if (pos + i >= sourceCode.length()) return false;
            if (sourceCode.charAt(pos + i) != word.charAt(i)) return false;
            i++;
        }
        i = word.length();
        if (pos + i < sourceCode.length()
                && isIdentChar(sourceCode.charAt(pos + i)))
            return false;
        pos += i;
        return true;
    }

    public static boolean isIdentChar(char c) {
        return isLetterOrDigit(c) || c == '_';
    }
}
