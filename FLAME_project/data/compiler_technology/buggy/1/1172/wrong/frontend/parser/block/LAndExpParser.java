package frontend.parser.block;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.LinkedList;

/**
 * 解析逻辑与表达式的解析器类。
 */
public class LAndExpParser {
    // Token 列表迭代器
    private TokenListIterator tokenStream;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenStream TokenListIterator 对象
     */
    public LAndExpParser(TokenListIterator tokenStream) {
        this.tokenStream = tokenStream;
    }

    /**
     * 解析逻辑与表达式。
     *
     * @return 解析得到的 LAndExp 对象
     */
    public LAndExp parseLAndExp() {
        // 初始化等价表达式解析器
        EqExpParser eqExpParser = new EqExpParser(tokenStream);
        // 初始化等价表达式列表和逻辑与操作符列表
        LinkedList<EqExp> eqExpList = new LinkedList<>();
        LinkedList<Token> andOperatorList = new LinkedList<>();

        // 解析第一个等价表达式
        EqExp firstEqExp = eqExpParser.parseEqExp();
        eqExpList.add(firstEqExp);

        // 循环解析后续的逻辑与操作符和等价表达式
        while (true) {
            Token operatorToken = tokenStream.readNextToken();
            if (operatorToken.getType() == TokenType.AND) {
                // 添加逻辑与操作符
                andOperatorList.add(operatorToken);
                // 解析下一个等价表达式
                EqExp nextEqExp = eqExpParser.parseEqExp();
                eqExpList.add(nextEqExp);
            } else {
                // 非逻辑与操作符，回退一个 Token，结束循环
                tokenStream.unReadTokens(1);
                break;
            }
        }

        // 创建并返回 LAndExp 对象
        return new LAndExp(eqExpList, andOperatorList);
    }
}
