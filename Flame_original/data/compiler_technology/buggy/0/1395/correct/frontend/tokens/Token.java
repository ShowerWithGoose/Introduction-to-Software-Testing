package frontend.tokens;

public class Token {
    private final String content;
    private final int line;
    protected TokenType type;
    public Token(String content, int line) {
        this.content = content;
        this.line = line;
    }

    public Token(String content, int line, TokenType type) {
        this.content = content;
        this.line = line;
        this.type = type;
    }

    public String getContent() {
        return content;
    }

    public int getLine() {
        return line;
    }

    public TokenType getType() {
        return type;
    }

    public static int getBlockComment(String sourceCode, int pos) {
        // return the position of the end of the comment
        for (int i = pos + 2; i < sourceCode.length(); i++)
            if (sourceCode.charAt(i) == '*' && sourceCode.charAt(i + 1) == '/')
                return i + 2;
        return -1;
    }

    public static int getLineComment(String sourceCode, int pos) {
        while (pos < sourceCode.length() && sourceCode.charAt(pos) != '\n') {
            pos++;
        }
        return pos;
    }

    public static int getChar(String sourceCode, int pos) {
        if (sourceCode.charAt(pos + 1) == '\\') {
            return pos + 4;
        } else {
            return pos + 3;
        }
    }

    public static int getString(String sourceCode, int pos) {
        int i = pos + 1;
        while (sourceCode.charAt(i) != '\"') {
            i++;
        }
        return i + 1; // 包含末尾的引号！substring(pos, end)时不包含end！
    }

    @Override
    public String toString() {
        return type + " " + content;
    }
}
