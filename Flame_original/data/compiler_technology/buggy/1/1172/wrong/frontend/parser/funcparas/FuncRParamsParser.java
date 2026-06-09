package frontend.parser.funcparas;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.AddExp;
import frontend.parser.expression.AddExpParser;

import java.util.LinkedList;

/**
 * 解析函数实参列表的解析器类。
 */
public class FuncRParamsParser {
    // Token 列表迭代器
    private TokenListIterator tokenIterator;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenIterator TokenListIterator 对象
     */
    public FuncRParamsParser(TokenListIterator tokenIterator) {
        this.tokenIterator = tokenIterator;
    }

    /**
     * 解析函数实参列表。
     *
     * @return 解析得到的 FuncRParams 对象
     */
    public FuncRParams parseFuncRParams() {
        // 使用 LinkedList 存储表达式和逗号
        LinkedList<AddExp> argExpressionList = new LinkedList<>();
        LinkedList<Token> delimiterTokens = new LinkedList<>();

        AddExpParser expressionParser = new AddExpParser(tokenIterator);

        // 解析第一个表达式
        AddExp firstExpression = expressionParser.parseAddExp();
        argExpressionList.add(firstExpression);

        // 循环解析后续表达式
        while (true) {
            Token nextToken = tokenIterator.readNextToken();
            if (nextToken.getType() == TokenType.COMMA) {
                // 添加逗号 Token
                delimiterTokens.add(nextToken);
                // 解析下一个表达式
                AddExp nextExpression = expressionParser.parseAddExp();
                argExpressionList.add(nextExpression);
            } else {
                // 回退一个 Token，因为不是逗号
                tokenIterator.unReadTokens(1);
                break;
            }
        }

        // 冗余代码：如果实参数量超过预期，输出警告（假设预期参数数量为 10）
        if (argExpressionList.size() > 10) {
            System.err.println("Warning: Too many arguments in function call.");
        }

        // 创建并返回 FuncRParams 对象
        return new FuncRParams(argExpressionList, delimiterTokens);
    }
}
