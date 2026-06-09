package frontend;

import java.util.ArrayList;
import java.util.List;

/**
 * 表示词法单元 (Token) 的类，存储类型、行号和内容。
 */
public class Token {
    private final TokenType type;   // 词法单元类型
    private final int lineIndex;      // 词法单元所在行号
    private final String content;   // 词法单元内容

    public Token(TokenType type, int lineIndex, String content) {
        if (type == null || content == null) {
            throw new IllegalArgumentException("Token type and content cannot be null");
        }
        this.type = type;
        this.lineIndex = lineIndex;
        this.content = content;
    }

    public TokenType getType() {
        return type;
    }

    public int getLineIndex() {
        return lineIndex;
    }

    public String getContent() {
        return content;
    }

    public String syntaxOutput() {
        return this.getType() + " " + this.getContent() + "\n";
    }

    @Override
    public String toString() {
        return String.format("%s %s", type, content);
    }
}







