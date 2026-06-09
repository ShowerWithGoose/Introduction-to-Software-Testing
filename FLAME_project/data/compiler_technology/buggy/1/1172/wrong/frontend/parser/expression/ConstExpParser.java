package frontend.parser.expression;

import frontend.lexer.*;

/**
 * 解析常量表达式的解析器类。
 */
public class ConstExpParser {
    // Token 列表迭代器
    private TokenListIterator iterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param iterator TokenListIterator 对象
     */
    public ConstExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析常量表达式。
     *
     * @return 解析得到的 ConstExp 对象
     */
    public ConstExp parseConstExp() {
        // 创建 AddExpParser 对象
        AddExpParser expressionParser = new AddExpParser(iterator);
        // 解析加法表达式
        AddExp expression = expressionParser.parseAddExp();
        // 创建并返回 ConstExp 对象
        return new ConstExp(expression);
    }
}
