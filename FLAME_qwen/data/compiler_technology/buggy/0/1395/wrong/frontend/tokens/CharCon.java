package frontend.tokens;

public class CharCon extends Token {
    public CharCon(String content, int line) {
        super(content, line);
        type = TokenType.CHRCON;
    }

    public static int getChar(String sourceCode, int pos) {
        if (sourceCode.charAt(pos + 1) == '\\') {
            return pos + 4;
        } else {
            return pos + 3;
        }
    }
}
