package frontend.tokens;

public class LineComment extends Token {
    // constructor
    public LineComment(String comment, int line) {
        super(comment, line);
        type = TokenType.LINECOMMENT;
    }

    public static int getLineComment(String sourceCode, int pos) {
        while (pos < sourceCode.length() && sourceCode.charAt(pos) != '\n') {
            pos++;
        }
        return pos;
    }

}
