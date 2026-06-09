package frontend.expression;

import frontend.TokenListIterator;
import frontend.expression.multiexp.AddExp;
import frontend.expression.multiexp.AddExpParser;

/**
 * 解析器: ConstExp (常量表达式)
 * 对应文法: ConstExp → AddExp
 *
 * 解析过程：
 * 1. 调用 AddExpParser 解析 AddExp。
 * 2. 将 AddExp 封装为 ConstExp 对象并返回。
 */
public class ConstExpParser {
    private final TokenListIterator iterator;

    public ConstExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public ConstExp parseConstExp() {
        // 使用 AddExpParser 来解析 AddExp
        AddExpParser addExpParser = new AddExpParser(this.iterator);
        AddExp addExp = addExpParser.parseAddExp();

        // 构建并返回 ConstExp 对象
        return new ConstExp(addExp);
    }
}
