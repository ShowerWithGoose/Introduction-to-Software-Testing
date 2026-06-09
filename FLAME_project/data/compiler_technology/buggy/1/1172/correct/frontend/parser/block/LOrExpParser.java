package frontend.parser.block;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.LinkedList;

/**
 * 解析逻辑或表达式的解析器类。
 */
public class LOrExpParser {
    // Token 列表迭代器
    private TokenListIterator tokenStream;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenStream TokenListIterator 对象
     */
    public LOrExpParser(TokenListIterator tokenStream) {
        this.tokenStream = tokenStream;
    }

    /**
     * 解析逻辑或表达式。
     *
     * @return 解析得到的 LOrExp 对象
     */
    public LOrExp parseLOrExp() {
        // 初始化逻辑与表达式解析器
        LAndExpParser andExpParser = new LAndExpParser(tokenStream);
        // 存储解析结果的列表
        LinkedList<LAndExp> andExpList = new LinkedList<>();
        LinkedList<Token> orOperatorList = new LinkedList<>();

        // 解析第一个逻辑与表达式
        LAndExp firstAndExp = andExpParser.parseLAndExp();
        andExpList.add(firstAndExp);

        // 循环解析后续的逻辑或操作符和逻辑与表达式
        while (true) {
            Token operatorToken = tokenStream.readNextToken();
            if (operatorToken.getType() == TokenType.OR) {
                // 添加逻辑或操作符
                orOperatorList.add(operatorToken);
                // 解析下一个逻辑与表达式
                LAndExp nextAndExp = andExpParser.parseLAndExp();
                andExpList.add(nextAndExp);
            } else {
                // 非逻辑或操作符，回退一个 Token，结束循环
                tokenStream.unReadTokens(1);
                break;
            }
        }

        // 创建并返回 LOrExp 对象
        return new LOrExp(andExpList, orOperatorList);
    }
}
