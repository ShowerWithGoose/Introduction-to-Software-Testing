package frontend.tokens;

public class StringCon extends Token {
    public StringCon(String content, int line) {
        super(content, line);
        type = TokenType.STRCON;
    }

    // 获取该String的末尾
    public static int getString(String sourceCode, int pos) {
        int i = pos + 1;
        while (sourceCode.charAt(i) != '\"') {
            i++;
        }
        return i + 1; // 包含末尾的引号！substring(pos, end)时不包含end！
    }
}
