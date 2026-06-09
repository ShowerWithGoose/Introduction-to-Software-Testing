package frontend.terminal;

import frontend.Token;
import frontend.TokenListIterator;
import frontend.TokenType;

/**
 * 解析器: IntConst (整型常量)
 * 对应文法: Number → IntConst
 *
 * 解析整型常量 (INTCON)，确保当前 Token 符合 IntConst 类型。
 */
public class IntConstParser {
    private final TokenListIterator iterator;
    private Token token = null;

    public IntConstParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public IntConst parseIntConst() {
        // 读取下一个 Token
        this.token = this.iterator.readNextToken();
        // 检查 Token 是否为整数常量 (INTCON)
        if (!this.token.getType().equals(TokenType.INTCON)) {
            System.out.println("Error: Expected an integer constant (INTCON), but found: " + token.getContent());
            return null; // 遇到错误时返回 null 或根据需求处理
        }
        // 创建并返回 IntConst 对象
        return new IntConst(this.token);
    }
}
