package frontend.terminal;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;

/**
 * 解析器: StringConst (字符串常量)
 * 对应文法: StringConst → '"' {ASCII} '"'
 *
 * 解析字符串常量 (STRCON)，确保当前 Token 符合 StringConst 类型。
 */
public class StringConstParser {
    private final TokenListIterator iterator;
    private Token token = null;

    public StringConstParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public StringConst parseStringConst() {
        // 读取下一个 Token
        token = this.iterator.readNextToken();
        // 检查 Token 是否为字符串常量 (STRCON)
        if (!token.getType().equals(TokenType.STRCON)) {
            System.out.println("Error: Expected a string constant (STRCON), but found: " + token.getContent());
            return null; // 遇到错误时返回 null 或根据需求处理
        }
        // 返回解析后的 StringConst 对象
        return new StringConst(token);
    }
}
