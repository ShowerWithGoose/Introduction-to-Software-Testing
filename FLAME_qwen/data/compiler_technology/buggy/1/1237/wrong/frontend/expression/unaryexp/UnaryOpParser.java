package frontend.expression.unaryexp;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;

/**
 * 解析器: UnaryOp (单目运算符)
 * 对应文法: UnaryOp → '+' | '−' | '!'
 *
 * 解析过程：
 * 1. 读取下一个 token
 * 2. 判断该 token 是否为 '+'、'-' 或 '!'，如果是，则返回对应的 UnaryOp 对象。
 * 3. 否则抛出非法 token 错误。
 */
public class UnaryOpParser {
    private final TokenListIterator iterator;

    public UnaryOpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public UnaryOp parseUnaryOp() {
        // 读取下一个 token
        Token token = this.iterator.readNextToken();

        // 验证 token 类型是否为 '+'、'-' 或 '!'
        if (token.getType().equals(TokenType.PLUS) ||
                token.getType().equals(TokenType.MINU) ||
                token.getType().equals(TokenType.NOT)) {
            // 构建并返回 UnaryOp 对象
            return new UnaryOp(token);
        } else {
            // 如果 token 类型不匹配，抛出异常
            throw new IllegalArgumentException("Unexpected token for UnaryOp: " + token.getType());
        }
    }
}
