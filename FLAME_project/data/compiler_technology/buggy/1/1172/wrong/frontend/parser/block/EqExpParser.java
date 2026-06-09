package frontend.parser.block;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.LinkedList;

/**
 * 解析等价表达式的解析器类。
 */
public class EqExpParser {
    // Token 列表的迭代器
    private TokenListIterator tokenStream;

    /**
     * 构造函数，初始化解析器。
     *
     * @param tokenStream TokenListIterator 对象
     */
    public EqExpParser(TokenListIterator tokenStream) {
        this.tokenStream = tokenStream;
    }

    /**
     * 解析等价表达式。
     *
     * @return 解析得到的 EqExp 对象
     */
    public EqExp parseEqExp() {
        // 初始化关系表达式解析器
        RelExpParser relExpParser = new RelExpParser(tokenStream);
        // 初始化关系表达式列表和等价操作符列表
        LinkedList<RelExp> relExpList = new LinkedList<>();
        LinkedList<Token> eqOperatorList = new LinkedList<>();

        // 解析第一个关系表达式
        RelExp firstRelExp = relExpParser.parseRelExp();
        relExpList.add(firstRelExp);

        // 循环解析后续的等价操作符和关系表达式
        while (true) {
            Token operatorToken = tokenStream.readNextToken();
            if (operatorToken.getType() == TokenType.EQL || operatorToken.getType() == TokenType.NEQ) {
                // 添加等价操作符
                eqOperatorList.add(operatorToken);
                // 解析下一个关系表达式
                RelExp nextRelExp = relExpParser.parseRelExp();
                relExpList.add(nextRelExp);
            } else {
                // 非等价操作符，回退一个 Token，结束循环
                tokenStream.unReadTokens(1);
                break;
            }
        }

        // 创建并返回 EqExp 对象
        return new EqExp(relExpList, eqOperatorList);
    }
}
