package frontend.lexer;

import frontend.parser.SyntaxOutput;
import java.util.Objects;

/**
 * 表示词法分析中的一个 Token。
 */
public class Token implements SyntaxOutput {
    private final TokenType type;     // Token 类型
    private final String lexeme;      // 词素
    private final int lineNumber;     // 行号

    // 缓存 toString 结果
    private String toStringCache;

    /**
     * 构造函数，初始化 Token 对象。
     * @param type Token 类型
     * @param lexeme 词素
     * @param lineNumber 行号
     */
    public Token(TokenType type, String lexeme, int lineNumber) {
        this.type = Objects.requireNonNull(type, "TokenType cannot be null");
        this.lexeme = Objects.requireNonNull(lexeme, "Lexeme cannot be null");
        this.lineNumber = lineNumber;
    }

    /**
     * 获取 Token 的类型。
     * @return TokenType
     */
    public TokenType getType() {
        return this.type;
    }

    /**
     * 获取 Token 所在的行号。
     * @return 行号
     */
    public int getLine() {
        return this.lineNumber;
    }

    /**
     * 重写 toString 方法，返回 Token 的字符串表示。
     * @return 字符串表示
     */
    @Override
    public String toString() {
        if (toStringCache == null) {
            StringBuilder sb = new StringBuilder();
            sb.append(type.toString()).append(" ").append(lexeme);
            toStringCache = sb.toString();
        }
        return toStringCache;
    }

    /**
     * 实现 SyntaxOutput 接口的方法，返回语法字符串。
     * @return 语法字符串
     */
    @Override
    public String toSyntaxString() {
        return toString() + System.lineSeparator();
    }

    // 重写 equals 方法，方便比较 Token 对象
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj instanceof Token) {
            Token other = (Token) obj;
            return type == other.type && lexeme.equals(other.lexeme) && lineNumber == other.lineNumber;
        }
        return false;
    }

    // 重写 hashCode 方法，配合 equals 方法
    @Override
    public int hashCode() {
        return Objects.hash(type, lexeme, lineNumber);
    }
}
