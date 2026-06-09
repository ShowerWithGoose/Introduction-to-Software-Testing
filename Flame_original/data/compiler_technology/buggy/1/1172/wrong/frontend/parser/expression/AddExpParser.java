package frontend.parser.expression;

import frontend.lexer.*;

import java.util.LinkedList;

/**
 * 解析加法表达式的解析器类。
 */
public class AddExpParser {
    // Token 列表迭代器
    private TokenListIterator iterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param iterator TokenListIterator 对象
     */
    public AddExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析加法表达式。
     *
     * @return 解析得到的 AddExp 对象
     */
    public AddExp parseAddExp() {
        // 使用 LinkedList 存储乘法表达式和运算符
        LinkedList<MulExp> termList = new LinkedList<>();
        LinkedList<Token> operatorList = new LinkedList<>();

        MulExpParser termParser = new MulExpParser(iterator);
        // 解析第一个乘法表达式
        MulExp firstTerm = termParser.parseMulExp();
        termList.add(firstTerm);

        // 预读取下一个 Token
        Token currentToken = iterator.readNextToken();
        // 循环解析后续的加减法表达式
        while (currentToken != null && (currentToken.getType() == TokenType.PLUS || currentToken.getType() == TokenType.MINU)) {
            // 添加运算符
            operatorList.add(currentToken);
            // 解析下一个乘法表达式
            MulExp nextTerm = termParser.parseMulExp();
            termList.add(nextTerm);
            // 读取下一个 Token
            currentToken = iterator.readNextToken();
        }
        // 回退一个 Token，因为最后读取的 Token 不属于加法表达式
        if (currentToken != null) {
            iterator.unReadTokens(1);
        }

        // 创建并返回 AddExp 对象
        return new AddExp(termList, operatorList);
    }
}
