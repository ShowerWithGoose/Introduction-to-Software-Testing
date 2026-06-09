package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;

/**
 * UnaryOp 单目运算符类
 * <UnaryOp> -> '+' | '-' | '!'
 */
public class UnaryOp implements SyntaxNode {
    /**
     * 属性：
     * name 该语法类名
     * token 符号
     */
    private final String name = "<UnaryOp>";
    private Token token;

    public UnaryOp(Token token) {
        this.token = token;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
