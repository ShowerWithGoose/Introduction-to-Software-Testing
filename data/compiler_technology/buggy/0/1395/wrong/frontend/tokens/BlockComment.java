package frontend.tokens;

public class BlockComment extends Token {
    // constructor
    public BlockComment(String comment, int line) {
        super(comment, line);
        type = TokenType.BLOCKCOMMENT;
    }

    public static int getBlockComment(String sourceCode, int pos) {
        // return the position of the end of the comment
        for (int i = pos + 2; i < sourceCode.length(); i++)
            if (sourceCode.charAt(i) == '*' && sourceCode.charAt(i + 1) == '/')
                return i + 2;
        return -1;
    }
}
