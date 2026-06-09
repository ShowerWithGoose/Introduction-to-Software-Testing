package frontend.Lexer;

public class Token {
    TokenType type;
    String content;
    int lineno;

    // 无参构造方法
    public Token() {}

    // 全参构造方法
    public Token(TokenType type, String content, int lineno) {
        this.type = type;
        this.content = content;
        this.lineno = lineno;
    }


}
