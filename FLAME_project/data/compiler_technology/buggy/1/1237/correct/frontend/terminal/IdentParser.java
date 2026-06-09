package frontend.terminal;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;

/**
 * 解析器: Ident (标识符)
 * 对应文法: Ident → identifier
 *
 * 解析标识符 (IDENFR)，确保当前 Token 符合 identifier 类型。
 */
public class IdentParser {
    private final TokenListIterator iterator;
    private Token token; // ident

    public IdentParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Ident parseIdent() {
        // 读取下一个 Token
        token = this.iterator.readNextToken();
        // 检查 Token 是否为标识符 (IDENFR)
        if (!token.getType().equals(TokenType.IDENFR)) {
            System.out.println("Error: Expected an identifier (IDENFR), but found: " + token.getContent());
            return null; // 遇到错误时返回 null 或根据需求处理
        }
        // 创建并返回 Ident 对象
        return new Ident(token);
    }
}
