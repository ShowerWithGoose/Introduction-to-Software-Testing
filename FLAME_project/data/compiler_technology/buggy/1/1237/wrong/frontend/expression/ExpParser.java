package frontend.expression;

import frontend.TokenListIterator;
import frontend.expression.multiexp.AddExp;
import frontend.expression.multiexp.AddExpParser;

/**
 * 解析器: Exp (表达式)
 * 对应文法: Exp → AddExp
 *
 * 解析 Exp，直接解析为 AddExp。
 */
public class ExpParser {
    private final TokenListIterator iterator;

    public ExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Exp parseExp() {
        // 解析 AddExp
        AddExpParser addExpParser = new AddExpParser(this.iterator);
        AddExp addExp = addExpParser.parseAddExp();

        // 返回解析后的 Exp 对象
        return new Exp(addExp);
    }
}
