package frontend.parser.expression;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.LinkedList;

/**
 * 解析乘法表达式的解析器类。
 */
public class MulExpParser {
    // Token 列表迭代器
    private TokenListIterator iterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param iterator TokenListIterator 对象
     */
    public MulExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    /**
     * 解析乘法表达式。
     *
     * @return 解析得到的 MulExp 对象
     */
    public MulExp parseMulExp() {
        // 使用 LinkedList 存储一元表达式和运算符
        LinkedList<UnaryExp> factorList = new LinkedList<>();
        LinkedList<Token> operatorList = new LinkedList<>();

        UnaryExpParser factorParser = new UnaryExpParser(iterator);
        // 解析第一个一元表达式
        UnaryExp firstFactor = factorParser.parseUnaryExp();
        factorList.add(firstFactor);

        // 预读取下一个 Token
        Token currentToken = iterator.readNextToken();
        // 循环解析后续的乘法表达式
        while (currentToken != null && (currentToken.getType() == TokenType.MULT ||
                currentToken.getType() == TokenType.DIV ||
                currentToken.getType() == TokenType.MOD)) {
            // 添加运算符
            operatorList.add(currentToken);
            // 解析下一个一元表达式
            UnaryExp nextFactor = factorParser.parseUnaryExp();
            factorList.add(nextFactor);
            // 读取下一个 Token
            currentToken = iterator.readNextToken();
        }
        // 回退一个 Token，因为最后读取的 Token 不属于乘法表达式
        if (currentToken != null) {
            iterator.unReadTokens(1);
        }

        // 创建并返回 MulExp 对象
        return new MulExp(factorList, operatorList);
    }
}
