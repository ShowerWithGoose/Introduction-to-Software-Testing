package frontend.expression;

import frontend.TokenListIterator;
import frontend.expression.multiexp.LOrExp;
import frontend.expression.multiexp.LOrExpParser;

/**
 * 解析器: Cond (条件表达式)
 * 对应文法: Cond → LOrExp
 *
 * 解析条件表达式，条件表达式是一个逻辑或表达式 (LOrExp)。
 */
public class CondParser {
    private final TokenListIterator iterator;

    public CondParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Cond parseCond() {
        // 调用 LOrExpParser 解析逻辑或表达式
        LOrExpParser lorExpParser = new LOrExpParser(this.iterator);
        LOrExp lorExp = lorExpParser.parseLOrExp();
        // 将逻辑或表达式封装在 Cond 对象中
        return new Cond(lorExp);
    }
}
