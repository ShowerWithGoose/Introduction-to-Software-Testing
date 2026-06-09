package frontend.terminal;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;
import frontend.expression.primaryexp.PrimaryExpEle;

/**
 * 解析器: CharConst (字符常量)
 * 对应文法: Character → CharConst
 *
 * 解析字符常量 (CHRCON)，确保当前 Token 符合 CharConst 类型。
 */
public class CharConstParser implements PrimaryExpEle {
    private final TokenListIterator iterator;
    private Token token = null;

    public CharConstParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public CharConst parseCharConst() {
        // 读取下一个 Token
        token = this.iterator.readNextToken();
        // 检查 Token 是否为字符常量 (CHRCON)
        if (!token.getType().equals(TokenType.CHRCON)) {
            System.out.println("Error: Expected a character constant (CHRCON), but found: " + token.getContent());
            return null; // 遇到错误时返回 null 或根据需求处理
        }
        // 返回解析后的 CharConst 对象
        return new CharConst(token);
    }

    @Override
    public String syntaxOutput() {
        return token.syntaxOutput();
    }
}
