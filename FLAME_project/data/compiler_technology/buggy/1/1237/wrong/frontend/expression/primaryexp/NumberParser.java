package frontend.expression.primaryexp;

import frontend.TokenListIterator;
import frontend.terminal.IntConst;
import frontend.terminal.IntConstParser;

/**
 * 解析器: Number (数值常量)
 * 对应文法: Number → IntConst
 *
 * 解析过程：
 * 1. 解析 IntConst（整数常量）。
 */
public class NumberParser {
    private final TokenListIterator iterator;

    public NumberParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Number parseNumber() {
        // 使用 IntConstParser 解析整数常量
        IntConstParser intConstParser = new IntConstParser(this.iterator);
        IntConst intConst = intConstParser.parseIntConst();

        // 构建并返回 Number 对象
        return new Number(intConst);
    }
}
