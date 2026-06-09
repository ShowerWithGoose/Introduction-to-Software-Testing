package frontend.tokens;

public class Ident extends Token
{
    // 正则表达式
    public static final String regex = "[a-zA-Z_][a-zA-Z0-9_]*";
    // constructor
    public Ident(String content, int line) {
        super(content, line);
        type = TokenType.IDENFR;
    }
}

